#include "app.h"
extern volatile bool TimerCallBackON; 

uint8_t flag = 0; 
void app()
{
    //-----------------------------------
    if(IO_RB0_PORT == 0 && flag == 0)
    {
        
        IO_RD0_Toggle(); 
        
       printf("{\"GPIO1\": %d }", IO_RD0_LAT); 
       
       //EUSART1_Write('A');
       
       delayMs(80); 
       flag = 1; 
    }
    if(IO_RB0_PORT == 1 && flag == 1)
    {
        flag = 0;
        delayMs(80);
    }
   
    //----------------------------------
    
    if(EUSART1_DataReady > 0)
    {
        uint8_t rec = EUSART1_Read(); 
        UART_Received(rec);
        //EUSART1_Write(rec);
    }
    
    //-----------------------------------
    if(TimerCallBackON == true)
    {
      uint16_t adcRes = ADC_GetConversion(0);
      printf((const char*)"{\"AN0\": %d }", adcRes);
      
      TimerCallBackON = false;
    }
    
}


#define buffer_size 20
volatile unsigned char *Pot;
volatile unsigned char dta[20];
volatile unsigned char aux = 0;

//{"GPIO1":0}

void UART_Received(uint8_t rec)
{
 
   if(rec == '{' && aux == 0)  //é o coringa? (inicio de protocolo)
   {
      aux = 1;   //flag que indica o início do protocolo
      Pot = dta;   //salva o endereço inicial do vetor no ponteiro P
   }
    else
       if (aux == 1)
        {
          *Pot = rec;  //salva na matriz o valor recebido na UART RX
           Pot++;

           if((Pot-dta) >= buffer_size)
           {
             aux = 0; //Descarta pacote e reinicia a recepção novamente
                      //pois ultrapassou o comprimento definido para o buffer
           }
        }
    if(aux == 1 && rec == '}')
     {
         //se chegou aqui é porque já recebemos TODOS os bytes do
         //protocolo, portanto podemos processar dta[]
         processar();
         aux = 0;
     }

}



void processar()
{
  //@Neste momento dta armazena o valor=  "GPIO1":X    onde X corresponde ao valor (dta[8])
  //@Atenção: As aspas fazem parte do Protocolo.
  
  if(dta[0] == '\"' && dta[1] == 'G' && dta[2] == 'P'&& dta[3] == 'I'&& dta[4] == 'O'&& dta[5] == '1'&& dta[6] == '\"')
   {
     if(dta[7] == ':')
     {
          switch(dta[8])
           {
             case '0': IO_RD0_LAT = 0; break;
             case '1': IO_RD0_LAT = 1; break;
           }
     }
   }

}


