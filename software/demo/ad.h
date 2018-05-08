/*
 * AD.h
 *
 *  Created on: 2018-3-1
 *      Author: Dell
 */

#ifndef AD_H_
#define AD_H_
#include "altera_avalon_pio_regs.h"
//#include "altera_avalon_timer.h"
//#include "altera_avalon_timer_regs.h"
#include <stdio.h>
void SetFreq(float Freq,int pointN,int BASE);
float ReadAdRes(int BASE);
float computeAd(int adValue);
void parseAdData(float *input, unsigned char * source);
#endif /* AD_H_ */
