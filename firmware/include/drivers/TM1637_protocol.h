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
char Data_transmit(char data, char state);

/* *
 * Signal the IC that a data transmission is imminent
 * should be call before use data transmit
 * */
void Start_condition(char state);

/* *
 * Signal the IC that the transmission is complete
 * @param : state to choose which IC to transmit
 * */
void Stop_condition(char state);
