#include "TM1637_protocol.c"
#include <avr/io.h>

/*Print out display number
 * state : choose DIOx pin
 * */
char Led_out(unsigned int number, char state) {
  unsigned char element[4];
  element[0] = number % 10;
  number /= 10;
  element[1] = number % 10;
  number /= 10;
  element[2] = number % 10;
  number /= 10;
  element[3] = number % 10;
  number /= 10;
  const unsigned char SEGMENT_MAP[] = {
      0x3F, // 0
      0x06, // 1
      0x5B, // 2
      0x4F, // 3
      0x66, // 4
      0x6D, // 5
      0x7D, // 6
      0x07, // 7
      0x7F, // 8
      0x6F  // 9
  };
  Start_condition(state);
  Data_transmit(0b11000000, state); // Address C0H first
  for (unsigned char i = 0; i < 4; i++)
    Data_transmit(SEGMENT_MAP[element[i]], state); // Sen data number
  Stop_condition(state);

  return 1;
}

/* Initiation for Led7Seg, with all 3 IC TM1637
 * */
void Leg7Seg_init(void) {

  for (int i = 0; i < 3; i++) {

    Start_condition(i);
    Data_transmit(0b01000000, i); // Data write mode setting
    Stop_condition(i);

    Start_condition(i);
    Data_transmit(0b11000000, i); // Address C0H first
    for (char j = 0; j < 6; j++)
      Data_transmit(0b00000000, i); // Clear dump data in IC
    Stop_condition(i);

    Start_condition(i);
    Data_transmit(0b10001000, i); // Display on command
    Stop_condition(i);
  }
}
