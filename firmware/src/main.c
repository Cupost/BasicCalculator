#include "Keypad.h"
#include "Led7Seg.h"
#include "Led8x8Matrix.h"
#include "SPI_protocol.h"
#include "TM1637_protocol.h"
#include "Timer.h"
#include <avr/io.h>

int main() {
  // Setup
  SPI_MasterInit();       // Start up SPI protocol
  TM1637_protocol_init(); // Startup 2 wire protocol
  Keypad_init();          // config port for Keypad
  Led_matrix_init();      // Initial value for Matrix
  Leg7Seg_init();         // Initial value for Led7Seg

  // Initialize variable
  unsigned int num1, num2, numt;
  num1 = num2 = 0;
  numt = 10000;
  char keycode, ope;
  ope = 99;
  char state = 0;
  // Start up main loop
  while (1) {
    //***************************
    do {
      keycode = Read_keypad(); // read keypad return keycode
    } while (keycode == 16); // no button is being pressed
    //***************************

    switch (keycode) {

    case 15:
      /* begin state is 0. when in this case, state will change from 0 to 1
       * again and again
       * */
      state = !state;
      break;

    case 14: // *
      /* begin ope = 99, so if no ope button being pressed before, numt will not
       * change and that make led_out errol message
       * */
      switch (ope) {
      case 13:
        numt = num1 / num2;
        break;
      case 12:
        numt = num1 * num2;
        break;
      case 11:
        numt = num1 - num2;
        break;
      case 10:
        numt = num1 + num2;
        break;
      }
      Led_out(numt, 2); // Led out result
      break;

    case 13: // D key
      Led_matrix_out(13);
      ope = 13;
      break;

    case 12: // C key
      Led_matrix_out(12);
      ope = 12;
      break;

    case 11: // B key
      Led_matrix_out(11);
      ope = 11;
      break;

    case 10: // A key
      Led_matrix_out(10);
      ope = 10;
      break;
    }

    // End switch case

    // If keycode is number from 0 to 9
    if (keycode >= 0 && keycode <= 9) {
      if (state == 0) {
        num1 = (num1 % 1000) * 10 + keycode; // Num1 update
        Led_out(num1, 0);
      }
      if (state == 1) {
        num2 = (num2 % 1000) * 10 + keycode; // Num2 update
        Led_out(num2, 1);
      }
    }
    delay_ms(70); // Bounding button
  }
}
