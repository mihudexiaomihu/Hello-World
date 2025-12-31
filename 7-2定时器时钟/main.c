#include <STC89C5xRC.H>
#include "TIMER0.h"
#include "Key.h"
#include "LCD1602.h"

unsigned char Sec,Min,Hour;

void main()
{
	
	LCD_Init();
	LCD_ShowString(1,1,"Clock:");
	LCD_ShowString(2,1,"00:00:00");
	Timer0_Init();
	while(1)
	{
		LCD_ShowNum(2,7,Sec,2);
		LCD_ShowNum(2,4,Min,2);
		LCD_ShowNum(2,1,Hour,2);
	}

}


void Timer0_Routine() interrupt 1
{
	static unsigned count = 0 ;
	TH0 = 0xFC ;
	TL0 = 0x17 ;
	count ++;
	if(count > 1000)
	{
		count = 0 ;
		Sec++;
		if(Sec>60)
		{
			Sec = 0;
			Min ++;
			if(Min>60)
			{
				Min = 0;
				Hour ++;
			}
		}
	}
}




