/* *
 * The function that initialization for SPI
 * @setup : mode 0, set output for SS CLK MOSI
 * */
void SPI_MasterInit(void);

// Transmit data with SPI protocol
void SPI_MasterTransmit(char cData);
