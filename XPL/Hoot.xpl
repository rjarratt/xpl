*SEGMENT 1
BEGIN
:: Test hooter program to output a square wave. Frequency cycles through different periods
VV/0  HOOT:%305
V32/NB HOOT.VAL:0
V32/NB PERIOD.NUMBER:1 :: Which entry in the PERIOD vector we are currently processing
V32/NB CURRENT.PERIOD.LENGTH:2 :: The number of iterations around the inner loop before changing the hoot value, basically the period of the square wave, measured in inner loop iterations
V32/NB NUMBER.OF.PERIODS:3
V32/NB CYCLES.IN.PERIOD:4
V32/NB CURRENT.CYCLE:5
V32/STK STACK.TOP:0

SF = 10 :: Set SF past the Names

:: Set number of periods so can cycle through the list of periods
A =' PERIOD
AU <= -32
AU & %FFFFFF
A => NUMBER.OF.PERIODS

:: Initialise variables
A =' 0
A => HOOT.VAL
A => PERIOD.NUMBER
A =' 500
A => CYCLES.IN.PERIOD

CYCLELOOP:

ACALL PRINT.STRING(L1,NEXT.PERIOD.STR)
L1:

:: Set current period length
D = PERIOD
B = PERIOD.NUMBER
A =' D[B]
A => CURRENT.PERIOD.LENGTH

:: Advance period number, reset back to zero if reached the end.
B + 1
B COMP NUMBER.OF.PERIODS
IF <0, - -> SET.NEXT.PERIOD
ACALL PRINT.STRING(L2,WRAP.STR)
L2:

B = 0
SET.NEXT.PERIOD:
B => PERIOD.NUMBER

:: Clear the current cycle counter
B = 0
B => CURRENT.CYCLE

:: Set up A with the hoot value that will be alternated between 0 and 1 every CURRENT.PERIOD.LENGTH iterations
A =' HOOT.VAL

PERIODLOOP: :: Loop that outputs the square wave at the chosen frequency(period) for CYCLES.IN.PERIOD iterations
B = CURRENT.CYCLE
B + 1
B COMP CYCLES.IN.PERIOD
IF >=0, -> CYCLELOOP
B => CURRENT.CYCLE

A => HOOT
B = 0
INNERLOOP:
B CINC CURRENT.PERIOD.LENGTH
IF <0, - -> INNERLOOP
AU + 1 :: flip the l.s. bit
AU & %1
A => HOOT.VAL
-> PERIODLOOP

DATAVEC PERIOD(32)
1000
2000
5000
10000
20000
50000
100000
200000
END
DATASTR NEXT.PERIOD.STR "NEXT|0D||0A|"
DATASTR WRAP.STR "WRAP|0D||0A|"


PROC PRINT.STRING
V64/NB STRING:1
V32/NB LENGTH:4
VV/0 CONSOLE.INTERRUPT:%300
VV/0 TELETYPE.DATA:%306
VV/0 TELETYPE.CONTROL:%307

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
A =' %F                       :: Value that resets console interrupt bits
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
