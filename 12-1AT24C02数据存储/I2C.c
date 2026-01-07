#include <STC89C5xRC.H>

sbit I2C_SCL=P2^1;
sbit I2C_SDA=P2^0;
//如果单片机速度很快需要加一个Delay。

/**
  * @brief  I2C开始
  * @param  无
  * @retval 无
  */
void I2C_Start()
{
	I2C_SDA=1;
	I2C_SCL=1;
	I2C_SDA=0;
	I2C_SCL=0;
}
/**
  * @brief  I2C停
  * @param  无
  * @retval 无
  */
void I2C_Stop()
{
	I2C_SDA=0;
	I2C_SCL=1;
	I2C_SDA=1;
	
}
/**
  * @brief  I2C发送一个字节
  * @param  一个字节
  * @retval 无
  */
void I2C_SendByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		I2C_SDA=Byte&(0x80>>i);
		I2C_SCL=1;
		I2C_SCL=0;	
	}	
}
/**
  * @brief  I2C接收一个字节
  * @param  无
  * @retval 接收的字节
  */
unsigned char I2C_ReceiveByte()
{
	unsigned char Byte,i;
	
	I2C_SDA=1;
	for(i=0;i<8;i++)
	{
		I2C_SCL=1;
		if(I2C_SDA==1){Byte|=(0x80>>i);}
		I2C_SCL=0;
	}
	
	return Byte;
}

/**
  * @brief  I2C发送应答
* @param AckBit，应答位，0为应答 1为非应答
  * @retval 无
  */
void I2C_SendAck(unsigned char AckBit)
{
	I2C_SDA=AckBit;
	I2C_SCL=1;
	
	I2C_SCL=0;
}

/**
  * @brief  I2C接收应答
  * @param  无
  * @retval 无
  */
unsigned char I2C_SeceiveAck()
{
	unsigned char AckBit=0;
	I2C_SDA=1;
	I2C_SCL=1;
	if(I2C_SDA==1){AckBit=1;}
	I2C_SCL=0;
	return AckBit;
}
