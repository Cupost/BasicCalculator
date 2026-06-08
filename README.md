# Basic Calculator Project 
## Description 
- A system using board **ARDUINO NANO** with a 4x4 keypad input and three 7-segment LED displays: one to display number A, one to display number B, and one to display the result, number R. There is an 8x8 LED matrix to display the arithmetic operators (+, -, *, /) ,
> example : A (+ - * /) B = R 
1. All number are positive integer , max value = 9999 .
2. On 4x4 numeric keypad , A is + , B is - , C is * , D is / . 

### Component List 
# Module Led-7-segment TM1637 
- D14 --> D17 / 4 pin  
  > - [D14] = PC0 = DIO-1
  > - [D15] = PC1 = DIO-2
  > - [D16] = PC2 = DIO-3
  > - [D17] = PC3 = CLK 
# Led-matrix-8*8 MAX7219 SPI protocol 
- D10 + D11 + D13 / 3 pin
  > - [D10] = PB2 = CS/SS  
  > - [D11] = PB3 = MOSI 
  > - [D13] = PB5 = SCK/CLK
# Keypad 4x4 basic 
- D0 --> D7 / 8 pin
  > - [PortD]

### Schematic 

## Configuration 
- F_OSC = 16MHz 
- Board = Arduino nano
---
> [!NOTE]
> IC TM1637 for Led 7 segment => just need to sent data one time on update value 
> MAX7219 SPI protocol => Don need MISO pin on MCU, only transmit data 
