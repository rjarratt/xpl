*SEGMENT 1
BEGIN
:: Test hooter proram to output a square wave.
VV/0  HOOT:%305

A =' 0

OUTERLOOP:
A => HOOT
B = 0
INNERLOOP:
B + 1
B COMP 10000
IF <0, - -> INNERLOOP
AU + 1 :: flip the l.s. bit
- -> OUTERLOOP

END
*END OF SEGMENT
