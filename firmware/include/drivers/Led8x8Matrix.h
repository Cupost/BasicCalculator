/* *
 * depends on keycode, this function will change operator on the the **matrix
 * led**
 * @param:
 * keycode : [10,13]
 * */
char Led_matrix_out(char keycode);
// Value input | output
// 10 | +
// 11 | -
// 12 | x
// 13 | /

/* *
 * Send data you want to matrix led, but this do not change
 * the operator you want, only use this to send command
 * @param:
 * addr : address of memory address
 * data : sen 8bit data you want, this should be command
 * */
void Matrix_send(unsigned char addr, unsigned char data);

/* *
 * Init for matrix led
 * @setup :
 * - turn off BCD MODE
 * - set brightness
 * - turn off TEST MODE
 * - wake up IC from SHUTDOWN MODE
 * - clear dump data
 * */
void Led_matrix_init(void);
