#include "drivers/Timer.h"
#include <avr/io.h>
#define CLK_ON PORTC = PORTC | (1 << 3)
#define CLK_OFF PORTC = PORTC & (~(1 << 3))
#define DIO_ON PORTC = PORTC | (1 << state)
#define DIO_OFF PORTC = PORTC & (~(1 << state))
// CLK and DIO at begin is high
void Start_condition(char state) {
  CLK_ON;
  delay_us(5);
  DIO_OFF;
}
void Stop_condition(char state) {
  CLK_ON;
  delay_us(5);
  DIO_ON;
}

// The function help to send data into device depend on state value
// Don't have the START and STOP condition, main will decide that.
char Data_trans(char data, char state) {
  char bit;
  // Send 8 bit data
  for (int i = 0; i <= 7; i++) {
    bit = (data >> i) & 1;
    CLK_OFF;
    delay_us(5);
    if (bit) {
      DIO_ON;
    } else
      DIO_OFF;
    delay_us(5);
    CLK_ON;
  }
  // Read bit 9 ACK
  CLK_OFF;
  delay_us(5);
  DDRC = DDRC & (~(1 << state)); // set DIO Input ???
  delay_us(5);
  CLK_ON;
  if (PINC & (1 << state)) {
    CLK_OFF;
    delay_us(5);
    DDRC = DDRC | (1 << state); // set DIO Output
    return 0;                   // NACK
  } else {
    delay_us(5);
    DDRC = DDRC | (1 << state); // set DIO Output
    return 1;                   // ACK
  }
}
