#ifndef __SHIFTY_DRIVER__
#define __SHIFTY_DRIVER__


#define NUM_SHIFT_REGS 2

//0 and 1 ommited as they are reserved for serial communication.
#define PIN_2 (B00000100)
#define PIN_3 (B00001000)
#define PIN_4 (B00010000)
#define PIN_5 (B00100000)
#define PIN_6 (B01000000)
#define PIN_7 (B10000000)
#define SET_PINS_0_7(bits) (PORTD = PORTD | (bits & B11111100))
#define CLEAR_PINS_0_7(bits) (PORTD = PORTD & ~(bits & B11111100))
#define GET_PINS_0_7 PIND

//6 and 7 ommited as they are reserved the crystal oscillator.
#define PIN_0 (B00000001)
#define PIN_1 (B00000010)
#define PIN_2 (B00000100)
#define PIN_3 (B00001000)
#define PIN_4 (B00010000)
#define PIN_5 (B00100000)
#define SET_PINS_8_13(bits) (PORTB = PORTB | (bits & B00111111))
#define CLEAR_PINS_8_13(bits) (PORTB = PORTB & ~(bits & B00111111))
#define GET_PINS_8_13 PINB

//Output enable (active low)
#define OE_PIN_NUM 6
#define OE PIN_6

//Shift register clock
#define SRCLK_PIN_NUM 3
#define SRCLK PIN_3

//Storage Register Clock
#define STORCLK_PIN_NUM 4
#define STORCLK PIN_4

//Master Reset
#define MR_PIN_NUM 5
#define MR PIN_5

//Serial out
#define SEROUT_PIN_NUM 2
#define SEROUT PIN_2


typedef unsigned char uint8;
typedef signed char int8;
typedef unsigned int uint16;
typedef int int16;
typedef unsigned long int uint32;
typedef long int int32;


#endif
