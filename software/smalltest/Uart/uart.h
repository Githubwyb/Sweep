/*
 * uart.h
 *
 *  Created on: 2018-2-27
 *      Author: Dell
 */

#ifndef UART_H_
#define UART_H_

#include "sopc.h"

#define BUFFER_SIZE 200

typedef struct{
	unsigned int receive_flag;
	unsigned int receive_count;
	unsigned char receive_buffer[BUFFER_SIZE];
	int (* send_byte)(unsigned char data);
	void (* send_string)(unsigned int len, unsigned char *str); //2
	int (* init)(void);
	unsigned int (* baudrate)(unsigned int baudrate);
}UART_T;

extern UART_T uart;

#endif /* UART_H_ */
