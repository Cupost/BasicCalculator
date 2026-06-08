#include <avr/io.h>

char Read_keypad() {
  PORTD = 0b01111111;
  char a = (~PIND) & 0x0F;
  switch (a) {
  case 1: // key = A
    return 10;
  case 2: // 3
    return 3;
  case 4: // 2
    return 2;
  case 8: // 1
    return 1;
  }
  PORTD = 0b10111111;
  a = (~PIND) & 0x0F;

  switch (a) {
  case 1: // key = B
    return 11;
  case 2: // 6
    return 6;
  case 4: // 5
    return 5;
  case 8: // 4
    return 4;
  }
  PORTD = 0b11011111;
  a = (~PIND) & 0x0F;

  switch (a) {
  case 1: // key = C
    return 12;
  case 2: // 9
    return 9;
  case 4: // 8
    return 8;
  case 8: // 7
    return 7;
  }
  PORTD = 0b11101111;
  a = (~PIND) & 0x0F;
  switch (a) {
  case 1: // key = D
    return 13;
  case 2: // key = #
    return 15;
  case 4: // 0
    return 0;
  case 8: // key = *
    return 14;
  }

  return 16;
}

// R1-R2-R3-R4-C1-C2-C3-C4

void Keypad_init(void) {
  // Set
  DDRD = 0b11110000;
}
