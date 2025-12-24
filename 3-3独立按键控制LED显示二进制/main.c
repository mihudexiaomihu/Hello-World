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
	unsigned char a=0;
	while(1)
	{
		if(P31==0)
		{
			Delay(20);
			while(P31==0);
			Delay(20);
			a++;
			P2=~a;
		
		}
	}
	
}
//
/*void main()
{
	P2=0xFF;
	while(1)
	{
		if(P31==0)
		{
			Delay(20);
			while(P31==0);
			Delay(20);
			
			P2--;
		
		}
	}
	
}*/