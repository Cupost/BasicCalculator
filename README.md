# Basic Calculator Project 
## Description 
- A system with a 4x4 keypad input and three 7-segment LED displays: one to display number A, one to display number B, and one to display the result, number R. There is an 8x8 LED matrix to display the arithmetic operators (+, -, *, /) ,
> example : A (+ - * /) B = R 
1. All number are positive integer , max value = 9999 .
2. On 4x4 numeric keypad , A is + , B is - , C is * , D is / . 
### Component List 
1. Module Led-7-segment TM1637 
  - D14 --> D17 / 4 pin  
2. Led-matrix-8*8 MAX7219 SPI protocol 
  - D10 + D11 + D13 / 3 pin
3. Keypad 4x4 basic 
  - D0 --> D7 / 8 pin 

### Schematic 

## Configuration 
- F_OSC = 16MHz 
---
> [!NOTE]
> IC TM1637 for Led 7 segment => just need to sent data one time on update value 
> MAX7219 SPI protocol => Don need MISO pin on MCU, only transmit data 
