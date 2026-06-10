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
// Hàm tạo trễ đúng 1 mili-giây bằng Timer0
void delay_ms(char ms) {
  TCNT0 = 0;   // Khởi tạo giá trị bộ đếm Timer0 bằng 0
  OCR0A = 249; // Đặt giá trị ngưỡng so sánh (Ngưỡng sinh ra 1ms)

  TCCR0A = (1 << WGM01); // Kích hoạt chế độ CTC (Reset timer khi đạt OCR0A)
  TCCR0B = (1 << CS01);  // Kích hoạt bộ chia tần (Prescaler) = 64
  TCCR0B |= (1 << CS00); // Cho phép timer chạy
  while (ms) {
    TIFR0 |= (1 << OCF0A); // Xóa cờ báo hiệu (Lưu ý: Với AVR, để xóa cờ ngắt ta
                           // phải ghi số 1 vào nó)
    // Vòng lặp chờ: Đứng đợi cho đến khi cờ OCF0A (Output Compare Flag 0 A)
    // được bật lên mức 1
    while ((TIFR0 & (1 << OCF0A)) == 0) {
      // Chờ đợi
    }
    ms--;
  }
  TCCR0B = 0; // Dừng timer để tiết kiệm năng lượng hoặc tránh đếm lố
}
