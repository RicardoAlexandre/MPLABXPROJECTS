 /*=========================================================================
  * I2Clcd.X
  * I2C LCD project
  * 
  * MPLAB X v3.20
  * 
  * XC8 COMPILER v1.36
  * 
  * PIC16F887 on a 44-Pin Demo Board
  * 
  * by  Hal Albach
  * 
  * Modified 02/03/2016
  * 
  * This program uses the hardware I2C on the 44-Pin Demo Board with a
  * PIC16F887 to write to a PCF8574A controlled 2x32 LCD, no backlight.
  * 8-bit I2C Address for the -A version is 0x70.
  * 
  * Displays some text, then uses the ADC and onboard RP1 to generate values 
  * displayed on LCD.
  * 
  * Cut a small perfboard to just fit the PCF8574A and a 2x7 DIL socket for 
  * the LCD and wired as indicated below.
  *  
  *         Connections:
  * 
  * PCF8574A              PCF8574A
  *   1 Gnd                 16 +5
  *   2 Gnd                 15 SDA to PIC RC4 & 3.3K pullup
  *   3 Gnd                 14 SCL to PIC RC3 & 3.3K pullup
  *   4 P0 to LCD 6 EN      13 n/c
  *   5 P1 to LCD 4 RS      12 P7  to LCD 14 DB7
  *   6 P2 to LCD 5 RW      11 P6  to LCD 13 DB6
  *   7 P3 n/c              10 P5  to LCD 12 DB5
  *   8 Gnd                 09 P4  to LCD 11 DB4
  * 
  
/***************************************************************************/

// First, some housekeeping...
// CONFIG1
#pragma config FOSC = HS        // Crystal/resonator on RA6/RA7  
#pragma config WDTE = OFF       // Watchdog Timer disabled 
#pragma config PWRTE = ON       // Power-up Timer Enabled
#pragma config MCLRE = OFF      // RE3/MCLR pin function is Digital
#pragma config CP = OFF         // Code Protection bit disabled
#pragma config CPD = OFF        // Data Code Protection disabled
#pragma config BOREN = ON       // Brown Out Reset bit (BOR enabled)*/
#pragma config IESO = ON        // Internal External Switchover enabled
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled
#pragma config LVP = ON         // Low Voltage Programming Enabled
// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset set to 4.0V
#pragma config WRT = OFF        // Flash Program Memory Self Write disabled

#define _XTAL_FREQ 20000000     // Fosc  frequency for _delay()  library

#include <stdint.h>             // for standard definitions
#include <xc.h>
#include "i2c887LCD.h"
#include <stdio.h>              // for printf



/****************************************************************************/

void main(void)
{
  init();
  start();        // send start condition and open PCF8574A 
  lcd_init();     // bring the LCD on line
  banners();
  test_adc();
  while(1);
}

/****************************************************************************/
//                  VERY IMPORTANT for proper I2C function
void is_I2C_idle(void)      
{
  while (( SSPCON2 & SSPCON2_MASK ) | R_W ); // wait for idle
}

/****************************************************************************/

void start(void)
{
  is_I2C_idle();
  SEN = START_BIT;
  is_I2C_idle();
  SSPBUF = I2C_ADR;        // address PCF8574A I2C port expander
}

/****************************************************************************/
// * This function actually initiates I2C write sequence. Also added NACK error
// * checking which will repeat the nacked transmission until an ACK is rec'd.
// * TO DO: Add a time out counter to abort in case I2C bus becomes locked.

void write_lcd(uint8_t data)
{
  uint8_t ackflag = NACK;
  while(ackflag)
  {
    is_I2C_idle();
    SSPIF = OFF;        // clear MSSP Interrupt Flag
    SSPBUF = data;      // send a char out on bus
    while(!SSPIF);      // goes high after 9th bit time, after ACK bit
    ackflag = ACK;
    if(ACKSTAT) ackflag = NACK; //* if ACTSTAT == 1 (nak) repeat loop
  }
}

/****************************************************************************/

void lcd_write_byte(uint8_t lcd_dat)
{
  uint8_t shadow;                   // the world famous "Shadow" register
    
  shadow = (lcd_dat & UPPER);        // EN, RS, RW = 0 0 0
  if(RS) shadow |= 0b00000010;    // skip if cmd, select lcd data register
  write_lcd(shadow);
  strobe(shadow);
// - - - - - - - - - - - - - 
  shadow = (lcd_dat << NIBBLE);      // EN, RS, RW = 0 0 0 by left shift fill
  if(RS) shadow |= 0b00000010;    // skip if cmd, select lcd data register
  write_lcd(shadow);
  strobe(shadow);
}

