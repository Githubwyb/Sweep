/*
 * uart.h
 *
 *  Created on: 2018-2-27
 *      Author: Dell
 */

#ifndef UART_H_
#define UART_H_

#include "sopc.h"
#include "message.h"
#include "freinfo.h"
#define BUFFER_SIZE 200

typedef struct{
	unsigned int receive_flag;
	unsigned int receive_count;
	char receive_buffer[BUFFER_SIZE];
	int (* send_byte)(unsigned char data);
	void (* send_string)(unsigned int len, unsigned char *str); //2
	int (* init)(void);
	unsigned int (* baudrate)(unsigned int baudrate);
}UART_T;

extern UART_T uart;
extern UART_T uart_input;
extern UART_T uart_output;
extern TestMessage ReceiveMessage;
extern FreInfo FInfo;
#endif /* UART_H_ */
