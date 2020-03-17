  
#ifndef ROTATORYENCODER_H
#define	ROTATORYENCODER_H

#define  enc_A   PORTBbits.RB0
#define  enc_B   PORTBbits.RB1

#include "hcm.h"

int enc_count;


void readEncoder();


#endif	/* XC_HEADER_TEMPLATE_H */

