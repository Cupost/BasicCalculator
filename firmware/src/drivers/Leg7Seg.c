#include "TM1637_protocol.c"
#include <avr/io.h>

// FIXME:
// char Led_out(unsigned int number, char state) {}

void Leg7Seg_init(void) {
  // Set PC0:PC3 output
  DDRC = 0b00001111;
  // Set CLK, DIO drive high at begin
  PORTC = 0b00001111;
}
