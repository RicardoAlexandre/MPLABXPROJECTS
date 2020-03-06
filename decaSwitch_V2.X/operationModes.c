#include <stdint.h>

#include "operationModes.h"

union word {
        uint16_t word_t;
        struct {
            unsigned  
                     b1 : 1, 
                     b2 : 1, 
                     b3 : 1, 
                     b4 : 1, 
                     b5 : 1, 
                     b6 : 1, 
                     b7 : 1,
                     b8 : 1,
                     b9 : 1,
                     b0 : 1,
                     b11 : 1,
                     b12 : 1,
                     b13 : 1,
                     b14 : 1,
                     b15 : 1, 
                     b16 : 1;
        } word;
    };

int config = 0;
union word var,var1;
 uint16_t auxconfig;

/*                         */
void changeBankUP(){
    
    i=i+1;
    if(i>9){
        i=0;
    }
    
    while(!footup);    
}

void changeBankDOWN(){
    
  //  i=i-1;
//   if(i<0){
 //       i=9;
 //   }   
 //   while(!footdown);
    
}


/*                               */
void setLoops(uint16_t preset){ 
              
    
    var.word_t = preset;
         
    loop1 = var.word.b1;
    loop2 = var.word.b2;
    loop3 = var.word.b3;
    loop4 = var.word.b4;
    loop5 = var.word.b5;
    loop6 = var.word.b6;
    loop7 = var.word.b7;
    loop8 = var.word.b8;
    loop9 = var.word.b9;
    loop0 = var.word.b0;
    
    esw1 = var.word.b11;
    esw2 = var.word.b12;
    esw3 = var.word.b13;
    esw4 = var.word.b14;
    esw5 = var.word.b15;   
}

/*                 */
void directMode(void){

     //loop//
    if (!foot1) {      
        
       var1.word.b1= ~var1.word.b1;
       loop1 = var1.word.b1;
      
        while (!foot1) {
        }
    }

    //loop//
    if (!foot2) {
        
        var1.word.b2= ~var1.word.b2;
        loop2 = var1.word.b2;
        
        while (!foot2) {
        }
    }

    //loop//
    if (!foot3) {
        
        var1.word.b3= ~var1.word.b3;
        loop3 = var1.word.b3;
        
        while (!foot3) {
        }
    }

    //loop//
    if (!foot4) {
        
       var1.word.b4= ~var1.word.b4;
       loop4 = var1.word.b4;
       
    }
    while (!foot4) {
    }

    //loop//
    if (!foot5) {
        
        var1.word.b5= ~var1.word.b5;
        loop5 = var1.word.b5;
        
    }
    while (!foot5) {
    }

    //loop//
    if (!foot6) {
        
        var1.word.b6= ~var1.word.b6;
        loop6 = var1.word.b6;
        
    }
    while (!foot6) {
    }

    //loop//
    if (!foot7) {
        
        var1.word.b7= ~var1.word.b7;
        loop7 = var1.word.b7;
        
    }
    while (!foot7) {
    }

    //loop//
    if (!foot8) {
        
        var1.word.b8= ~var1.word.b8;
        loop8 = var1.word.b8;
    }
    while (!foot8) {
    }

    //loop//
    if (!foot9) {
        
       var1.word.b9= ~var1.word.b9;
       loop9 = var1.word.b9;
    }
    while (!foot9) {
    }

    //loop//
    if (!foot0) {
        
        var1.word.b0= ~var1.word.b0;
        loop0 = var1.word.b0;
    }
    while (!foot0) {
    }
    
    auxconfig=var1.word_t;
    
   
  
    
}

/*      */
void liveMode(){
    
}

/*             */
void configMode(){
            
    
    auxconfig = var1.word_t;
    
    presets[0][0]=auxconfig;   
}

/*     */
void muteMode(){
    
}