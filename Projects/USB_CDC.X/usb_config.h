/********************************************************************
//comments here
/*********************************************************************
 * Descriptor specific type definitions are defined in: usbd.h
 ********************************************************************/

#ifndef USBCFG_H
#define USBCFG_H

/** DEFINITIONS ****************************************************/


#define USB_EP0_BUFF_SIZE       8   // Valid Options: 8, 16, 32, or 64 bytes.
                                    // Using larger options take more SRAM, but
                                    // does not provide much advantage in most types
                                    // of applications.  Exceptions to this, are applications
                                    // that use EP0 IN or OUT for sending large amounts of
                                    // application related data.

#define USB_MAX_NUM_INT         2   //Set this number to match the maximum interface number used in the descriptors for this firmware project
                                    // For tracking Alternate Setting

//Device descriptor - if these two definitions are not defined then
//  a ROM USB_DEVICE_DESCRIPTOR variable by the exact name of device_dsc
//  must exist.
#define USB_USER_DEVICE_DESCRIPTOR &device_dsc
#define USB_USER_DEVICE_DESCRIPTOR_INCLUDE extern const USB_DEVICE_DESCRIPTOR device_dsc

//Configuration descriptors - if these two definitions do not exist then
//  a const BYTE *const variable named exactly USB_CD_Ptr[] must exist.
#define USB_USER_CONFIG_DESCRIPTOR USB_CD_Ptr
#define USB_USER_CONFIG_DESCRIPTOR_INCLUDE extern const uint8_t *const USB_CD_Ptr[]


#define USB_PING_PONG_MODE USB_PING_PONG__FULL_PING_PONG    //A good all around setting


#define USB_INTERRUPT

/* Parameter definitions are defined in usb_device.h */
#define USB_PULLUP_OPTION USB_PULLUP_ENABLE


#define USB_TRANSCEIVER_OPTION USB_INTERNAL_TRANSCEIVER


#define USB_SPEED_OPTION USB_FULL_SPEED



//------------------------------------------------------------------------------------------------------------------
//Option to enable auto-arming of the status stage of control transfers, if no
//"progress" has been made for the USB_STATUS_STAGE_TIMEOUT value.
//If progress is made (any successful transactions completing on EP0 IN or OUT)
//the timeout counter gets reset to the USB_STATUS_STAGE_TIMEOUT value.

#define USB_ENABLE_STATUS_STAGE_TIMEOUTS    //Comment this out to disable this feature.

//Section 9.2.6 of the USB 2.0 specifications indicate that:
//1.  Control transfers with no data stage: Status stage must complete within
//      50ms of the start of the control transfer.
//2.  Control transfers with (IN) data stage: Status stage must complete within
//      50ms of sending the last IN data packet in fullfilment of the data stage.
//3.  Control transfers with (OUT) data stage: No specific status stage timing
//      requirement.  However, the total time of the entire control transfer (ex:
//      including the OUT data stage and IN status stage) must not exceed 5 seconds.

#define USB_STATUS_STAGE_TIMEOUT     (uint8_t)45   //Approximate timeout in milliseconds
//------------------------------------------------------------------------------------------------------------------


#define USB_SUPPORT_DEVICE

#define USB_NUM_STRING_DESCRIPTORS 3

#define USB_ENABLE_ALL_HANDLERS

/** DEVICE CLASS USAGE *********************************************/
#define USB_USE_CDC

/** ENDPOINTS ALLOCATION *******************************************/
#define USB_MAX_EP_NUMBER       2

/* CDC */
#define CDC_COMM_INTF_ID        0x0
#define CDC_COMM_EP             1
#define CDC_COMM_IN_EP_SIZE     10

#define CDC_DATA_INTF_ID        0x01
#define CDC_DATA_EP             2
#define CDC_DATA_OUT_EP_SIZE    64
#define CDC_DATA_IN_EP_SIZE     64


#define USB_CDC_SUPPORT_ABSTRACT_CONTROL_MANAGEMENT_CAPABILITIES_D1 //Set_Line_Coding, Set_Control_Line_State, Get_Line_Coding, and Serial_State commands

#endif //USBCFG_H
