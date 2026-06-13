/**
 * The function return keycode depends on the button state
 * @param : none
 * @return : [1,16]
 * @condition : call Keypad_init() before
 * */
char Read_keypad();
// Value returns
// 0-1-2-3-4-5-6-7-8-9 : number key
// 10 - 11 - 12 - 13 : A - B - C - D key
// 14 : * Key
// 15 : # Key
// 16 : no key press
// Note: Using portd

/**
 * Init for keypad function
 * Setup : DDRB and PORTB
 * */
void Keypad_init(void);
