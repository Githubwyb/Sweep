/*
 * main.c
 *
 *  Created on: 2018Äê4ÔÂ9ÈÕ
 *      Author: Liang
 */

#include "altera_avalon_pio_regs.h"
#include "system.h"

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
	printf("Hello from Nios II!\n");
	int j=0;
	int i;
	uart.init();
	double fre ;
//	for(i=1;i<10;i++)
//	{
	i = 20;
	fre = 50000000/((i*20) * 32);
	AD9833_WaveSeting(fre,0,SIN_WAVE,0);

	IOWR_ALTERA_AVALON_PIO_DATA(COUNTER_BASE,(i*20));
	IOWR_ALTERA_AVALON_PIO_DATA(RST_N_BASE,0);

	for(j =0 ;j < 100;j ++);
	IOWR_ALTERA_AVALON_PIO_DATA(RST_N_BASE,1);
	IOWR_ALTERA_AVALON_PIO_DATA(START_BASE,1);
	while(uart.receive_flag != 1);
	printf("i=%d\n",i);
	for(j=0; j < 64; j++)
	{
		printf("%x  ",uart.receive_buffer[j]);
	}
	IOWR_ALTERA_AVALON_PIO_DATA(START_BASE,0);

	IOWR_ALTERA_AVALON_PIO_DATA(RST_N_BASE,0);
	uart.receive_flag = 0;
	printf("\n");
//	}
	return 0;
}
