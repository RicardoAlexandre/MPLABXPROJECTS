/*
 * File:   main.c
 * Author: Ricardo Alexandre
 *
 * Created on 29 de Fevereiro de 2020, 21:12
 */


#include <xc.h>

void main(void) {
    
    OSCCON = 0x00; // Oscilator config
    
    TRISA = 0xFF; //All Port A as input
    TRISB = 0x00; //All Port B as output 
    
    ADCON0 = 0x00; // Turn ADC off
    ADCON1 = 0xFF; //All pin as digital
    
    return;
}
