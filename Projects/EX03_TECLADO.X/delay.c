#include "delay.h"


 void delayMs(uint16_t time)
    {
        for(uint16_t i =1 ; i < time; i++)
        {
            __delay_ms(1);
        }
    }