/****************************************************************************/
//      used by printf() function to print to LCD
// Uses ASCII control code VT (0x0B) #defined as 'v' to indicate that an LCD
// control code follows and RS must be set to CMD mode (0) for the next byte

void putch(uint8_t lcd_dat)
{
  if(lcd_dat == RS_TRAP)
  {
    RS = LCD_CMD;
    return;               // ends the \v sequence
  }
  lcd_write_byte(lcd_dat);
  if(!RS)
  {
    if ((lcd_dat >= LCD_CLR) && (lcd_dat <= LCD_HOME))
    __delay_ms(LCD_DELAY);
  }
  RS = LCD_DATA;
}

/****************************************************************************/
//                    Wiggle the E line
void strobe(uint8_t cmd)      // shadow --> cmd
{
  cmd |= EN_ON;             // EN 0000_0001
  write_lcd(cmd);           // send modified shadow to LCD
  cmd &= EN_OFF;            // EN 0b11111110
  write_lcd(cmd);           // send restored shadow to LCD
  PORTD = cmd;              // show activity ( for glitz))
}

/****************************************************************************/
//                          ADC module
void test_adc(void)
{
  uint16_t result = NULL;
  uint16_t result_avg = NULL;
  uint8_t i, j, buf[MAX_BUF];
    
  printf( CLS "Turn the dial...");
  printf( LINE2 "ADC value = ");
  while(1)
  {
    result_avg = NULL;
    for(i = 0; i < SAMPLES; i++)        // get 30 samples
    {
      __delay_ms(ACQ_DELAY);            // Acquisition delay 5ms
      GO = ON;                          // Start conversion
      while(GO);                        // wait for conversion to complete
      result = (ADRESH << 8) + ADRESL;
      result_avg += result;
    }
      printf( LINE2_13 "%4d    ", result_avg / SAMPLES);
  }
}

/****************************************************************************/
//              Bring the LCD to life in 4-bit mode
void lcd_init(void)
{
  uint8_t shadow = SET_8_BIT;   // 0b0011_0000
    
  write_lcd(shadow);          // data = 3, EN & RS lo  to PCF8574 --> LCD
  __delay_ms(POWER_UP_DELAY);

  strobe(shadow);             // toggle EN line   latch PCF8574 output into LCD
  __delay_ms(INIT_DELAY_5);

  strobe(shadow);             // toggle EN line   latch PCF8574 output into LCD
  __delay_ms(INIT_DELAY_2);

  strobe(shadow);             // toggle EN line   latch PCF8574 output into LCD
  __delay_ms(INIT_DELAY_2);
    
  shadow = FOUR_BIT;          // 0b0010_0000  4 bit data bus 
  write_lcd(shadow);          // data = 2, EN & RS lo  to PCF8574 --> LCD 
  strobe(shadow);             // toggle EN line   latch PCF8574 output into LCD
    
  lcd_write_byte(FOUR_MORE);  // 0b0010_1000  set 4 bit IF, move cursor
  lcd_write_byte(CURSOR);     // 0b0000_1100  display ON, Cursor ON, no blink
  lcd_write_byte(INC_CURSOR); // 0b0000_0110  Cursor increments, no shift
}

/****************************************************************************/

void init(void)
{
  // Make all unused ports output and set to 0. Makes things more stable.
    
  PORTA = TRISB = ANSELH = PORTC = PORTE = SSPCON2 = PORTD = TRISD = NULL;
  TRISA = ANSEL = 1;  // Only RA0 is Analog Input
  PORTB =   ALL_HI;
  TRISC =   RC34;     // RC3 & RC4 assigned to i2c
  SSPCON =  MASTER;   // set I2C master mode
  SSPADD =  BUS100;   // 100kHz i2c bus with 20MHz xtal
  CKE = ON;           // use I2C levels
  SMP = ON;           // disable slew rate control
  SSPIF = OFF;        // clear SSPIF interrupt flag
  BCLIF = OFF;        // clear bus collision flag
    
  // Set up ADC for reading RP1 on 44 Pin Demo board
  ADCON1 = ADC80;     // right justify & internal Vref
  ADCON0 = ADC81;     // FOSC/32, chan 0, ADC on
}

/****************************************************************************/

void banners(void)
{
  printf( CLS "Mister Hal sez: Hello, World!!");
  printf( LINE2 "Have a very Happy New Year!");
  __delay_ms(SEC_2);
  
  printf( CLS "  Do not look into Laser with");
  printf( LINE2 "      remaining good eye");
  __delay_ms(SEC_3);
}

/****************************************************************************/

