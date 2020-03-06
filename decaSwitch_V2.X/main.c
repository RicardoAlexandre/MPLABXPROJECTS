/*
 * File:   main.c
 * Author: Ricardo Alexandre Guedes
 *
 * Created on March 2, 2017, 2:39 PM
 */

#include "main.h"

void main(void) {
    
    systemInit();
           
    while(1){   
          
       //app();
        
        putcUSART('A');
        
        __delay_ms(100);
        __delay_ms(100);
        __delay_ms(100);
        __delay_ms(100);
        __delay_ms(100);
               
    }
     
}
