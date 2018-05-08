/*
 * ad9833.h
 *
 *  Created on: 2017-12-27
 *      Author: Wang Yuhao
 */

#ifndef AD9833_H_
#define AD9833_H_
#include "system.h"

#define TRI_WAVE 	0  		//������ǲ�
#define SIN_WAVE 	1		//������Ҳ�
#define SQU_WAVE 	2		//�������
void test();

void AD9833_WaveSeting(double frequence,unsigned int frequence_SFR,unsigned int WaveMode,unsigned int Phase);

void AD9833_Init_GPIO(void);
void AD9833_AmpSet(unsigned char amp);


#endif /* AD9833_H_ */