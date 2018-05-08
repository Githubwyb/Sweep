/*
 * uart.c
 *
 *  Created on: 2018-2-27
 *      Author: Dell
 */
#include"sys/alt_irq.h"
#include <stdlib.h>
#include <stdio.h>
#include "uart.h"
#include "sopc.h"

static int uart_send_byte(unsigned char data);
static void uart_send_string(unsigned int len, unsigned char *str);
static int uart_init(void);
static void uart_ISR(void *context);
static int set_baudrate(unsigned int baudrate);

UART_T uart={
		.receive_flag=0,
		.receive_count=0,
		.send_byte=uart_send_byte,
		.send_string=uart_send_string,
		.init=uart_init,
		.baudrate=set_baudrate
};

/*
 *  * === FUNCTION ======================================================= *
 *  * Name: uart_send_byte
 *  * Description: 发送一个Byte
 *  * ======================================================================
 *  */

int uart_send_byte(unsigned char data)
{
	UART->TXDATA.BITS.TRANSMIT_DATA = data;
	while(!UART->STATUS.BITS.TRDY);
	return 0;
}


/*
 * * === FUNCTION ======================================================= *
 * Name: uart_send_string *
 * Description: 串口发送函数 *
 * ======================================================================
 * */

void uart_send_string(unsigned int len, unsigned char *str)
{
	while(len--)
	{
		uart_send_byte(*str++);
	}
}


/*
 * === FUNCTION =======================================================
 * Name: uart_init *
 * Description: 串口初始化 *
 * ======================================================================
 */

int uart_init(void)
{
	//将波特率设置为115200
	set_baudrate(115200);
	//将控制寄存器IRRDY置1，在接收准备好后使能中断
	UART->CONTROL.BITS.IRRDY=1;
	//将状态寄存器全部清零
	UART->STATUS.WORD=0;
	//为UART注册中断
	alt_ic_isr_register(UART_IRQ_INTERRUPT_CONTROLLER_ID,UART_IRQ,uart_ISR,NULL,0x0);
	return 0;
}


/*
 * * === FUNCTION ======================================================= *
 * Name: uart_ISR *
 * Description: 串口中断服务函数 *
 * ======================================================================
 * */

static void uart_ISR(void *context)
{
	//等待状态寄存器RRDY置1，当RRDY为1时表示接收的数据已经传输到RXDATA中
	while(!(UART->STATUS.BITS.RRDY));
	uart.receive_buffer[uart.receive_count++] = UART->RXDATA.BITS.RECEIVE_DATA;
	if(uart.receive_count == 64){
		uart.receive_buffer[uart.receive_count]='\0';
		uart.receive_count=0;
		uart.receive_flag=1;
	}
}

int set_baudrate(unsigned int baudrate)
{
	UART->DIVISOR.WORD=(unsigned int)(ALT_CPU_FREQ/baudrate+0.5);
	return 0;
}
