#include <avr/io.h>
#define Fosc 16000000
void init() {
  // Config  PORTD for Keypad
  DDRD = 0b11110000;
  // Config PORTC for Led7Seg TM1637
  DDRC = 0b00001111;
  PORTC = 0b00001111;
}
