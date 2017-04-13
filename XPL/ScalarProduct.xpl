*SEGMENT 1
BEGIN
::Contrary to the HASE example, the second descriptor has to have an origin of 524368 because the values in the vector are 64-bit rather than 32-bit.
::At least that has to be the case until I understand how 32-bit values can be loaded into ACC and operated on by the AU orders.
::Calculates scalar product of two vectors, expected result in A is 935 (dec), 3A7 (hex)

V32/0 BASE:0
V64/NB XVEC:0
V64/NB YVEC:1
V32/NB RESULT:4
V64/STK STACK.TOP:0

NB = BASE
SF =NB+ 6
B = 0
A =' 0
LOOP:A *= XVEC[B]
AU * YVEC[B]
B CINC 9
AU + STACK.TOP
IF /=0, - -> LOOP
A => RESULT :: Result should be %3A7
STOP: - -> STOP
END
*END OF SEGMENT
*SEGMENT 0
BEGIN
DATAVEC DATA(32)
16,0
0,0
0,0
0,0
0,0
0,0
0,0
0,0
671088650,524288
671088650,524328
0,0
0,0
0,0
0,0
0,0
0,0
0,0
0,0
0,0
0,0
0,0
0,0
0,0
0,0
0,0
0,0
0,0
0,0
0,0
0,0
0,0
0,0
0,0
0,0
0,0
END
END
*END OF SEGMENT
*SEGMENT 2
BEGIN
DATAVEC VECTORS(32)
1,2
3,4
5,6
7,8
9,10
11,12
13,14
15,16
17,18
19,20
21,22
23,24
25,26
27,28
29,30
31,31
END
END
*END OF SEGMENT
