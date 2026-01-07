#include <STC89C5xRC.H>
 
sbit DS1302_SCLK=P3^6;
sbit DS1302_IO=P3^4;
sbit DS1302_CE=P3^5;
/**
  * @brief  DS1302初始化
  * @param  无
  * @retval 无
  */
void DS1302_Init()
{
	DS1302_CE=0;
	DS1302_SCLK=0;	
}



/**
  * @brief  DS1302写入
  * @param  命令字，选择控制什么，
  * @retval 无
  */
void DS1302_WriteByte(unsigned char Command,Date)
{
	char i;
	DS1302_CE=1;
	
	for(i=0;i<8;i++)
	{
		DS1302_IO=Command&(0x01<<i);
		DS1302_SCLK=1;
		DS1302_SCLK=0;
	
	}
	for(i=0;i<8;i++)
	{
		DS1302_IO=Date&(0x01<<i);
		DS1302_SCLK=1;
		DS1302_SCLK=0;
	
	}
	DS1302_CE=0;	
/*
	DS1302_CE=1;
	DS1302_IO=Command&0x01;
	DS1302_SCLK=1;
	DS1302_SCLK=0;
	DS1302_IO=Command&0x02;
	DS1302_SCLK=1;
	DS1302_SCLK=0;
	DS1302_IO=Command&0x04;
	DS1302_SCLK=1;
	DS1302_SCLK=0;
	DS1302_IO=Command&0x08;
	DS1302_SCLK=1;
	DS1302_SCLK=0;
	DS1302_IO=Command&0x10;
	DS1302_SCLK=1;
	DS1302_SCLK=0;
	DS1302_IO=Command&0x20;
	DS1302_SCLK=1;
	DS1302_SCLK=0;
	DS1302_IO=Command&0x40;
	DS1302_SCLK=1;
	DS1302_SCLK=0;
	DS1302_IO=Command&0x80;
	DS1302_SCLK=1;
	DS1302_SCLK=0;
	DS1302_CE=0;
	*/	
}
/**
  * @brief  DS1302读出
  * @param  命令字
  * @retval 无
  */

unsigned char DS1302_ReadByte(unsigned char Command)
{
	char i,Date=0x00;
	DS1302_CE=1;
	
	for(i=0;i<8;i++)
	{
		DS1302_IO=Command&(0x01<<i);
		DS1302_SCLK=0;
		DS1302_SCLK=1;
	
	}
	
	
	for(i=0;i<8;i++)
	{
		DS1302_SCLK=1;
		DS1302_SCLK=0;
		if(DS1302_IO==1)
		{
			Date=Date|(0x01<<i);
		}
		
	}
	DS1302_CE=0;
	return Date;
}