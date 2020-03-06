/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.26
        Device            :  PIC18F46K22
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set TECLA_1 aliases
#define TECLA_1_TRIS               TRISBbits.TRISB0
#define TECLA_1_LAT                LATBbits.LATB0
#define TECLA_1_PORT               PORTBbits.RB0
#define TECLA_1_WPU                WPUBbits.WPUB0
#define TECLA_1_ANS                ANSELBbits.ANSB0
#define TECLA_1_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define TECLA_1_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define TECLA_1_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define TECLA_1_GetValue()           PORTBbits.RB0
#define TECLA_1_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define TECLA_1_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define TECLA_1_SetPullup()      do { WPUBbits.WPUB0 = 1; } while(0)
#define TECLA_1_ResetPullup()    do { WPUBbits.WPUB0 = 0; } while(0)
#define TECLA_1_SetAnalogMode()  do { ANSELBbits.ANSB0 = 1; } while(0)
#define TECLA_1_SetDigitalMode() do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()    do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()   do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()   do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()         PORTCbits.RC6
#define RC6_SetDigitalInput()   do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()  do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetAnalogMode() do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()    do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()   do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()   do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()         PORTCbits.RC7
#define RC7_SetDigitalInput()   do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()  do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetAnalogMode() do { ANSELCbits.ANSC7 = 1; } while(0)
#define RC7_SetDigitalMode()do { ANSELCbits.ANSC7 = 0; } while(0)

// get/set LED1 aliases
#define LED1_TRIS               TRISDbits.TRISD0
#define LED1_LAT                LATDbits.LATD0
#define LED1_PORT               PORTDbits.RD0
#define LED1_ANS                ANSELDbits.ANSD0
#define LED1_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define LED1_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define LED1_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define LED1_GetValue()           PORTDbits.RD0
#define LED1_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define LED1_SetAnalogMode()  do { ANSELDbits.ANSD0 = 1; } while(0)
#define LED1_SetDigitalMode() do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set LED2 aliases
#define LED2_TRIS               TRISDbits.TRISD1
#define LED2_LAT                LATDbits.LATD1
#define LED2_PORT               PORTDbits.RD1
#define LED2_ANS                ANSELDbits.ANSD1
#define LED2_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define LED2_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define LED2_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define LED2_GetValue()           PORTDbits.RD1
#define LED2_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define LED2_SetAnalogMode()  do { ANSELDbits.ANSD1 = 1; } while(0)
#define LED2_SetDigitalMode() do { ANSELDbits.ANSD1 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/