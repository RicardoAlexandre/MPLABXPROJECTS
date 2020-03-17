#include "hcm.h"
#include "rotatoryEncoder.h"

int enc_count;

void readEncoder(){
    static uint8_t aux_enc;
      
    if(!enc_A){
        
        if(!aux_enc){
            aux_enc = 0x01;
            enc_count+=1;
        }
    }else{
        if(!enc_B){
            if(!aux_enc){
                aux_enc = 0x01;
                enc_count-=1;
            }
        }
    }    
    
     if(enc_A & enc_B)
        aux_enc = 0x00;
}