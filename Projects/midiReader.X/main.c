#include <p18f4550.h>
#include "HardwareConfig.h"
#include "lcd.h"
#include <usart.h>
#include <sw_uart.h>
#include <delays.h>
#include <stdlib.h>
#include <stdio.h>

void DelayTXBitUART(){
    Delay100TCYx(1);
    Delay1TCYx(18);
}

void DelayRXHalfBitUART(){
    Delay10TCYx(5);
    Delay1TCYx(6);
}
void DelayRXBitUART(){
    Delay100TCYx(1);
    Delay10TCYx(2);
}

void main() {

    TRISD = 0b00000000;
    
    unsigned char recebe_midi;
    unsigned char dado_recebido;
    unsigned char n_dado;
    char s[20];

    OpenUSART(USART_TX_INT_OFF
            & USART_RX_INT_OFF
            & USART_ASYNCH_MODE
            & USART_EIGHT_BIT
            & USART_CONT_RX
            & USART_BRGH_HIGH, 19);
    
    BAUDCONbits.BRG16 = 0;   // Gerador de 8bits.                 (0 ? Gerador de 8bits e 1 ? Gerador de 16bits)
    BAUDCONbits.ABDEN = 0;   // Desabilita o auto baud rate.  (0 ? Desabilita e 1 ? Habilita)
    BAUDCONbits.WUE = 0; 
            
    __delay_ms(10);
    
    OpenUART();
    
    __delay_ms(10);
    
    Lcd_Init();
    
    __delay_ms(10);
    
    
    while (1) {
        
        if(DataRdyUSART())
        {       
                dado_recebido = getcUSART();   
                
               //  putcUSART(dado_recebido);
                 while (BusyUSART()) ;
                                        
                 putcUART(dado_recebido);
                               
          while (BusyUSART()) ;
            }
      
 
        
        /*
        getsUSART(recebe_midi,3);
        
        sprintf(s,"%c", recebe_midi[0]);
        Lcd_Clear();
        Lcd_Set_Cursor(1, 1);
        Lcd_Write_String(s);
       
        

      //  delay_x100ms(1);
*/
 
}
}