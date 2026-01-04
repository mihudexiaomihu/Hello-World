#ifndef __MATRIXLED_H__
#define __MATRIXLED_H__


void MatrixLED_Init();
void _74HC595_WritByte(unsigned char Byte);
void MatrixLED_ShowColumn(unsigned char colum,Date);

#endif