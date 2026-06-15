#include <stdint.h>
/* *
 * Transmit data to Led module depends on state variable
 * @param:
 * **number**: data to transmit
 * **state** : choose which module led is out
 * @return:
 * 1 = transmit completed
 * 0 = transmit uncompleted
 * */
int8_t Led_out(uint16_t number, int8_t state);
// State = 0 : Led num 1
// State = 1 : Led num 2
// State = 2 : Led result 3

/* *
 * Init for Led 7 segment module
 * @setup: turn on display, wake up IC from sleep mode
 * clear dump data, start with clear data
 * */
void Leg7Seg_init(void);
