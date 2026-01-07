#include <STC89C5xRC.H>
#include "I2C.h"

#define AT24C02_ADRESS    0xA0


/**
  * @brief  AT24C02写入一个字节
  * @param  WordAdress，要写入字节的地址
  * @param  Date 要写入的数据
  * @retval 无
  */
void AT24C02_WriteByte(unsigned char WordAdress,Date)
{
	I2C_Start();
	I2C_SendByte(AT24C02_ADRESS);
	I2C_SeceiveAck();
	I2C_SendByte(WordAdress);
	I2C_SeceiveAck();
	I2C_SendByte(Date);
	I2C_SeceiveAck();
	I2C_Stop();
}


/**
  * @brief  AT23C02读取一个字节
  * @param  WordAdress，要读出字节的地址
  * @retval 读出的数据
  */
unsigned char AT24C02_ReadByte(unsigned char WordAdress)
{
	unsigned char Date;
	I2C_Start();
	I2C_SendByte(AT24C02_ADRESS);
	I2C_SeceiveAck();
	I2C_SendByte(WordAdress);
	I2C_SeceiveAck();
	I2C_Start();
	I2C_SendByte(AT24C02_ADRESS|0x01);
	I2C_SeceiveAck();
	Date=I2C_ReceiveByte();
	I2C_SendAck(1);
	I2C_Stop();
	return Date;
}