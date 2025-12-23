#include <STC89C5xRC.H>
#include <INTRINS.H>
void Delay500ms()	
{
	unsigned char data i, j, k;

	_nop_();
	_nop_();
	i = 4;
	j = 205;
	k = 120;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void main()
{
	
	while(1)
	{
	P2=0xFE;
	Delay500ms();
	P2=0xFF;
	Delay500ms();	
	}
}