/********************************************************************
//Comments All Application handled here
 *******************************************************************/

/** INCLUDES *******************************************************/

#define _XTAL_FREQ 48000000

#include "system.h"

#include <stdint.h>
#include <string.h>
#include <stddef.h>

#include "usb.h"

#include "app_device_cdc_basic.h"
#include "usb_config.h"
#include <plib/delays.h>

/** VARIABLES ******************************************************/

static uint8_t readBuffer[CDC_DATA_OUT_EP_SIZE];
static uint8_t writeBuffer[CDC_DATA_IN_EP_SIZE];

/*********************************************************************
* Function: void APP_DeviceCDCBasicDemoInitialize(void);
*
* Overview: Initializes the demo code
*
* PreCondition: None
*
* Input: None
*
* Output: None
*
********************************************************************/
void APP_DeviceCDCBasicDemoInitialize()
{
    CDCInitEP();

    
    line_coding.bCharFormat = 0;
    line_coding.bDataBits = 8;
    line_coding.bParityType = 0;
    line_coding.dwDTERate = 9600;

}

/*********************************************************************
* Function: void APP_DeviceCDCBasicDemoTasks(void);
*
* Overview: Keeps the demo running.
*
* PreCondition: The demo should have been initialized and started via
*   the APP_DeviceCDCBasicDemoInitialize() and APP_DeviceCDCBasicDemoStart() demos
*   respectively.
*
* Input: None
*
* Output: None
*
* Description:Modifiy your code here to do stuff over usb
*
********************************************************************/
void APP_DeviceCDCBasicDemoTasks()
{

       //Switch1
       LATDbits.LATD1 = 1;
       TRISDbits.RD1 = 1;
       PORTDbits.RD1 = 1;

       //Switch2
       LATDbits.LATD2 = 1;
       TRISDbits.RD2 = 1;
       PORTDbits.RD2 = 1;
    /* Check to see if there is a transmission in progress, if there isn't, then
     * we can see about performing an echo response to data received.
     */
    if( USBUSARTIsTxTrfReady() == true)
    {

        uint8_t i;
        uint8_t numBytesRead;
        int x;

        //put only once since condition false
        if (RD1 == 0) {
            __delay_ms(10);
            if (RD1 == 0){
             __delay_ms(10);
            putrsUSBUSART("Button 1 Pressed");
            __delay_ms(10);
            __delay_ms(10);
            }
        }

        //put only once since condition false
        if (RD2 == 0){
            __delay_ms(10);
                if (RD2 == 0){
                    __delay_ms(10);
                    putrsUSBUSART("Button 2 Pressed");
                      __delay_ms(10);
                      __delay_ms(10);
                }
            }
    }

    CDCTxService();
}
