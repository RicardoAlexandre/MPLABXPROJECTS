#ifndef PINMANAGER_H
#define	PINMANAGER_H

//Foots
#define foot1 PORTAbits.RA0
#define foot2 PORTAbits.RA1
#define foot3 PORTAbits.RA2
#define foot4 PORTAbits.RA3
#define foot5 PORTAbits.RA4
#define foot6 PORTAbits.RA5
#define foot7 PORTBbits.RB2
#define foot8 PORTBbits.RB3
#define foot9 PORTCbits.RC0
#define foot0 PORTCbits.RC1

#define footup   PORTCbits.RC2
//#define footdown PORTEbits.RE3


//Loop de pedais
#define  loop1 LATDbits.LATD0
#define  loop2 LATDbits.LATD1
#define  loop3 LATDbits.LATD2
#define  loop4 LATDbits.LATD3
#define  loop5 LATDbits.LATD4
#define  loop6 LATDbits.LATD5
#define  loop7 LATDbits.LATD6
#define  loop8 LATDbits.LATD7
#define  loop9 LATEbits.LATE0
#define  loop0 LATEbits.LATE1


//External switchs
#define  esw1 LATEbits.LATE2
#define  esw2 LATBbits.LATB4        
#define  esw3 LATBbits.LATB5
#define  esw4 LATBbits.LATB6
#define  esw5 LATBbits.LATB7




#endif	/* XC_HEADER_TEMPLATE_H */

