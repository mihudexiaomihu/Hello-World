#include <STC89C5xRC.H>


unsigned char NixieTable[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};//???0?9????????

void Delay(xms)
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


void Nixie(unsigned char Location,Number)
{
	switch(Location)
	{
		case 7:
			P24=0;P23=0;P22=1;break;
		case 6:
			P24=0;P23=1;P22=0;break;
		case 5:
			P24=0;P23=1;P22=1;break;		
		case 4:
			P24=1;P23=0;P22=0;break;
		case 3:
			P24=1;P23=0;P22=1;break;
		case 2:
			P24=1;P23=1;P22=0;break;
		case 1:
			P24=1;P23=1;P22=1;break;
		case 8:
			P24=0;P23=0;P22=0;break;
	}
	P0=NixieTable[Number];
	Delay(1);
	P0=0x00;
}
	


void main()
{
	
	while(1)
	{
		Nixie(1,1);
		//Delay(10);
		Nixie(2,2);
		//Delay(10);
		Nixie(3,3);
		//Delay(10);
		Nixie(3,3);
		//Delay(10);
		Nixie(4,4);
		//Delay(10);
		Nixie(5,5);
		//Delay(10);
		Nixie(6,6);
		//Delay(10);
		Nixie(7,7);
		//Delay(10);
		Nixie(8,8);
		//Delay(10);
		
	}
	
}