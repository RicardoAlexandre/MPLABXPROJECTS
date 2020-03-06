#include "app.h"


void app(){
    
    if(TECLA_1_PORT == 0)
    {
       printf("#0x1:343");
       
       
      //  EUSART1_Write('b');
    LED1_Toggle();
    delayMs(500);
    }
}                          