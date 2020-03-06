/*
 * File:   main.c
 * Author: ricardoalexandre
 *
 * Created on November 18, 2017, 4:13 PM
 */


#include <xc.h>
#include "hardware_config.h"
#include <pic16f877a.h>




void main(void) {
    
    TRISD = 0x00;
    
    PORTD=0x00;
    
    while(1){
    PORTD=0xFF;
    
    _delay(500000);
    
    //PORTDbits.RD0=1;
    //PORTDbits.RD3=1;
    PORTD=0x00;
    
    _delay(500000);
    }
    return;
    
}
