#include <STC89C5xRC.H>


void Uart_Init()	//4800bps@11.0592MHz
{
	PCON &= 0x7F;		//波特率不倍速
	SCON = 0x50;		//8位数据,可变波特率
	
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xF4;			//设置定时初始值
	TH1 = 0xF4;			//设置定时重载值
	ET1 = 0;			//禁止定时器中断
	TR1 = 1;			//定时器1开始计时
}

void UART_SenfByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;

}

void main()
{
	Uart_Init();
	UART_SenfByte(0x66);
	while(1)
	{

	}

}

