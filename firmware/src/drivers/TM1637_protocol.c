#include "drivers/Timer.h"
#include <avr/io.h>
#define CLK_ON PORTC |= (1 << 3)
#define CLK_OFF PORTC &= (~(1 << 3))
#define DIO_ON PORTC |= (1 << state)
#define DIO_OFF PORTC &= (~(1 << state))

/* From begin:
 * CLK is driving high
 * DIO is driving high
 * We have 3 different DIO pin
 * */
void Start_condition(char state) {
  DIO_ON;
  delay_us(5);
  CLK_ON;
  delay_us(5);
  DIO_OFF;
}
/* After Start_condition:
 * CLK is driving high
 * DIO is driving low
 * */

char Data_transmit(char data, char state) {
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
    delay_us(5);
  }

  // Read bit 9 ACK
  CLK_OFF;
  delay_us(5);
  DIO_ON;
  DDRC = DDRC & (~(1 << state)); // set DIO Input
  delay_us(5);
  CLK_ON;

  if (PINC & (1 << state)) {
    CLK_OFF;
    delay_us(5);
    DDRC = DDRC | (1 << state); // set DIO Output
    return 0;                   // NACK
  } else {
    CLK_OFF;
    delay_us(5);
    DDRC = DDRC | (1 << state); // set DIO Output
    return 1;                   // ACK
  }
}

void Stop_condition(char state) {
  CLK_OFF;
  delay_us(5);
  DIO_OFF;
  delay_us(5);
  CLK_ON;
  delay_us(5);
  DIO_ON;
}
