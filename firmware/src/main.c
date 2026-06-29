#include "Keypad.h"
#include "Led7Seg.h"
#include "Led8x8Matrix.h"
#include "SPI_protocol.h"
#include "TM1637_protocol.h"
#include "Timer.h"
#include <avr/io.h>

int16_t main() {
  // Setup
  SPI_MasterInit();       // Start up SPI protocol
  TM1637_protocol_init(); // Startup 2 wire protocol
  Keypad_init();          // Config port for Keypad
  Led_matrix_init();      // Initial value for Matrix
  Leg7Seg_init();         // Initial value for Led7Seg

  // Initialize variable
  uint16_t num1, num2, numt;
  num1 = num2 = 0;
  numt = 10000;
  uint8_t keycode, ope;
  ope = 99;
  int8_t state = 0;

  // Start up main loop

  // FIXME:
  // Check keycode return value

  DDRC = 0b11111111;
  PORTC = 0;
  while (1) {
    //***************************
    do {
      keycode = Read_keypad(); // read keypad return keycode
    } while (keycode == 16); // no button is being pressed
    //***************************
    if (keycode < 16)
      PORTC = keycode;
    delay_ms(70); // Bounding button
  }
}
