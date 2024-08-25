/*
 * LCD_interface.h
 *
 *  Created on: Jul 28, 2024
 *      Author: Abdelrhman M Eissa
 */


#ifndef LCD_LCD_INTERFACE_H_
#define LCD_LCD_INTERFACE_H_

#define LCD_CLEAR_DISPLAY			0x01
#define LCD_RESET_CURSOR			0x02
#define LCD_ENTRY_MODE_INC			0X06
#define LCD_ENTRY_MODE_DEC			0X04
#define LCD_DISPLAY_OFF				0X08
#define LCD_DISPLAY_ON				0X0C
#define LCD_MOVE_CURSOR				0x80
#define LCD_FUNCTION_8BIT_2LINE		0x38
#define LCD_FUNCTION_4BIT_2LINE		0x28

#define LCD_ROW0				0x00
#define LCD_ROW1				0x01

#define LCD_COL0				0x00
#define LCD_COL1				0x01
#define LCD_COL2				0x02
#define LCD_COL3				0x03
#define LCD_COL4				0x04
#define LCD_COL5				0x05
#define LCD_COL6				0x06
#define LCD_COL7				0x07
#define LCD_COL8				0x08
#define LCD_COL9				0x09
#define LCD_COL10				0x0A
#define LCD_COL11				0x0B
#define LCD_COL12				0x0C
#define LCD_COL13				0x0D
#define LCD_COL14				0x0E
#define LCD_COL15				0x0F



void LCD_voidInit(void);
void LCD_voidSendCommand(u8 u8CmdCopy);
void LCD_voidPrintChar(char u8CharCopy);
void LCD_voidPrintStr(const char * s8StringCopy);
void LCD_voidGotoRowCol(u8 u8RawCopy, u8 u8ColCopy);
void SetDDRAM_Add(u8 address);


#endif /* LCD_LCD_INTERFACE_H_ */
