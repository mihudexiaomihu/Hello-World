#ifndef __I2C_H__
#define __I2C_H__

	void I2C_Start();
	void I2C_Stop();
	void I2C_SendByte(unsigned char Byte);
	unsigned char I2C_SeceiveAck();//接收应答
	
	unsigned char I2C_ReceiveByte();
	void I2C_SendAck(unsigned char AckBit);//发送应答
	
		
#endif
