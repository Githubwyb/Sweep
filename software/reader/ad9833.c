/*
 * ad9833.c
 *
 *  Created on: 2017-12-27
 *      Author: Dell
 */



#include "ad9833.h"
#include<stdio.h>
#include "altera_avalon_pio_regs.h"

//***************************
//		Pin assign
//		Cyclone			AD9833
//		PIN_110 		---> FSYNC
//		PIN_105 		---> SCK
//		PIN_103			---> DAT
//***************************

	/*�˿ڶ��� */
//	#define PORT_FSYNC	GPIOB
//	#define PIN_FSYNC	GPIO_Pin_15
//
//	#define PORT_SCK	GPIOB
//	#define PIN_SCK		GPIO_Pin_14
//
//	#define PORT_DAT	GPIOB
//	#define PIN_DAT		GPIO_Pin_13
	int value = 0;
//****************************************************************


#define FSYNC_0()		value = value & 0b011; IOWR_ALTERA_AVALON_PIO_DATA(DDS_BASE, value)
#define FSYNC_1()		value = value | 0b100; IOWR_ALTERA_AVALON_PIO_DATA(DDS_BASE, value)

#define SCK_0()		value = value & 0b101; IOWR_ALTERA_AVALON_PIO_DATA(DDS_BASE, value )
#define SCK_1()		value = value | 0b010; IOWR_ALTERA_AVALON_PIO_DATA(DDS_BASE, value )

#define DAT_0()		value = value & 0b110; IOWR_ALTERA_AVALON_PIO_DATA(DDS_BASE, value )
#define DAT_1()		value = value | 0b001; IOWR_ALTERA_AVALON_PIO_DATA(DDS_BASE, value )

//��ʼ��AD9833 GPIO

void AD9833_Init_GPIO()
{
//    GPIO_InitTypeDef GPIO_InitStructure;
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
//    GPIO_InitStructure.GPIO_Pin = PIN_FSYNC|PIN_SCK|PIN_DAT;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//    GPIO_Init(PORT_SCK, &GPIO_InitStructure);
	IOWR_ALTERA_AVALON_PIO_DIRECTION(DDS_BASE, 0x0);
}

/*
*********************************************************************************************************
*	�� �� ��: AD9833_Delay
*	����˵��: ʱ����ʱ
*	��    ��: ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void AD9833_Delay(void)
{
	int i;
	for (i = 0; i < 1; i++);
}



/*
*********************************************************************************************************
*	�� �� ��: AD9833_Write
*	����˵��: ��SPI���߷���16��bit����
*	��    ��: TxData : ����
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void AD9833_Write(unsigned int TxData)
{
	unsigned char i;

	SCK_1();
	//AD9833_Delay();
	FSYNC_1();
	AD9833_Delay();
	FSYNC_0();
	AD9833_Delay();
	for(i = 0; i < 16; i++)
	{
		if (TxData & 0x8000)
		{
			DAT_1();
		}
		else
		{
			DAT_0();
		}

		AD9833_Delay();
		SCK_0();
		AD9833_Delay();
		SCK_1();

		TxData <<= 1;
	}
	FSYNC_1();

}
/*
*********************************************************************************************************
*	�� �� ��: AD9833_WaveSeting
*	����˵��: ��SPI���߷���16��bit����
*	��    ��: 1.Freq: Ƶ��ֵ, 0.1 hz - 12Mhz
			  2.Freq_SFR: 0 �� 1
			  3.WaveMode: TRI_WAVE(���ǲ�),SIN_WAVE(���Ҳ�),SQU_WAVE(����)
			  4.Phase : ���εĳ���λ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void AD9833_WaveSeting(double Freq,unsigned int Freq_SFR,unsigned int WaveMode,unsigned int Phase )
{

	int frequence_LSB,frequence_MSB,Phs_data;
	double   frequence_mid,frequence_DATA;
	long int frequence_hex;

	/*********************************����Ƶ�ʵ�16����ֵ***********************************/
	frequence_mid=268435456/25;//�ʺ�25M����
	//���ʱ��Ƶ�ʲ�Ϊ25MHZ���޸ĸô���Ƶ��ֵ����λMHz ��AD9833���֧��25MHz
	frequence_DATA=Freq;
	frequence_DATA=frequence_DATA/1000000;
	frequence_DATA=frequence_DATA*frequence_mid;
	frequence_hex=frequence_DATA;  //���frequence_hex��ֵ��32λ��һ���ܴ�����֣���Ҫ��ֳ�����14λ���д�����
	frequence_LSB=frequence_hex; //frequence_hex��16λ�͸�frequence_LSB
	frequence_LSB=frequence_LSB&0x3fff;//ȥ�������λ��16λ����ȥ����λ������14λ
	frequence_MSB=frequence_hex>>14; //frequence_hex��16λ�͸�frequence_HSB
	frequence_MSB=frequence_MSB&0x3fff;//ȥ�������λ��16λ����ȥ����λ������14λ

	Phs_data=Phase|0xC000;	//��λֵ
	AD9833_Write(0x0100); //��λAD9833,��RESETλΪ1
	AD9833_Write(0x2100); //ѡ������һ��д�룬B28λ��RESETλΪ1

	if(Freq_SFR==0)				  //���������õ�����Ƶ�ʼĴ���0
	{
		frequence_LSB=frequence_LSB|0x4000;
		frequence_MSB=frequence_MSB|0x4000;
		 //ʹ��Ƶ�ʼĴ���0�������
		AD9833_Write(frequence_LSB); //L14��ѡ��Ƶ�ʼĴ���0�ĵ�14λ��������
		AD9833_Write(frequence_MSB); //H14 Ƶ�ʼĴ����ĸ�14λ��������
		AD9833_Write(Phs_data);	//������λ
		//AD9833_Write(0x2000); /**����FSELECTλΪ0��оƬ���빤��״̬,Ƶ�ʼĴ���0�������**/
	}
	if(Freq_SFR==1)				//���������õ�����Ƶ�ʼĴ���1
	{
		 frequence_LSB=frequence_LSB|0x8000;
		 frequence_MSB=frequence_MSB|0x8000;
		//ʹ��Ƶ�ʼĴ���1�������
		AD9833_Write(frequence_LSB); //L14��ѡ��Ƶ�ʼĴ���1�ĵ�14λ����
		AD9833_Write(frequence_MSB); //H14 Ƶ�ʼĴ���1Ϊ
		AD9833_Write(Phs_data);	//������λ
		//AD9833_Write(0x2800); /**����FSELECTλΪ0������FSELECTλΪ1����ʹ��Ƶ�ʼĴ���1��ֵ��оƬ���빤��״̬,Ƶ�ʼĴ���1�������**/
	}

	if(WaveMode==TRI_WAVE) //������ǲ�����
		AD9833_Write(0x2002);
	if(WaveMode==SQU_WAVE)	//�����������
		AD9833_Write(0x2028);
	if(WaveMode==SIN_WAVE)	//������Ҳ���
		AD9833_Write(0x2000);

}



