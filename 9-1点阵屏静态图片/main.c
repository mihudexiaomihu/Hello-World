#include <STC89C5xRC.H>
#include "DELAY.h"
sbit RCK=P3^5;
sbit SCK=P3^6;
sbit SEN=P3^4;


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

void MatrixLED_ShowColumn(unsigned char colum,Date)
{
	_74HC595_WritByte(Date);
	P0=~(0x80>>colum);
	Delay(1);
	P0=0xFF;
	
}

void main()
{
	while(1)
	{
		MatrixLED_ShowColumn(0,0xAA);
		MatrixLED_ShowColumn(1,0x55);
		MatrixLED_ShowColumn(2,0xAA);
		MatrixLED_ShowColumn(3,0x55);
		MatrixLED_ShowColumn(4,0x55);
		MatrixLED_ShowColumn(5,0x55);
		MatrixLED_ShowColumn(6,0x55);
		MatrixLED_ShowColumn(7,0x55);
	}
}
