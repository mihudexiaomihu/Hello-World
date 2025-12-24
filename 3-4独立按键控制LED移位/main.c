#include <STC89C5xRC.H>

void Delay(unsigned int xms)	
{
	while(xms)
	{
		unsigned char data i, j;

		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
}

void main()
{
	int LEDNum=0;
	P20=1;
	while(1)
	{
		if(P31==0)
		{
			Delay(20);
			while(P31==0);
			Delay(20);
			LEDNum++;
			
			if(LEDNum>=8)
			{
				LEDNum=0;
			}
			P2=~(0x01<<LEDNum);
		}
		
		if(P30==0)
		{
			Delay(20);
			while(P31==0);
			Delay(20);
		
			if(LEDNum=0)
			{
				LEDNum=7;
			}
			LEDNum--;
			P2=~(0x01<<LEDNum);
		}
	}

}
	