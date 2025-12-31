#include <STC89C5xRC.H>
#include "Delay.h"

/**
  * @brief  获取独立按键键码
  * @param  无
  * @param  
  * @retval 按下按键的键码，范围0-4；无按键按下时返回0；
  */

unsigned char Key()
{
	unsigned char KeyNumber;
	if(P31==0){Delay(20);while(1);Delay(20);KeyNumber=1;}
	if(P30==0){Delay(20);while(1);Delay(20);KeyNumber=2;}
	if(P32==0){Delay(20);while(1);Delay(20);KeyNumber=3;}
	if(P33==0){Delay(20);while(1);Delay(20);KeyNumber=4;}
	return KeyNumber;
}