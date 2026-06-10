#include "SPI_protocol.h"
#include <avr/io.h>
#define CS_ON PORTB |= (1 << PB2)
#define CS_OFF PORTB &= ~(1 << PB2)

unsigned char ADD[8] = {
    0b00011000, // Hàng 1:    **
    0b00011000, // Hàng 2:    **
    0b00011000, // Hàng 3:    **
    0b11111111, // Hàng 4: ********
    0b11111111, // Hàng 5: ********
    0b00011000, // Hàng 6:    **
    0b00011000, // Hàng 7:    **
    0b00011000  // Hàng 8:    **
};
unsigned char SUB[8] = {
    0b00000000, // Hàng 1
    0b00000000, // Hàng 2
    0b00000000, // Hàng 3
    0b11111111, // Hàng 4: ********
    0b11111111, // Hàng 5: ********
    0b00000000, // Hàng 6
    0b00000000, // Hàng 7
    0b00000000  // Hàng 8
};
unsigned char MUL[8] = {
    0b11000011, // Hàng 1: **    **
    0b01100110, // Hàng 2:  **  **
    0b00111100, // Hàng 3:   ****
    0b00011000, // Hàng 4:    **
    0b00011000, // Hàng 5:    **
    0b00111100, // Hàng 6:   ****
    0b01100110, // Hàng 7:  **  **
    0b11000011  // Hàng 8: **    **
};
unsigned char DIV[8] = {
    0b00011000, // Hàng 1:    **
    0b00011000, // Hàng 2:    **
    0b00000000, // Hàng 3
    0b11111111, // Hàng 4: ********
    0b11111111, // Hàng 5: ********
    0b00000000, // Hàng 6
    0b00011000, // Hàng 7:    **
    0b00011000  // Hàng 8:    **
};

void Matrix_send(unsigned char addr, unsigned char data) {
  CS_ON;
  SPI_MasterTransmit(addr);
  SPI_MasterTransmit(data);
  CS_OFF;
}

void Led_matrix_init(void) {
  // 1. Tắt chế độ giải mã BCD (Dùng ma trận LED thì không cần giải mã 7 đoạn)
  Matrix_send(0x09, 0x00);

  // 2. Cài đặt độ sáng (Giá trị từ 0x00 đến 0x0F)
  Matrix_send(0x0A, 0x07); // Mức sáng trung bình

  // 3. Giới hạn quét (Quét toàn bộ 8 hàng)
  Matrix_send(0x0B, 0x07);

  // 4. Tắt chế độ kiểm tra màn hình (Test mode sẽ làm tất cả LED sáng rực)
  Matrix_send(0x0C, 0x00); // 0 = Chế độ hoạt động bình thường

  // 5. Bật IC (Thoát khỏi chế độ ngủ - Shutdown Mode)
  Matrix_send(0x0F, 0x01); // 1 = Normal operation

  // 6. Xóa rác khởi động: Tắt toàn bộ LED trên ma trận 8x8
  // Lưu ý: Thanh ghi dữ liệu của các hàng được đánh số từ 1 đến 8 (không phải
  // từ 0)
  for (unsigned char row = 1; row <= 8; row++) {
    Matrix_send(row, 0x00); // Gửi giá trị 0x00 (tắt hết 8 bit) vào từng hàng
  }
}

char Led_matrix_out(char keycode) {
  switch (keycode) {
  case 10:
    for (unsigned char row = 1; row <= 8; row++) {
      Matrix_send(
          row, ADD[row - 1]); // Gửi giá trị 0x00 (tắt hết 8 bit) vào từng hàng
    }
    break;
  case 11:
    for (unsigned char row = 1; row <= 8; row++) {
      Matrix_send(
          row, SUB[row - 1]); // Gửi giá trị 0x00 (tắt hết 8 bit) vào từng hàng
    }
    break;
  case 12:
    for (unsigned char row = 1; row <= 8; row++) {
      Matrix_send(
          row, MUL[row - 1]); // Gửi giá trị 0x00 (tắt hết 8 bit) vào từng hàng
    }
    break;
  case 13:
    for (unsigned char row = 1; row <= 8; row++) {
      Matrix_send(
          row, DIV[row - 1]); // Gửi giá trị 0x00 (tắt hết 8 bit) vào từng hàng
    }
    break;
  }
  return 1;
}
