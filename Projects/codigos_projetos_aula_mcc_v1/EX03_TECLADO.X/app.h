/* 
 * File:   app.h
 * Author: Microgenios
 *
 * Created on 30 de Janeiro de 2016, 11:05
 */

#ifndef APP_H
#define	APP_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "main.h"
#include "delay.h"
    
void app(void); 
void UART_Received(uint8_t rec);
void processar();

#ifdef	__cplusplus
}
#endif

#endif	/* APP_H */

