#include "Keypad.h"
#include "Led7Seg.h"
#include "Led8x8Matrix.h"
#include "SPI_protocol.h"
#include "TM1637_protocol.h"
#include "Timer.h"
#include <avr/io.h>

int main() {
  // Setup
  SPI_MasterInit();
  TM1637_protocol_init();
  Keypad_init();
  Led_matrix_init();
  Leg7Seg_init();
  // Variable
  unsigned int num1, num2, numt;
  num1 = num2 = numt = 0;
  char keycode;
  char state = 0;
  char check = -3;

  /*BUG:
   * What if:
   *  press * key first ?
   *  press 1 key long ?
   *  don't have start value ?
   *
   * */

  while (1) {
    do {
      keycode = Read_keypad(); // read keypad return keycode
    } while (keycode == 16);

    switch (keycode) {
    case 15:          // #
      state = !state; // Change led out
      break;
    case 14: // *
      if (check >= 0) {
        Led_out(numt, 2);
      } // Led out result

    /*FIXME:
     * [] Not have any command create numt value
     * [] Not have lock feature after led_out( numt, 2)
     * [] Not have operator update
     * */
    case 13: // D key
      Led_matrix_out(13);
      break;
    case 12: // C key
      Led_matrix_out(12);
      break;
    case 11: // B key
      Led_matrix_out(11);
      break;
    case 10: // A key
      Led_matrix_out(10);
      break;
    }

    if (keycode >= 0 && keycode <= 9) {
      if (state == 0)
        num1 = (num1 % 1000) * 10 + keycode;
      if (state == 1)
        num2 = (num2 % 1000) * 10 + keycode;
    }
  }
}
