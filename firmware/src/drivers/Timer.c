#include <avr/io.h>

void delay_us(char us) {
  // 1. Cài đặt Timer 0 ở chế độ CTC (WGM01 = 1, WGM00 = 0)
  TCCR0A = (1 << WGM01);
  // 2. Cài đặt giá trị so sánh (Compare Match Value)
  OCR0A = 15;
  // 3. Khởi động Timer với Prescaler = 1 (CS00 = 1)
  TCCR0B = (1 << CS00);
  while (us > 0) {
    // Xóa cờ báo ngắt OCF0A bằng cách ghi bit '1' vào nó
    TIFR0 = (1 << OCF0A);
    // Chờ cho đến khi cờ OCF0A được bật (Timer đếm đến OCR0A)
    while ((TIFR0 & (1 << OCF0A)) == 0)
      ;
    us--; // Giảm số microgiây còn lại
  }

  // 4. Dừng Timer 0 sau khi hoàn thành delay
  TCCR0B = 0;
}
