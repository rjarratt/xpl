*SEGMENT 8192
BEGIN
:: This is Robert Jarratt's re-construction of a minimal MU5 Engineer's Loader. It bears little resemblance to the original functionality at this stage.
::
:: The vectors below are the interrupt vectors, with space for the old link and values for the new link. The segment must be loaded as a virtually
:: addressed segment with a CPR set up for it. The new link values set executive mode in MS and keep virtual addressing enabled, so a CPR must be
:: coded for the interrupt handlers. The new link sets NB to zero, this assumes the interrupt procedures set SN to an executive data segment. The 
:: CO register is set to JUMP instructions in the 32 words before the vectors. Each of the 8 JUMPs occupies 48 bits (16 for the instruction,
:: 32 for the address), or 3 16-bit words, so 8 jumps is 24 16-bit words, which is 6 64-bit words, so padding for 10 more 64-bit words is required
:: to place the vectors in the right place.
JUMP HANDLE.INTERRUPT.0
JUMP HANDLE.INTERRUPT.1
JUMP HANDLE.INTERRUPT.2
JUMP HANDLE.INTERRUPT.3
JUMP HANDLE.INTERRUPT.4
JUMP HANDLE.INTERRUPT.5
JUMP HANDLE.INTERRUPT.6
JUMP HANDLE.INTERRUPT.7
DATAVEC PAD(64)
0,[10]
END
DATAVEC VECTORS(64)
0, %001D000040000000
0, %001D000040000003
0, %001D000040000006
0, %001D000040000009
0, %001E00004000000C
0, %001E00004000000F
0, %001E000040000012
0, %001E000040000015
END
DATASTR INTERRUPT.0 "SYSTEM ERROR INTERRUPT|0D||0A|"
DATASTR INTERRUPT.1 "CPR NON-EQUIVALENCE INTERRUPT|0D||0A|"
DATASTR INTERRUPT.2 "EXCHANGE INTERRUPT|0D||0A|"
DATASTR INTERRUPT.3 "PERIPHERAL WINDOW INTERRUPT|0D||0A|"
DATASTR INTERRUPT.4 "INSTRUCTION COUNTER 0 INTERRUPT|0D||0A|"
DATASTR INTERRUPT.5 "ILLEGAL ORDERS INTERRUPT|0D||0A|"
DATASTR INTERRUPT.6 "PROGRAM FAULTS INTERRUPT|0D||0A|"
DATASTR INTERRUPT.7 "SOFTWARE INTERRUPT|0D||0A|"

PROC HANDLE.INTERRUPT.0
ACALL PRINT.STRING(L0,INTERRUPT.0)
L0:
B = 0
EXIT VECTORS[B]
END

PROC HANDLE.INTERRUPT.1
ACALL PRINT.STRING(L1,INTERRUPT.1)
L1:
B = 1
EXIT VECTORS[B]
END

PROC HANDLE.INTERRUPT.2
ACALL PRINT.STRING(L0,INTERRUPT.2)
L2:
B = 2
EXIT VECTORS[B]
END

PROC HANDLE.INTERRUPT.3
ACALL PRINT.STRING(L0,INTERRUPT.3)
L3:
B = 3
EXIT VECTORS[B]
END

PROC HANDLE.INTERRUPT.4
ACALL PRINT.STRING(L0,INTERRUPT.4)
L4:
B = 4
EXIT VECTORS[B]
END

PROC HANDLE.INTERRUPT.5
ACALL PRINT.STRING(L0,INTERRUPT.5)
L5:
B = 5
EXIT VECTORS[B]
END

PROC HANDLE.INTERRUPT.6
ACALL PRINT.STRING(L0,INTERRUPT.6)
L6:
B = 6
EXIT VECTORS[B]
END

PROC HANDLE.INTERRUPT.7
ACALL PRINT.STRING(L0,INTERRUPT.7)
L7:
B = 7
EXIT VECTORS[B]
END

:: Parameter is descriptor for string to be printed.
PROC PRINT.STRING
V64/NB STRING:1
V32/NB LENGTH:4
VV/0 CONSOLE.INTERRUPT:%300
VV/0 TELETYPE.DATA:%306
VV/0 TELETYPE.CONTROL:%307
V32/STK STACK.TOP:0

NB =SF+ - 2 :: Go back 2 for each parameter
SF + 1

STACK B
STACK D
STACK A

:: Extract length of string              
A =' STRING
AU <= -32
AU & %FFFFFF
A => LENGTH

B = 0
D = STRING
NEXTCHAR:
B COMP LENGTH
IF >=0, - -> DONE
A =' %F             :: Value that resets console interrupt bits
A => CONSOLE.INTERRUPT        :: Set Console Interrupt in Console V-Store
A =' %00                      :: TTY output mode
A => TELETYPE.CONTROL         :: Set teletype control
A =' D[B]                     :: Next character
A => TELETYPE.DATA            :: Set teletype data

POLL: A =' CONSOLE.INTERRUPT  :: Read Console Interrupt
AU COMP 0                     :: Poll for interrupt
IF =0, - -> POLL
B + 1
- -> NEXTCHAR

DONE:
A = STACK.TOP
D = STACK.TOP
B = STACK.TOP

RETURN
END

END
*END OF SEGMENT
