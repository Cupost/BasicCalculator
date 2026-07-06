#include <avr/io.h>
// Delay with us parameter
void delay_us(uint8_t us) {
  // 1. Timer0 CTC Mode (WGM01 = 1, WGM00 = 0)
  TCCR0A = (1 << WGM01);
  // 2. (Compare Match Value)
  OCR0A = 15;
  // 3. (CS00 = 1)
  TCCR0B = (1 << CS00);
  while (us > 0) {
    // Clear interrupt flag bit by write 1 to it
    TIFR0 = (1 << OCF0A);
    // Wait for flag
    while ((TIFR0 & (1 << OCF0A)) == 0)
      ;
    us--;
  }

  // Turn off timer
  TCCR0B = 0;
}
// Delay with ms parameter
void delay_ms(uint8_t ms) {
  TCNT0 = 0;   // Start count value for timer
  OCR0A = 249; // Compare Value set

  TCCR0A = (1 << WGM01); // Turn on CTC mode
  TCCR0B = (1 << CS01);  // Set prescale
  TCCR0B |= (1 << CS00); // Enable timer
  while (ms) {
    TIFR0 |= (1 << OCF0A); // clear flag
    while ((TIFR0 & (1 << OCF0A)) == 0) {
      // Wait for flag
    }
    ms--;
  }
  TCCR0B = 0; // Turn off timer
}
