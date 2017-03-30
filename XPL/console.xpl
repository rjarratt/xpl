*SEGMENT 1
BEGIN

V32/NB LENGTH:0
VV/0 CONSOLE.INTERRUPT:%300
VV/0 TELETYPE.DATA:%306
VV/0 TELETYPE.CONTROL:%307

NB = %10
:: Extract length of string              
A =' HELLO.WORLD
AU <= -32
AU & %FFFFFF
A => LENGTH

REPEAT:B = 0
NEXTCHAR: A =' %F             :: Value that resets console interrupt bits
A => CONSOLE.INTERRUPT        :: Set Console Interrupt in Console V-Store
A =' %00                      :: TTY output mode
A => TELETYPE.CONTROL         :: Set teletype control
A =' HELLO.WORLD[B]           :: @ sign
A => TELETYPE.DATA            :: Set teletype data

POLL: A =' CONSOLE.INTERRUPT  :: Read Console Interrupt
AU COMP 0                     :: Poll for interrupt
IF =0, - -> POLL
B CINC LENGTH
IF <0, - -> NEXTCHAR
- -> REPEAT

STOP: - -> STOP
END
*END OF SEGMENT
*SEGMENT 2
BEGIN
DATASTR HELLO.WORLD "Hello MU5 World|0D||0A|"
END
*END OF SEGMENT
