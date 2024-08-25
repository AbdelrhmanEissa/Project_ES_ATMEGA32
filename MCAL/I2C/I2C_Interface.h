/*
  * File:  I2C_Interface.h 
 *	SWC:    I2C
 *	Version: 1.0 
 *  Created on: 11-08-2024 
 *  Author: Abdalla Ragab 
 */
#ifndef I2C_INTERFACE
#define I2C_INTERFACE

#define I2C_READ_OP		0b1
#define I2C_WRITE_OP	0b0

#define I2C_STAT_STA			0x08
#define I2C_STAT_ADDRESS_ACK	0x18
#define I2C_STAT_DATA_ACK		0x28

void I2C_InitMaster(u32 bit_rate);
void I2C_InitSlave(void);
u8 I2C_SendStart(void);
u8 I2C_SendAddress(u8 address, u8 op);
u8 I2C_SendData(u8 data);
u8 I2C_SendStop(void);
u8 I2C_ReceiveWithACK(void);
u8 I2C_ReceiveWithoutACK(void);



#endif // I2C_INTERFACE
