
#ifndef HCM_H
#define	HCM_H

#define _XTAL_FREQ  20000000



void systemInit(void);

void adcInit(void);

uint16_t readADC(uint8_t);

#endif	

