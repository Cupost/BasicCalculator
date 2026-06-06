#include <avr/io.h>

char Read_keypad() {
  PORTD = 0b10000000;
  char a = PIND & 0x0F;
  switch (a) {}
  return 0;
}
