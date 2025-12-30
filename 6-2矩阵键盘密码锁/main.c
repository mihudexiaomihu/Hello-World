#include <STC89C5xRC.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"


unsigned char KeyNum;
unsigned int Password;
int count;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	while(1)
	{
		KeyNum=MatrixKey();
		if(KeyNum!=0)
	    {
			
			if(KeyNum<=10)
			{
				if(count<4)
				{	
					Password*=10;//Passworf=passworf*10
				
					Password+=KeyNum%10;//获取一位密码
				}
				count++;//记次加1
			}
			LCD_ShowNum(2,1,Password,4);
			
			if(KeyNum==11)//如果是S11按下，为确定
			{
				if(Password==2345)
				{
					LCD_ShowString(1,14,"ok ");
					Password=0;
					count=0;
					LCD_ShowNum(2,1,Password,4);
				}
				else
				{
					LCD_ShowString(1,14,"err");
					Password=0;
					count=0;
					LCD_ShowNum(2,1,Password,4);
				}
				if(KeyNum==12)
				{
					Password=0;
					count=0;
					LCD_ShowNum(2,1,Password,4);
					
				}
			}
		}
	}

}








/*

unsigned char KeyNum;
unsigned int Password[];
int i;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	while(1)
	{
		KeyNum=MatrixKey();
		if(KeyNum!=0)
	    {
			for(i=0;i<4;i++)
			{	
				if(KeyNum<=10)
				{
					
					
					
					Password[i]=KeyNum%10;//获取一位密码
					
					//if(Password==10)
					//{
					//	Password=0;
					//}
					//else
					//{
					//	Password=n;
					//}
				}
				i++;
				LCD_ShowNum(2,i,Password[i],i);
						
				
			}
			
			
			if(KeyNum==11)//如果是S11按下，为确定
			{
				if(Password==2345)
				{
					LCD_ShowString(1,14,"ok ");
					Password[4]={0,0,0,0};
					i=0;
					LCD_ShowNum(2,1,Password,4);
				}
				else
				{
					LCD_ShowString(1,14,"err");
					Password[4]={0,0,0,0};
					i=0;
					LCD_ShowNum(2,1,Password,4);
				}
				
			}
			
			if(KeyNum==12)
				{
					Password[4]={0,0,0,0};
					i=0;
					LCD_ShowNum(2,1,Password,4);
					
				}
		}	

	}
}
*\



