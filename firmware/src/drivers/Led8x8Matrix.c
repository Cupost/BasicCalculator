#include "SPI_protocol.h"
#include <avr/io.h>
#define CS_ON PORTB |= (1 << PB2)
#define CS_OFF PORTB &= ~(1 << PB2)

uint8_t ADD[8] = {
    0b00011000, // 1:    **
    0b00011000, // 2:    **
    0b00011000, // 3:    **
    0b11111111, // 4: ********
    0b11111111, // 5: ********
    0b00011000, // 6:    **
    0b00011000, // 7:    **
    0b00011000  // 8:    **
};
uint8_t SUB[8] = {
    0b00000000, // 1
    0b00000000, // 2
    0b00000000, // 3
    0b11111111, // 4: ********
    0b11111111, // 5: ********
    0b00000000, // 6
    0b00000000, // 7
    0b00000000  // 8
};
uint8_t MUL[8] = {
    0b11000011, // 1: **    **
    0b01100110, // 2:  **  **
    0b00111100, // 3:   ****
    0b00011000, // 4:    **
    0b00011000, // 5:    **
    0b00111100, // 6:   ****
    0b01100110, // 7:  **  **
    0b11000011  // 8: **    **
};
uint8_t DIV[8] = {
    0b00011000, // 1:    **
    0b00011000, // 2:    **
    0b00000000, // 3
    0b11111111, // 4: ********
    0b11111111, // 5: ********
    0b00000000, // 6
    0b00011000, // 7:    **
    0b00011000  // 8:    **
};

void Matrix_send(uint8_t addr, uint8_t data) {
  CS_OFF;
  SPI_MasterTransmit(addr);
  SPI_MasterTransmit(data);
  CS_ON;
}

void Led_matrix_init(void) {
  // 1. Turn of BCD mode
  Matrix_send(0x09, 0x00);

  // 2. Setting brightness
  Matrix_send(0x0A, 0x07); // Medium brightness

  // 3. Turn on all 8 row
  Matrix_send(0x0B, 0x07);

  // 4. Turn off display TestMode ( All led turn on in TestMode)
  Matrix_send(0x0F, 0x00); // 0 = Normal mode

  // Turn off Shutdown mode
  Matrix_send(0x0C, 0x01); // 1 = Normal operation

  // 6. Clear start garbage memory && Turn off all led at begin
  // Note: start register is 1 not 0, from 1 -> 8
  for (uint8_t row = 1; row <= 8; row++) {
    Matrix_send(row, 0x00); // Send 0x00 data byte
  }
}

int8_t Led_matrix_out(int8_t keycode) {
  switch (keycode) {
  case 10:
    for (uint8_t row = 1; row <= 8; row++) {
      Matrix_send(row, ADD[row - 1]); // + operation
    }
    break;
  case 11:
    for (uint8_t row = 1; row <= 8; row++) {
      Matrix_send(row, SUB[row - 1]); // - operation
    }
    break;
  case 12:
    for (uint8_t row = 1; row <= 8; row++) {
      Matrix_send(row, MUL[row - 1]); // * operation
    }
    break;
  case 13:
    for (uint8_t row = 1; row <= 8; row++) {
      Matrix_send(row, DIV[row - 1]); // / operation
    }
    break;
  }
  return 1;
}
