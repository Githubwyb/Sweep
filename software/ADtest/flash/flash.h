#ifndef FLASH_H_
#define FLASH_H_

void W25Q16_Write(unsigned int address,unsigned char *data,unsigned char j);//向W25Q16写入 j个8位数据 第一个参数是 W25Q16的首地址 第二个参数是 内存的首地址
void W25Q16_Read(unsigned int address,unsigned char *data,unsigned char j);//从W25Q16中的address地址上读取 j个字节的数据保存到 以data为首地址的内存中
#endif 