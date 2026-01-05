#include <STC89C5xRC.H>
#include "LCD1602.h"
#include "DS1302.h"


unsigned char Sencond;

void main()
{
	LCD_Init();
	DS1302_Init();
	LCD_ShowString(1,1,"RST");
	DS1302_WriteByte(0x80,0x03);
	
	while(1)
	{
		Sencond=DS1302_ReadByte(0x81);
		LCD_ShowNum(2,1,Sencond,3);
		
	}

}