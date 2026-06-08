#include <avr/io.h>

void Leg7Seg_init(void) {
  // Set PC0:PC3 output
  DDRC = 0b00001111;
  // Set CLK, DIO drive high at begin
  PORTC = 0b00001111;
}
