/*
 * File:   main.c
 * Author: ricardo
 *
 * Created on 6 de Março de 2020, 09:34
 */

#include <stdint.h>
#include <pic16f877a.h>
#include <pic.h>
#include "main.h"

void main(void) {
    
    systemInit();
    adcInit();
    
    __delay_ms(10);
    
    uint16_t adcValue = 0;
    
    while (1) {
        
        adcValue = readADC(0);
        
        if(adcValue > 500){
            
            PORTDbits.RD0 =1;
        }else{
            PORTDbits.RD0 = 0;
        }    

    }

    
}
