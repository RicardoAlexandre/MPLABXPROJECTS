
// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <pic.h>

#include<pic16f877a.h>

#include "hcm.h"


void systemInit(){
    
    TRISD = 0b00000000;
    PORTD = 0x00;
    TRISA = 0b00000001;
    
    
}

void adcInit(){
    
    ADCON0bits.ADCS = 0b10; //FOSC/64
    ADCON1bits.ADCS2 = 1;   //FOSC/64
    ADCON1bits.ADFM = 1;    //Right Justified
    ADCON0bits.ADON = 0;    //ADC module is off
    ADCON1bits.PCFG = 0b1110; //RA1 as analog pin VDD VSS as reference
    
    __delay_us(25);
    
}

int readADC(uint8_t adc_channel){
    int valueADC = 0;
    ADCON0bits.CHS = adc_channel;
    ADCON0bits.ADON = 1;  
    
    __delay_us(10);
    
    ADCON0bits.GO =1;
    
    while(ADCON0bits.nDONE)  
    
        
                 valueADC = ((ADRESH<<8)+ADRESL);
                 return valueADC;         
}