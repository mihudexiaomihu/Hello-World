
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