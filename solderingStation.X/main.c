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

void main(void) {
    
    char text[16];
    systemInit();
    adcInit();
    
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
    
