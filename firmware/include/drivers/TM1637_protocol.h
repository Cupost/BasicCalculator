#include <stdint.h>
/* *
 * Init for 2 wire protocol, should be call first before use any function
 * in this header file
 * @setup : Set output for CLK pin && DIO pin
 * */
void TM1637_protocol_init(void);

/* *
 * Data transmit for 2 wire protocol
 * @param :
 * - data : data you want to transmit
 * - state: for this project, choose which IC to transmit
 * @condition :
 * - Call Start_condition() to start transmit
 * */
int8_t Data_transmit(int8_t data, int8_t state);

/* *
 * Signal the IC that a data transmission is imminent
 * should be call before use Data_transmit function
 * */
void Start_condition(int8_t state);

/* *
 * Signal the IC that the transmission is completed
 * @param : state to choose which IC to transmit
 * */
void Stop_condition(int8_t state);
