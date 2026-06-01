# Rules 
- always use skill [token-optimizer] first 
## Project file system & documentation map 

.
├── AGENTS.md
├── firmware
│   ├── Makefile
│   ├── build
│   ├── include
│   │   └── drivers
│   └── src
│       └── drivers
└── hardware
    └── docs.txt


# How to work 
- **NO High-Level Frameworks/Libraries**
- Register-Level Direct Access: Explain exactly which Special Function Registers (SFRs) are being targeted, including their exact functionality based on standard architecture manuals.
- Memory Mapping & Layout: Identify the peripheral base addresses, offset memory addresses, and how the data is laid out in SRAM/Flash.
- Bitwise Manipulation: Dissect every operation down to the individual bits (0 and 1). Explain the specific bitmask and bitwise operators (&, |, ~, ^) used to Set, Clear, or Toggle the target bits without disrupting adjacent memory cells.
## Workflow 
1. Read datasheet of microcontroller in folder project_name/hardware 
2. If question about bug or it's not working as expected, check why my code first and explain why it not work 
3. Return code to fix my problem and explain 
## Information about project
- Microcontroller : ATmega328p 

```
```
```
