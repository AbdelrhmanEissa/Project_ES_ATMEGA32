/*
  * File:  I2C_Program.c
 *	SWC:    I2C
 *	Version: 1.0 
 *  Created on: 11-08-2024 
 *  Author: Abdalla Ragab 
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"

#include    "I2C_Interface.h"
#include    "I2C_Config.h"
#include    "I2C_Private.h"

void I2C_InitMaster(u32 bit_rate)
{
	/* Enable I2C */
	SET_BIT(TWCR, TWEN);

	/* Select Prescaler */
	CLEAR_BIT(TWSR, TWPS0);
	CLEAR_BIT(TWSR, TWPS1);

	/* Set bit-rate */
	TWBR = (((u32) 8000000) / (8 * bit_rate)) - 2;
}

void I2C_InitSlave(void)
{
	/* Enable I2C */
	SET_BIT(TWCR, TWEN);

	/* Set Slave Address */
	TWAR = I2C_SLAVE_ADDRESS << 1;
}

u8 I2C_SendStart(void)
{

	/* Send Start Condition and Clear TWINT to start transmission */
	TWCR = (1<< TWSTA) | (1<< TWINT) | (1 << TWEN);

	/* wait until finish the operation */
	while(GET_BIT(TWCR, TWINT) == 0);

	/* Return Status */
	return TWSR & 0xF8;
}

u8 I2C_SendAddress(u8 address, u8 op)
{
	/* Write Address and operation to Data Register */
	TWDR = (address << TWA0) | op;

	/* Clear TWINT to start transmission */
	TWCR = (1<< TWINT) | (1 << TWEN) | (1 << TWEN);

	/* wait until finish the operation */
	while(GET_BIT(TWCR, TWINT) == 0);

	/* Return Status */
	return TWSR & 0xF8;

}

u8 I2C_SendData(u8 data)
{
	/* Write Address and operation to Data Register */
	TWDR = data;

	/* Clear TWINT to start transmission */
	TWCR = (1<< TWINT) | (1 << TWEN);

	/* wait until finish the operation */
	while(GET_BIT(TWCR, TWINT) == 0);

	/* Return Status */
	return TWSR & 0xF8;
}

u8 I2C_SendStop(void)
{
	/* Send Start Condition and Clear TWINT to start transmission */
	TWCR = (1<< TWSTO) | (1<< TWINT) | (1 << TWEN);

	/* Return Status */
	return TWSR & 0xF8;
}

u8 I2C_ReceiveWithACK(void)
{
	/* Receive Data */
	TWCR = (1<< TWEA) | (1<< TWINT) | (1 << TWEN);

	/* wait until finish the operation */
	while(GET_BIT(TWCR, TWINT) == 0);

	return TWDR;
}

u8 I2C_ReceiveWithoutACK(void)
{
	/* Receive Data */
	TWCR = (1<< TWINT) | (1 << TWEN);

	/* wait until finish the operation */
	while(GET_BIT(TWCR, TWINT) == 0);

	return TWDR;
}

u8 I2C_SendFrame(u8 address, u8 * buf, u8 len)
{
	u8 state;
	/* Send Start Cond. */
	state = I2C_SendStart();

	/* Check if there is an error */
	if(state != I2C_STAT_STA) return state;

	/* Send Address + write operation */
	state = I2C_SendAddress(address, I2C_WRITE_OP);

	/* Check if there is no response */
	if(state != I2C_STAT_ADDRESS_ACK) return state;

	/* Send Data */
	for (int i = 0; i < len; i++)
	{
		/* Send a byte of data */
		state = I2C_SendData(buf[i]);

		/* Check if there is any ACK */
		if(state != I2C_STAT_DATA_ACK) break;
	}

	/* Send Start Cond. */
	state = I2C_SendStop();

	/* Transmission Completed s*/
	return state;
}
