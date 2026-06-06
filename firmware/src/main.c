#include <avr/io.h>

void init() {
  // Port config
  DDRD = 0b11110000;
}
