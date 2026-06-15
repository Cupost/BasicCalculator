#include "Timer.h"
#include <avr/io.h>
#define CLK_ON PORTC |= (1 << 3)
#define CLK_OFF PORTC &= (~(1 << 3))
#define DIO_ON PORTC |= (1 << state)
#define DIO_OFF PORTC &= (~(1 << state))

void TM1637_protocol_init(void) {
  // Set PC0:PC3 output
  DDRC |= 0b00001111;
  // Set CLK, DIO drive high at begin
  PORTC |= 0b00001111;
}
/* From begin:
 * CLK is driving high
 * DIO is driving high
 * We have 3 different DIO pin
 * */

/**
 * Create a signal start send data
 * state : Choose DIOx pin
 **/
void Start_condition(int8_t state) {
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

/*
 * Send 1 byte data to DIOx pin
 * @return 1 is success
 * @return 0 is fail
 * */
int8_t Data_transmit(int8_t data, int8_t state) {
  int8_t bit;
  // Send 8 bit data
  for (int16_t i = 0; i <= 7; i++) {
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
  delay_us(5);

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
/*After data transmit
 * CLK is driving low
 * DIO is driving hight
 * */

/*
 * Create stop signal, turn off transmit
 * state : Choose DIOx pin
 * */
void Stop_condition(int8_t state) {
  CLK_OFF;
  delay_us(5);
  DIO_OFF;
  delay_us(5);
  CLK_ON;
  delay_us(5);
  DIO_ON;
}
