
/*
 * main.c
 *
 *  Created on: Aug 15, 2024
 *      Author: Abdelrhman M Eissa
 */


#include  "../LIB/STD_Types.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/Keypad/Keypad_interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/I2C/I2C_Interface.h"
#include "../HAL/Servo/Servo_interface.h"
#include "../MCAL/UART/UART_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../HAL/Project_file/p_interface.h"
#include "../MCAL/7-USART/UART_Interface.h"
#include <util/delay.h>






u8 res[]= "Login success";
u8 length = (sizeof(res)/sizeof (res[0]));

int main() {



	void Project_Init();
    while (1) {

       	  if ( (login())) {
       		  LCD_voidSendCommand(LCD_CLEAR_DISPLAY);
       		  SetDDRAM_Add(0);
       		  LCD_voidPrintStr("Unlocked!");
       		  Servo_SetAngle(SERVO1, 90);  // Unlock
       		  LED_voidSetLEDHigh(LED4);   //Buzzer
       		  UART_Sendstr(res , length);
       		  _delay_ms(1000);
       		  LED_voidSetLEDLow(LED4);
       		  Servo_SetAngle(SERVO1, 0);   // Lock again
       	    }

    }

 return 0;
     }

