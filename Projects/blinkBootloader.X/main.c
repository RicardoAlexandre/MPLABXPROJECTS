/*
 * File:   main.c
 * Author: ricardoguedes
 *
 * Created on December 11, 2019, 12:15 PM
 */

#include "main.h"

void main(void) {
    
    systemInit();
    
    while(1){
        
        LATBbits.LATB7=1;
        __delay_ms(250);
         LATBbits.LATB7=0;
         __delay_ms(250);
    }
}
