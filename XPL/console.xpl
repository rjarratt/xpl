*SEGMENT 1
BEGIN

NB = %10
SF = %10

REPEAT: CALL PRINT.STRING(REPEAT, HELLO.WORLD)

STOP: - -> STOP

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
*SEGMENT 2
BEGIN
DATASTR HELLO.WORLD "Hello MU5 World|0D||0A|"
END
*END OF SEGMENT
