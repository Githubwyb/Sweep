/*
 * main.c
 *
 *  Created on: 2018Äê5ÔÂ2ÈÕ
 *      Author: Liang
 */
#include "altera_avalon_pio_regs.h"
#include "system.h"

#include ".\flash\flash.h"
#include ".\ad\ad.h"
#include ".\Uart\uart.h"
#include ".\Uart\sopc.h"
#include ".\dds\ad9833.h"
#define COUNTER_BASE PIO_INPUT_BASE
#define RST_N_BASE PIO_RST_BASE
#define START_BASE PIO_START_BASE

#include <stdio.h>

int main()
{
    unsigned int add = 0x3;
    unsigned char buffer[8] = {0};
    W25q16_Erasure();
    printf("flash test\r\n");
    printf("before read %s\t",buffer);
    W25Q16_Read(add,buffer,8);
    printf("after read %s\t",buffer);
    //printf("%s\n",buffer);
    buffer[0] = 'a';
	buffer[1] = 'b';
	buffer[2] = 'c';
	buffer[3] = 'd';
	buffer[4] = 'e';
	buffer[5] = 'f';
	buffer[6] = 'g';
	buffer[7] = 'h';
//	buffer[8] = 'i';
//	buffer[9] = 'j';
//	buffer[10] = 'k';
//	buffer[11] = 'l';
//	buffer[12] = 'm';
//	buffer[13] = 'n';
//	buffer[14] = 'o';
//	buffer[15] = 'p';
//	buffer[16] = 'q';
//	buffer[17] = 'r';
//	buffer[18] = 's';
//	buffer[19] = 't';
//	buffer[20] = 'u';
//	buffer[21] = 'v';
//	buffer[22] = 'w';
//	buffer[23] = 'x';
//	buffer[24] = 'y';
//	buffer[25] = 'z';
//	buffer[26] = '0';
//	buffer[27] = '1';
//	buffer[28] = '2';
//	buffer[29] = '3';
//	buffer[30] = '4';
//	buffer[31] = '5';
	W25q16_Erasure();
    W25Q16_Write(add,buffer,8);
    buffer[5]='!';
    W25Q16_Read(add,buffer,8);
    printf("after write %s\r\n",buffer);
    return 0;
}

//int main()
//{
//	printf("Hello from Nios II!\n");
//	int j=0;
//	int i;
//	uart.init();
//	double fre ;
//	i = 200;
//	fre = 100000000/((i) * 32);
//	AD9833_WaveSeting(fre,0,SIN_WAVE,0);
//	while(1)
//	{
//		IOWR_ALTERA_AVALON_PIO_DATA(COUNTER_BASE,(i));
//		IOWR_ALTERA_AVALON_PIO_DATA(RST_N_BASE,0);
//		for(j =0 ;j < 100;j ++);
//		IOWR_ALTERA_AVALON_PIO_DATA(RST_N_BASE,1);
//		IOWR_ALTERA_AVALON_PIO_DATA(START_BASE,1);
//		while(uart.receive_flag != 1);
////		printf("i=%d\n",i);
//		for(j=0; j < 64; j++)
//		{
//			printf("%x  ",uart.receive_buffer[j]);
//		}
//		IOWR_ALTERA_AVALON_PIO_DATA(START_BASE,0);
//
//		IOWR_ALTERA_AVALON_PIO_DATA(RST_N_BASE,0);
//		uart.receive_flag = 0;
//		printf("\r\n\r\n");
//	}
//	for(i=1;i<10;i++)
//	{
////	i = 20;
//	fre = 50000000/((i*20) * 32);
//	AD9833_WaveSeting(fre,0,SIN_WAVE,0);
//
//	IOWR_ALTERA_AVALON_PIO_DATA(COUNTER_BASE,(i*20));
//	IOWR_ALTERA_AVALON_PIO_DATA(RST_N_BASE,0);
//
//	for(j =0 ;j < 100;j ++);
//	IOWR_ALTERA_AVALON_PIO_DATA(RST_N_BASE,1);
//	IOWR_ALTERA_AVALON_PIO_DATA(START_BASE,1);
//	while(uart.receive_flag != 1);
//	printf("i=%d\n",i);
//	for(j=0; j < 64; j++)
//	{
//		printf("%x  ",uart.receive_buffer[j]);
//	}
//	IOWR_ALTERA_AVALON_PIO_DATA(START_BASE,0);
//
//	IOWR_ALTERA_AVALON_PIO_DATA(RST_N_BASE,0);
//	uart.receive_flag = 0;
//	printf("\n");
//	}
//	return 0;
//}
