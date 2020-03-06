 
#ifndef OPERATIONMODES_H
#define	OPERATIONMODES_H

#include "main.h"


/* Bit Operation macros */
#define set_bit(b,n)        ((b) |=   (1<<(n)))        /* Set bit number n in byte b   */
#define clear_bit(b,n)      ((b) &= (~(1<<(n))))       /* Clear bit number n in byte b */
#define read_bit(b,n)       ((b) &    (1<<(n)))        /* Read bit number n in byte b  */
#define toogle_bit(b,n)     ((b) ^=   (1<<(n)))        /* Flip bit number n in byte b  */
 
#define bit_is_set(b,n)     (b & (1<<n))                /* Test if bit number n in byte b is set   */
#define bit_is_clear(b,n)   (!(b & (1<<n)))             /* Test if bit number n in byte b is clear */


extern  uint16_t presets[10][10];

extern  uint16_t dip16;

///////Change Banks/////
void changeBankUP(void);

void changeBankDOWN(void);

//////Set outputs///////////////
void setLoops(uint16_t preset);

/////////////////Active output direct from foot switch////////////////
void directMode(void);

void liveMode(void);

void configMode(void);

void muteMode(void);


#endif	/* XC_HEADER_TEMPLATE_H */

