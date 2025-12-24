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
	while(1)
	{
		if(P31==0)
		{
			Delay(20);
			while(P31==1);
			Delay(20);
			
			P20=~P20;
		}
		
	}

}