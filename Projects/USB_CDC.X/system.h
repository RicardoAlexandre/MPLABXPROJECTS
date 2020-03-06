
#ifndef SYSTEM_H
#define SYSTEM_H

#if defined(COMPILER_MPLAB_C18) //++VSK def(COMP_MPLAB_C18)
    #define __attribute__(a)
    #define const far rom

    #include <p18cxxx.h>
    #include <adc.h>

#elif defined(__XC8)
    #include <xc.h>
#endif


//PUT your pic here
#if defined(__18F4553)
    #include "pdfsusb_4550.h"
#endif

#define MAIN_RETURN void

/*** System States **************************************************/
typedef enum
{
    SYSTEM_STATE_USB_START,
    SYSTEM_STATE_USB_SUSPEND,
    SYSTEM_STATE_USB_RESUME
} SYSTEM_STATE;


/*********************************************************************
* Function: void SYSTEM_Initialize( SYSTEM_STATE state )
*
* Overview: Initializes the system.
*
* PreCondition: None
*
* Input:  SYSTEM_STATE - the state to initialize the system into
*
* Output: None
*
********************************************************************/
void SYSTEM_Initialize( SYSTEM_STATE state );


/*********************************************************************
* Function: void SYSTEM_Tasks(void)
*
* Overview: Runs system level tasks that keep the system running
*
* PreCondition: System has been initalized with SYSTEM_Initialize()
*
* Input: None
*
* Output: None
*
********************************************************************/

#define SYSTEM_Tasks()  // VSK nothing to do ???

#endif //SYSTEM_H
