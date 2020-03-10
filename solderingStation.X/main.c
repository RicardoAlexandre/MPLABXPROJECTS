/*
 * File:   main.c
 * Author: ricardo
 *
 * Created on 6 de Março de 2020, 09:34
 */

#include <stdint.h>
#include <pic16f877a.h>
#include <pic.h>
#include <stdio.h>
#include "main.h"

 int tmr1Count = 0;
 
void interrupt interruption(){
        
   //Timer 1 overflow 104ms
    
        if(PIR1bits.TMR1IF == 1){
            PIR1bits.TMR1IF =0;
           tmr1Count ++;
           
           if(tmr1Count == 4){
               PORTCbits.RC2 = !PORTCbits.RC2;
               tmr1Count = 0;
           }
            
        }
}

void main(void) {
    
    char text[16];
    systemInit();
    adcInit();
    tmr1Init();
    
    LCD_Begin();
        
    
    __delay_ms(10);
    
    int adc_Value = 0;
    
    
    
    
    while (1) {
        
        adc_Value = readADC(0);
        LCD_Cmd(LCD_CLEAR);
        LCD_Goto(1,1);
        
       sprintf(text,"ADC: %d",adc_Value);
        
       LCD_Print(text);
        __delay_ms(1000);
        

    }
}
    
