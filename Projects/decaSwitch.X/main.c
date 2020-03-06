/*
 * File:   main.c
 * Author: Ricardo Alexandre
 *
 * Created on 23 de Julho de 2016, 11:55
 */

#include <p18f4550.h>
#include "configBits.h"
#include <stdio.h>
#include <stdlib.h>
//#include <usart.h>



#define _XTAL_FREQ 20000000

//Foots
#define foot1 PORTAbits.RA0
#define foot2 PORTAbits.RA1
#define foot3 PORTAbits.RA2
#define foot4 PORTAbits.RA3
#define foot5 PORTAbits.RA4
#define foot6 PORTAbits.RA5
#define foot7 PORTBbits.RB2
#define foot8 PORTBbits.RB3
#define foot9 PORTCbits.RC0
#define foot0 PORTCbits.RC1

#define footup   PORTCbits.RC2
#define footdown PORTEbits.RE3


//Loop de pedais
#define  loop1 LATDbits.LATD0
#define  loop2 LATDbits.LATD1
#define  loop3 LATDbits.LATD2
#define  loop4 LATDbits.LATD3
#define  loop5 LATDbits.LATD4
#define  loop6 LATDbits.LATD5
#define  loop7 LATDbits.LATD6
#define  loop8 LATDbits.LATD7
#define  loop9 LATEbits.LATE0
#define  loop0 LATEbits.LATE1


//External switchs
#define  esw1 LATEbits.LATE2
#define  esw2 LATBbits.LATB4        
#define  esw3 LATBbits.LATB5
#define  esw4 LATBbits.LATB6
#define  esw5 LATBbits.LATB7


/* Bit Operation macros */
#define set_bit   (b,n) ((b) |=   (1<<(n)))        /* Set bit number n in byte b   */
#define clear_bit (b,n) ((b) &= (~(1<<(n))))       /* Clear bit number n in byte b */
#define read_bit  (b,n) ((b) &    (1<<(n)))        /* Read bit number n in byte b  */
#define fbi       (b,n) ((b) ^=   (1<<(n)))        /* Flip bit number n in byte b  */

#define bit_is_set (b,n)   (b & (1<<n))      /* Test if bit number n in byte b is set   */
#define bit_is_clear(b,n) (!(b & (1<<n)))   /* Test if bit number n in byte b is clear */


unsigned char prst_l[10], prst_h[10];
int i=1;


union low_byte {
        unsigned byte;

        struct {
            unsigned b0 : 1, 
                     b1 : 1, 
                     b2 : 1, 
                     b3 : 1, 
                     b4 : 1, 
                     b5 : 1, 
                     b6 : 1, 
                     b7 : 1;
                    
        } bitv;
    } var;
    
    
    union high_byte {
        unsigned char byte;

        struct {
            unsigned b0 : 1, 
                     b1 : 1, 
                     b2 : 1, 
                     b3 : 1, 
                     b4 : 1, 
                     b5 : 1, 
                     b6 : 1, 
                     b7 : 1;
        } bitv;
    } var2;
    

void setaLoops(unsigned char preset_l, unsigned char preset_h){
            
    var.byte=preset_l;
    var2.byte=preset_h;
    

loop1=var.bitv.b0;
loop2=var.bitv.b1;
loop3=var.bitv.b2;
loop4=var.bitv.b3;
loop5=var.bitv.b4;
loop6=var.bitv.b5;
loop7=var.bitv.b6;
loop8=var.bitv.b7;

loop9=var2.bitv.b0;
loop0=var2.bitv.b1;
esw1=var2.bitv.b2;
esw2=var2.bitv.b3;
esw3=var2.bitv.b4;
esw4=var2.bitv.b5;
esw5=var2.bitv.b6;
    
}

void changeBankUP(){
    
    i=i+1;
    if(i>9){
        prst_l[0]=0b00010001;
        prst_h[0]=0b01000001;
        i=0;       
    }
    while(!footup);
}

void changeBankUDOWN(){
    
    i=i-1;
    if(i<0)
        i=9;
    
}

void main(void) {
  
    TRISA = 0b11111111;
    TRISB = 0b00001111;
    TRISC = 0b00000111;
    TRISD = 0b00000000;
    TRISE = 0b11111000;
    
    PORTD = 0x00;
    PORTE = 0x00;
    PORTB = 0x00;
    
   /* OpenUSART(USART_TX_INT_OFF
             &USART_RX_INT_ON
             &USART_ASYNCH_MODE
             &USART_EIGHT_BIT
             &USART_BRGH_HIGH,39);
    */
    
    
    
    __delay_ms(10);
    
    while(1){
        
        if(!footup){
            changeBankUP();
        }
        
        if(!footdown){
            changeBankUDOWN();
        }      
        
        setaLoops(prst_l[0],prst_h[0]);
        
        __delay_ms(10);
    }
}
