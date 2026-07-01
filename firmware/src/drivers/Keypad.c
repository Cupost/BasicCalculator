#include <avr/io.h>
#include <stdint.h>

uint8_t Read_keypad() {
  uint8_t a;
  PORTD = 0b11111110;
  __asm__ __volatile__("nop");
  __asm__ __volatile__("nop");
  a = (~PIND & 0xF0) >> 4;
  switch (a) {
  case 1: // key = D
    return 13;
  case 2: // key = C
    return 12;
  case 4: // key = B
    return 11;
  case 8: // key = A
    return 10;
  }

  PORTD = 0b11111101;
  __asm__ __volatile__("nop");
  __asm__ __volatile__("nop");
  a = (~PIND & 0xF0) >> 4;
  switch (a) {
  case 1: // key = #
    return 15;
  case 2: // 9
    return 9;
  case 4: // 6
    return 6;
  case 8: // 3
    return 3;
  }
  PORTD = 0b11111011;
  __asm__ __volatile__("nop");
  __asm__ __volatile__("nop");
  a = (~PIND & 0xF0) >> 4;

  switch (a) {
  case 1: // 0
    return 0;
  case 2: // 8
    return 8;
  case 4: // 5
    return 5;
  case 8: // 2
    return 2;
  }

  PORTD = 0b11110111;
  __asm__ __volatile__("nop");
  __asm__ __volatile__("nop");
  a = (~PIND & 0xF0) >> 4;
  switch (a) {
  case 1: // key = *
    return 14;
  case 2: // 7
    return 7;
  case 4: // 4
    return 4;
  case 8: // 1
    return 1;
  }
  return 16;
}

// R1-R2-R3-R4-C1-C2-C3-C4

void Keypad_init(void) {
  // Set
  DDRD = 0b00001111;
}
