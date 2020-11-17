1a) MOVS, STR
1b) LDR, ORRS.W, STR

2a) The first four values are added to registers R0-R3, while the last value is pushed onto the stack.
2b) Writes the last value to the stack pointer, then moves the rest to registers R0-R3, then does a BL call to func1.
2c) There is a BX call to the link register.
2d) None