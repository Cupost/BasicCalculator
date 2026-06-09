// The function that show operator base on keycode input using SPI protocol
char Led_matrix_out(char keycode);
// Value input | output
// 10 | +
// 11 | -
// 12 | x
// 13 | /

void Matrix_send(unsigned char addr, unsigned char data);

void Led_matrix_init(void);
