#include <STC89C5xRC.H>
/**
  * @brief  定时器0初始化//1毫秒@12MHz
  * @param  无
  * @param  
  * @retval 无
  */

void Timer0_Init ()
{
	TMOD = 0x01 ;
	TF0 = 0 ;
	TR0 = 1 ;
	TH0 = 0xFC ;
	TL0 = 0x17 ;
	ET0 = 1 ;
	EA = 1 ;

	PT0 = 0 ;
	
}