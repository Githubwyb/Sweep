/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#include "altera_avalon_pio_regs.h"
#include "sys/alt_irq.h"

#include "system.h"
#include "ad.h"
#include "uart.h"
#include "sopc.h"
#include "ad9833.h"
#include "fft.h"
#include "message.h"
#include "freinfo.h"
#include "log.h"

#define SIZE 32

float input[SIZE] = {0};
float output[SIZE] = {0};

void delay();

FreInfo FInfo = {0,0,0,0};
TestMessage ReceiveMessage = {0,0,0,0,0};
OutputMessage Result = {0};

int getBeginMessge()
{
//	return 0;
//	return 1;
	return ReceiveMessage.getMessege;
}

void setDDSFre()
{
	AD9833_WaveSeting(FInfo.CurFre, 0, SIN_WAVE, 0);
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_INPUT_BASE, FInfo.divideFre);
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_OUTPUT_BASE, FInfo.divideFre);

	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RST_BASE,0);
	delay();
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RST_BASE,1);
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_START_BASE,1);

	if (FInfo.divideFre <= 100000 && FInfo.divideFre > 10000) {
		FInfo.divideFre = FInfo.divideFre - 1000;
	}
	else if (FInfo.divideFre <= 10000 && FInfo.divideFre > 1000) {
		FInfo.divideFre = FInfo.divideFre - 100;
	}
	else if (FInfo.divideFre <= 1000 && FInfo.divideFre > 100) {
		FInfo.divideFre = FInfo.divideFre - 10;
	}
	else if (FInfo.divideFre <= 100 && FInfo.divideFre > 10) {
		FInfo.divideFre = FInfo.divideFre - 1;
	}
	else if (FInfo.divideFre <= 10 && FInfo.divideFre > 1) {
		FInfo.divideFre = FInfo.divideFre - 1;
	}

	FInfo.CurFre = 1562500 / (float)FInfo.divideFre;

//	LOG_DEBUG("next fre %d", (int)(FInfo.CurFre));
//	LOG_DEBUG("next num %d", FInfo.divideFre);
	if(FInfo.divideFre <= 3) {
		FInfo.endTest = 1;
		LOG_DEBUG("end test ");
	}

	uart_input.receive_flag = 0;
	uart_output.receive_flag = 0;
}

int testIsOver()
{
//	return 0;
	return FInfo.endTest;
}

void beginFFT()
{
	Complex result[SIZE];
	FFT(input,result,SIZE);

	Result.inputIm = result[1].imagin;
	Result.inputRe = result[1].real;
//	LOG_DEBUG("OK");
//	printf("complex(%d, %d),\r\n", (int)(Result.inputRe * 10000), (int)(Result.inputIm * 10000));

	FFT(output,result,SIZE);
	Result.outIm = result[1].imagin;
	Result.outRe = result[1].real;


	Result.fre = FInfo.CurFre;
}

void sendMessage()
{
	unsigned char str[150] = {0};

	sprintf(str,"{\"start\":\"data\",\"inRe\":%d,\"inIm\":%d,\"outRe\":%d,\"outIm\":%d,\"fre\":%u,\"end\":\"end\"}\n",
			(int)(Result.inputRe * 100000),(int)(Result.inputIm * 100000),(int)(Result.outRe * 100000),
			(int)(Result.outIm * 100000),(unsigned int)(Result.fre * 100000));
	log_hex(str,strlen(str));
	uart.send_string(strlen(str),str);
	delay();
}

int sampleIsReady()
{
//	return 1;
	return uart_input.receive_flag && uart_output.receive_flag;
//	return uart_input.receive_flag;
}

void init()
{
	memset(&FInfo, 0, sizeof(FInfo));
	memset(&ReceiveMessage, 0, sizeof(ReceiveMessage));
	memset(&Result, 0, sizeof(Result));
}

void show(OutputMessage Result) {
//	LOG_DEBUG("inputRe: %d", (int)(Result.inputRe));
//	LOG_DEBUG("inputIm: %d", (int)(Result.inputIm));
//	LOG_DEBUG("outRe: %d", (int)(Result.outRe));
//	LOG_DEBUG("outIm: %d", (int)(Result.outIm));
//	LOG_DEBUG("fre: %d", (int)(Result.fre));
}

int msg_proc(unsigned char *data, int length)
{
	if(NULL != strstr(data, "S f"))
	{
		ReceiveMessage.getMessege = 1;
		FInfo.CurFre = 15.625;
		FInfo.divideFre = 100000;
		FInfo.endTest = 0;

		LOG_DEBUG("start");
	}
	else if(NULL != strstr(data, "stop"))
	{
		ReceiveMessage.getMessege = 0;
		LOG_DEBUG("end");
	}
	return 0;
}

extern unsigned char inputData[64];
extern unsigned char outputData[64];

int main()
{
	LOG_DEBUG("Hello from Nios II!");
	int i = 0,j = 0;
	uart.init();
	uart_input.init();
	uart_output.init();

	init();
	FInfo.CurFre = 15.625;
	FInfo.divideFre = 100000;
	FInfo.endTest = 0;

	for(i = 0; ;i++)
	{
		if(uart.receive_flag == 1)
		{
			j = 1;
			uart.receive_flag = 0;
		}
		if(j != 0)
		{
			j++;
			if(j > 1000)
			{
				LOG_DEBUG("wifi recieve %d data:", uart.receive_count);
				log_hex(uart.receive_buffer, uart.receive_count);
				msg_proc(uart.receive_buffer, uart.receive_count);
				uart.receive_count = 0;
				j = 0;
			}
		}

		if(!getBeginMessge() || testIsOver())
		{
//			init();
//			FInfo.CurFre = 15.625;
//			FInfo.divideFre = 100000;
//			FInfo.endTest = 0;
//			delay();
//			delay();
//			delay();
//			delay();
//			delay();
//			delay();
//			delay();
//			delay();
			continue;
		}

		setDDSFre();
		while(!sampleIsReady());
		parseAdData(input, uart_input.receive_buffer);
		parseAdData(output, uart_output.receive_buffer);
		beginFFT();
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_START_BASE,0);
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_RST_BASE,0);
		sendMessage();
		if(j > 0)
		{
			j = 1000;
		}
//		show(Result);
	}
	LOG_DEBUG("end main");
	return 0;
}

void delay() {
	int i = 0;
	for(; i < 100; i ++);
}
