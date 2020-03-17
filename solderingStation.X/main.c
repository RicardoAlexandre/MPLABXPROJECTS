/*
 * File:   main.c
 * Author: ricardo
 *
 * Created on 6 de Março de 2020, 09:34
 */


#include "main.h"
uint8_t enc_count;

void readEncoder(){
    static uint8_t aux_enc;
      
    if(!enc_A){
        
        if(!aux_enc){
            aux_enc = 0x01;
            enc_count+=10;
        }
    }else{
        if(!enc_B){
            if(!aux_enc){
                aux_enc = 0x01;
                enc_count-=10;
            }
        }
    }    
    
     if(enc_A & enc_B)
        aux_enc = 0x00;
}


 int tmr1Count = 0;
 
void interrupt interruption(){
        
   //Timer 1 overflow 104ms
    
        if(PIR1bits.TMR1IF == 1){
            PIR1bits.TMR1IF =0;
           tmr1Count ++;
           
           readEncoder();
           
           if(tmr1Count == 4){
              // PORTCbits.RC2 = !PORTCbits.RC2;
               tmr1Count = 0;
           }
            
        }
}

void main(void) {
    
    
    char text[16];
    enc_count = 0x00;
   
    systemInit();
    adcInit();
    tmr1Init();
    tmr2Init();
    pwm1Init();
    
    
    LCD_Begin();
        
    
    __delay_ms(10);
    
    int adc_Value = 0;
    int dutycicle = 0;
    
     LCD_Cmd(LCD_CLEAR);
    
    
    
    
    while (1) {
        
        LCD_Cmd(LCD_CLEAR);
        
        adc_Value = readADC(0);
       
        
        LCD_Goto(2,1);
        sprintf(text,"Enc: %d",enc_count);
        LCD_Print(text);
                    
        dutycicle = adc_Value / 3;
        
        dutyCiclePWM1(dutycicle);
        
       LCD_Goto(1,1);
       sprintf(text,"ADC: %d",adc_Value);
       LCD_Print(text);
       
       //LCD_Goto(2,1);
       
       //sprintf(text, "PWM: %d", dutycicle);
      // LCD_Print(text);
        
     
        __delay_ms(250);
        

    }
}
    
