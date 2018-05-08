/*
 * message.h
 *
 *  Created on: 2018-3-12
 *      Author: Dell
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_

#include<stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINEAR 1
#define LOG 2

typedef struct
{
	int startFre;
	int endFre;
	int sweepNum;
	int showForm;
	int getMessege;
}TestMessage;

typedef struct
{
	float inputRe;
	float inputIm;
	float outRe;
	float outIm;
	double fre;
}OutputMessage;

void parseMessage(char* result, TestMessage* message);
int getStartMessge(char* message);

#endif /* MESSAGE_H_ */
