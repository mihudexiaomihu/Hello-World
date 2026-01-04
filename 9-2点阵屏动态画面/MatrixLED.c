#include <STC89C5xRC.H>
#include "DELAY.h"

sbit RCK=P3^5;
sbit SCK=P3^6;
sbit SEN=P3^4;

/**
  * @brief  点阵屏初始化
  * @param  无
  * @retval 无
  */

void MatrixLED_Init()
{
	SCK=0;
	RCK=0;
}



/**
  * @brief  75HC595写入一个字节，
  * @param  Byte    想要列的那几个发光
  * @retval 无
  */
void _74HC595_WritByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SEN=Byte&(0x80>>i);
		SCK=1;
		SCK=0;
	}
	RCK=1;
	RCK=0;
}

/**
  * @brief  LED点阵屏的一组数据
  * @param  Colum  第几列   Date  那几个灯
  * @retval 无
  */
void MatrixLED_ShowColumn(unsigned char colum,Date)
{
	_74HC595_WritByte(Date);
	P0=~(0x80>>colum);
	Delay(1);
	P0=0xFF;
	
}


