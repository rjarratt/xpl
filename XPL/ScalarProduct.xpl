*SEGMENT 1234
BEGIN
::Contrary to the HASE example, the second descriptor has to have an origin of 524368 because the values in the vector are 64-bit rather than 32-bit.
::At least that has to be the case until I understand how 32-bit values can be loaded into ACC and operated on by the AU orders.
::Calculates scalar product of two vectors, expected result in A is 935 (dec), 3A7 (hex)

V32/0 BASE:0
V64/NB X:0
V64/NB Y:1
V32/NB RESULT:4
V64/STK STACK.TOP:0

NB = BASE
SF =NB+ 6
B = 0
A =' 0
LOOP:A *= X[B]
AU * Y[B]
B CINC 9
AU + STACK.TOP
IF /=0, - -> LOOP
A => RESULT
STOP: - -> STOP
END
*END OF SEGMENT
