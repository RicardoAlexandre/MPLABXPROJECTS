/******************************************************************************
 * Hardware I2C single master routines for PIC16F887 to PCF8574A LCD
 * MPLAB XC8 COMPILER.
 *
 * by Hal Albach
 * 
 * created  01/15/2016
 * 
 * modified 02/03/2016
 * 
******************************************************************************/

// Global variables
uint8_t RS = 0;       // select lcd command register

#define POWER_UP_DELAY  50
#define NIBBLE          4
#define INIT_DELAY_5    5
#define ACQ_DELAY       5
#define INIT_DELAY_2    2
#define FOUR_BIT        0x20
#define FOUR_MORE       0x28
#define CURSOR          0x0C
#define INC_CURSOR      6
#define NULL            0x00
#define EN_OFF          0b11111110
#define ACK             0
#define LCD_CMD         0
#define OFF             0
#define ON              1
#define LCD_DATA        1
#define EN_ON           0b00000001
#define NACK            1
#define START_BIT       1
#define ALL_HI          0xFF
#define RC34            0x18
#define MASTER          0x38
#define BUS100          0x31
#define ADC80           0x80
#define ADC81           0x81
#define MAX_BUF         10
#define SAMPLES         30
#define UPPER           0xF0
#define I2C_ADR         0x70
#define SEC_2           2000
#define SEC_3           3000
#define SSPCON2_MASK    0x1F
#define SET_8_BIT       0x30
#define LCD_DELAY       1.64
#define LCD_CLR         0b00000001
#define LCD_HOME        0b00000011

#define RS_TRAP         '\v'        // used to signal that RS needs to be set 
                                    // to command mode for following command
#define CLS             "\v\x01"    // Clear Screen
#define LINE2           "\v\xC0"    // Line 2 Col 1
#define LINE2_13        "\v\xCD"    // Line 2 Col 13


// Prototypes
void write_lcd(uint8_t data);
void init();
void i2c_start();
void i2c_stop();
void lcd_write_byte(uint8_t byte);
void lcd_init();
void start(void);
void test_adc(void);
void strobe(uint8_t cmd);
void is_I2C_idle(void);
void putch(uint8_t byte);
void banners(void);




