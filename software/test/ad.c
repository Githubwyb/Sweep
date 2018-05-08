/*
 * ad.c
 *
 *  Created on: 2018-3-6
 *      Author: Dell
 */

#include "ad.h"
#include "log.h"

void parseAdData(float *input, unsigned char * source)
{
	int i;
	int j = 0;
//	int data = 0;
//	LOG_DEBUG("data:");
	for (i = 0; i < 32; i ++)
	{
		unsigned char low = source[j];
		unsigned char high = source[j+1];
		unsigned int result = high;
		result = result << 8;
		result = result | low;
		input[i] = computeAd(result);
		j += 2;
//		data = input[i] * 1000;
//		printf("%d ", data);
	}
//	printf("\r\n");
}


/*
 * 函数说明：
 * 调用函数可读取AD转换结果（二补数），并返回其真实值
 * 参数说明：
 * BASE为相应AD模块数据位链接的并行IO口的基地址
 */
float ReadAdRes(int BASE)
{
    float Res = 0;                              //待计算的AD结果
	int databits = 0;                           //AD结果数值位
	int DVolt = 0;                              //ADC得到二补数结果
	DVolt = IORD_ALTERA_AVALON_PIO_DATA(BASE);
	databits = DVolt & 0x7FF;
	if(0x800==(DVolt & 0x800))
	{
		Res = (databits - 0x800)/4095.0*10;
	}
	else
	{
		Res = (databits)/4095.0*10;
	}
	return Res;
}

float computeAd(int adValue)
{
	float Res = 0;                              //待计算的AD结果
	int databits = 0;                           //AD结果数值位

	databits = adValue & 0x7FF;
	if(0x800==(adValue & 0x800))
	{
		Res = (databits - 0x800)/4095.0*10;
	}
	else
	{
		Res = (databits)/4095.0*10;
	}
	return Res;
}


