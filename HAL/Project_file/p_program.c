/*
 * p_program.c
 *
 *  Created on: Aug 18, 2024
 *      Author: Abdelrhman M Eissa
 */

#include  "../../LIB/STD_Types.h"
#include "../../HAL/LCD/LCD_interface.h"
#include "../../HAL/Keypad/Keypad_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/I2C/I2C_Interface.h"
#include "../../HAL/Servo/Servo_interface.h"
#include "../../MCAL/UART/UART_interface.h"
#include "../../HAL/LED/LED_interface.h"
#include "../../MCAL/GIE/GIE_interface.h"
#include "../../MCAL/7-USART/UART_Interface.h"

#include "p_config.h"
#include "p_interface.h"

#include <string.h>
#include <util/delay.h>

 u8 value;

 u8 failed[] = "Login Failed";
 u8 lengthh = (sizeof(failed)/sizeof(failed[0]));

// Function to initialize the system's peripherals
void Project_Init(){


    DIO_u8SetPinDirection(PORTC, PIN5, OUTPUT);  // Set PC5 as output (LED)
    DIO_u8SetPinDirection(PORTC, PIN4, OUTPUT);  // Set PC4 as output (buzzer)

    DIO_u8SetPinDirection(PORTD, PIN0, INPUT);       //UART RX
    DIO_u8SetPinDirection(PORTD, PIN1, OUTPUT);      //UART TX


    LCD_voidInit();         //PORT D IS CONTROL E > 3 , RW > 6 , RS > 7 , DATA PORT A 0:7
    LED_voidInit();
    Keypad_voidInit();      //PORT B >> ROW = 0:3 , COL 4:7
    Servo_Init();           //PORT D 4,5
    Servo_SetAngle(SERVO1,0);  // Initialize to 0 degrees
    UART_voidInit(9600);
}

// Function to lock the system, displaying a message and activating a buzzer
void LockSystem(void) {
    LCD_voidSendCommand(LCD_CLEAR_DISPLAY);     // Clear the LCD display
    SetDDRAM_Add(0);                            // Reset cursor to the start
    LCD_voidPrintStr("System Locked");          // Display lock message on the LCD
    UART_Sendstr(failed, lengthh);              // Send lock message over UART
    DIO_u8SetPinValue(PORTC, PIN4, HIGH);       // Activate buzzer
    Servo_SetAngle(SERVO1, -90);                // Set the servo to locking position (-90 degrees)

    _delay_ms(1000);                            // Wait for 1 second
    DIO_u8SetPinValue(PORTC, PIN4, LOW);        // Deactivate the buzzer
    Servo_SetAngle(SERVO1, 0);                  // Reset the servo to 0 degrees

    LCD_voidSendCommand(LCD_CLEAR_DISPLAY);     // Clear the LCD again
}

// Function to handle user login process
int login() {
    char entered_username[USER_LENGTH] = {0};   // Buffer to store entered username
    char entered_password[PASSWORD_LENGTH] = {0}; // Buffer to store entered password
    int tries = 0;                              // Counter for number of login attempts

    while (tries < MAX_TRIES) {                 // Loop until the maximum number of attempts is reached
        u8 indexu = 0, index = 0;               // Indexes for username and password input
        u8 key1 = 0xFF, key = 0xFF;             // Variables to store keypad input

        // Input Username
        LCD_voidSendCommand(LCD_CLEAR_DISPLAY); // Clear the LCD
        SetDDRAM_Add(0);                        // Reset cursor position
        LCD_voidPrintStr("Enter Username:");    // Prompt user for username input

        while (indexu < USER_LENGTH - 1) {      // Collect username input from the keypad
            key1 = Keypad_u8GetValue();         // Read input from the keypad

            if (key1 == 0xFF) {                 // If no key is pressed
                UART_u8ReceiveByte(&value);     // Check UART for input
                if (value == '1') break;        // If an override signal is received, break out of loop
            }
            else {                              // If a key is pressed
                LCD_voidGotoRowCol(1, indexu);  // Move cursor to next position on LCD
                LCD_voidPrintChar(key1);        // Display the pressed key on LCD
                entered_username[indexu++] = key1; // Store the key in the username buffer
                _delay_ms(300);                 // Small delay for user feedback
            }
        }
        entered_username[indexu] = '\0';        // Null-terminate the username string

        // Input Password
        LCD_voidSendCommand(LCD_CLEAR_DISPLAY); // Clear the LCD
        SetDDRAM_Add(0);                        // Reset cursor position
        LCD_voidPrintStr("Enter Password:");    // Prompt user for password input

        while (index < PASSWORD_LENGTH - 1) {   // Collect password input from the keypad
            key = Keypad_u8GetValue();          // Read input from the keypad

            if (key == 0xFF) {                  // If no key is pressed
                UART_u8ReceiveByte(&value);     // Check UART for input
                if (value == '1') break;        // If an override signal is received, break out of loop
            }
            else {                              // If a key is pressed
                LCD_voidGotoRowCol(1, index);   // Move cursor to next position on LCD
                LCD_voidPrintChar('*');         // Display a masked character for password input
                entered_password[index++] = key; // Store the key in the password buffer
                _delay_ms(300);                 // Small delay for user feedback
            }
        }
        entered_password[index] = '\0';         // Null-terminate the password string

        u8 login_success = 0;                   // Flag to indicate successful login
        for (int i = 0; i < MAX_USERS; i++) {   // Check entered credentials against stored users

            u8 username_match = 1;              // Flag to indicate matching username
            u8 password_match = 1;              // Flag to indicate matching password

            // Compare entered username with stored username
            for (int j = 0; entered_username[j] != '\0' || users[i].username[j] != '\0'; j++) {
                if (entered_username[j] != users[i].username[j]) {
                    username_match = 0;         // Set flag to 0 if username does not match
                    break;
                }
            }

            // Compare entered password with stored password
            for (int j = 0; entered_password[j] != '\0' || users[i].password[j] != '\0'; j++) {
                if (entered_password[j] != users[i].password[j]) {
                    password_match = 0;         // Set flag to 0 if password does not match
                    break;
                }
            }

            // If either the credentials match or override signal is received
            if ((username_match && password_match) || value == '1') {
                login_success = 1;              // Set login success flag
                value = '0';                    // Reset override signal
                break;
            }
        }

        if (login_success) {
            return 1;                          // Return success if login is successful
        } else {
            // Display "Incorrect!" message if login fails
            LCD_voidSendCommand(LCD_CLEAR_DISPLAY);
            SetDDRAM_Add(0);
            LCD_voidPrintStr("Incorrect!");    // Inform user of incorrect input
            _delay_ms(1000);                   // Delay before retry
            tries++;                            // Increment the attempt counter
        }
    }

    LockSystem();                               // Lock the system after max attempts

    return 0;                                   // Return failure if login fails
}
