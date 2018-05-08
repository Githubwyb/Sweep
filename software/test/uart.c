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
#include "ad.h"
#include "log.h"

static int uart_send_byte(unsigned char data);
static void uart_send_string(unsigned int len, unsigned char *str);
static int uart_init(void);
static int uart_input_init(void);
static int uart_output_init(void);
static void uart_ISR(void *context);
static void uart_input_ISR(void *context);
static void uart_output_ISR(void *context);
static int set_baudrate(unsigned int baudrate);
static int set_baudrate_input(unsigned int baudrate);
static int set_baudrate_output(unsigned int baudrate);

UART_T uart={
		.receive_flag=0,
		.receive_count=0,
		.send_byte=uart_send_byte,
		.send_string=uart_send_string,
		.init=uart_init,
		.baudrate=set_baudrate
};

UART_T uart_input={
		.receive_flag=0,
		.receive_count=0,
		.send_byte=uart_send_byte,
		.send_string=uart_send_string,
		.init=uart_input_init,
		.baudrate=set_baudrate_input
};

UART_T uart_output={
		.receive_flag=0,
		.receive_count=0,
		.send_byte=uart_send_byte,
		.send_string=uart_send_string,
		.init=uart_output_init,
		.baudrate=set_baudrate_output
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
	set_baudrate(57600);
	UART->CONTROL.BITS.IRRDY=1;
	UART->STATUS.WORD=0;
	alt_ic_isr_register(UART_IRQ_INTERRUPT_CONTROLLER_ID,UART_IRQ,uart_ISR,NULL,0x0);
	return 0;
}

int uart_input_init(void) {
	set_baudrate_input(115200);
	UART_INPUT->CONTROL.BITS.IRRDY=1;
	UART_INPUT->STATUS.WORD=0;
	alt_ic_isr_register(UART_INPUT_IRQ_INTERRUPT_CONTROLLER_ID,UART_INPUT_IRQ,uart_input_ISR,NULL,0x0);
	return 0;
}

int uart_output_init(void) {
	set_baudrate_output(115200);
	UART_OUTPUT->CONTROL.BITS.IRRDY=1;
	UART_OUTPUT->STATUS.WORD=0;
	alt_ic_isr_register(UART_OUTPUT_IRQ_INTERRUPT_CONTROLLER_ID,UART_OUTPUT_IRQ,uart_output_ISR,NULL,0x0);
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
//	LOG_DEBUG("uart interrupt");
	while(!(UART->STATUS.BITS.RRDY));
	uart.receive_buffer[uart.receive_count++] = UART->RXDATA.BITS.RECEIVE_DATA;
	uart.receive_flag = 1;
//	if(getStartMessge(uart.receive_buffer)){
//		LOG_DEBUG("get start message!");
//		parseMessage(uart.receive_buffer, &ReceiveMessage);
////		memcpy(uart.receive_buffer,0,uart.receive_count);
//		FInfo.CurFre = (double)ReceiveMessage.startFre;
//		FInfo.endTest = 0;
//		//default start fre is 10hz
//		FInfo.log = 1;
//		uart.receive_buffer[uart.receive_count]='\0';
//		uart.receive_count=0;
//		uart.receive_flag=1;
//	}
}

unsigned char inputData[65];

static void uart_input_ISR(void *context) {
	//等待状态寄存器RRDY置1，当RRDY为1时表示接收的数据已经传输到RXDATA中
//	LOG_DEBUG("uart_input interrupt");
	while(!(UART_INPUT->STATUS.BITS.RRDY));
	uart_input.receive_buffer[uart_input.receive_count++] = UART_INPUT->RXDATA.BITS.RECEIVE_DATA;
	if(uart_input.receive_count == 64){
		uart_input.receive_buffer[uart_input.receive_count]='\0';
		memcpy(inputData, uart_input.receive_buffer, 64);
//		LOG_DEBUG("uart input data:");
		log_hex(inputData, 64);
		uart_input.receive_count=0;
		uart_input.receive_flag=1;
	}
}

unsigned char outputData[65];

static void uart_output_ISR(void *context) {
//	LOG_DEBUG("uart_output interrupt");
	while(!(UART_OUTPUT->STATUS.BITS.RRDY));
	uart_output.receive_buffer[uart_output.receive_count++] = UART_OUTPUT->RXDATA.BITS.RECEIVE_DATA;
	if(uart_output.receive_count == 64){
		uart_output.receive_buffer[uart_output.receive_count]='\0';
		memcpy(outputData, uart_output.receive_buffer, 64);
//		LOG_DEBUG("uart output data:");
//		log_hex(outputData, 64);
		uart_output.receive_count=0;
		uart_output.receive_flag=1;
	}
}

int set_baudrate(unsigned int baudrate)
{
	UART->DIVISOR.WORD=(unsigned int)(ALT_CPU_FREQ/baudrate+0.5);
	return 0;
}

int set_baudrate_input(unsigned int baudrate) {
	UART_INPUT->DIVISOR.WORD=(unsigned int)(ALT_CPU_FREQ/baudrate+0.5);
	return 0;
}

int set_baudrate_output(unsigned int baudrate) {
	UART_OUTPUT->DIVISOR.WORD=(unsigned int)(ALT_CPU_FREQ/baudrate+0.5);
	return 0;
}

