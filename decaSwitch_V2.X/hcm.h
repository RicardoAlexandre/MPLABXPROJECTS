  
#ifndef HCM_H
#define	HCM_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <p18f4550.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "operationModes.h"

#define _XTAL_FREQ  20000000

extern int i;

extern uint16_t presets[10][10];

void systemInit(void);

#endif	/* XC_HEADER_TEMPLATE_H */

