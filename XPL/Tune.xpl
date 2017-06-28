*SEGMENT 1
BEGIN
:: Editor's Notes *******************************************************************************************************
:: Listing identifies this as "TUNE" printed 12.19.50 16.05.78. Listing marked as "ES MUSIC PROGRAM FOR MU5", ES presumably standing for Eric Sunderland.
:: The code below actions the pencilled comments on the original, so some lines have been added and removed.
:: The original had a blank line between *SEGMENT and BEGIN, but the manual does not allow for it, so it has been removed because the correct grammar is unclear
:: TODO: The segment number above should be -1, the XPL compiler currently does not support -1 as a segment number.
:: 
:: Details on program operation
::
:: The program is driven by the engineer's handkeys. If switches 0 and 2 are set then a "snake" is displayed on the display lamps.
:: If the 4 least significant handswitches are set the program terminates.
::
:: Variables
:: N2 contains a copy of N14 and is used to XOR with N1
:: N14 contains a number that depends on whether overlapping is enabled or not. If overlapping is enabled it is set to half the value it would otherwise be.
:: 
:: 
:: **********************************************************************************************************************
V64/0 XPLD:27
V32/0 PW0:0, PW1:1, PO2:2
V32/XNB XB0:0, XB1:1
V32/NB N0:0, N1:1,N2:2,N3:3,N4:4,N5:5,N6:6,N7:7,N8:8,N9:9
V32/NB N10:10,N11:11,N14:14
VV/0  MODE:%30A,HOOT:%305

-> BEG

:: Editor's note, bound is 95.
DATAVEC NOTE(4)
15,[14]
14,13,12,11,10,9,8,7,7,6,5,4,4,3,2,2,1,1
0,15,15,15,14,14,13,13,12,12,11,11,11,10,10,10
9,9,8,8,8,7,7,7,6,6,6,5,5,5,5,4,4,4,3,3,3,3,2,2,2,1,1,1,1
0,[18]
END
BEG:

:: Editor's Note. This bit looks like some OS call setup. No idea what XPLD does. It looks like PW0 could be some kind of return value.
SF = 164
B = %200180000
B => XPLD
::XENTER CREATE.SEGMENT(0,6,%1F00,-1) :: Editor's note: Creates segment 6 of size %1F00?
::XENTER UPDATE.TP(0,"T04SCR4",%40000D04")
B = PW0
B COMP 0
IF <0, -> FIN
L1: NB = 164
SF = 200
B = -13
B => N11
B = %40004000
B => N14
:: XENTER EE(0)
B = 0
B => N10
MS = %40402020
:: Editor's Note. This section is checking the Console Mode switch for overlapped instruction mode
B = MODE
B & %10
B COMP 0
IF=0,->LL1
:: Editor's Note. This code is reached if there is no overlapping of instructions
B = -14
B => N11
B = %20002000
B => N14
LL1:
B = 9
B & 15
B COMP 9
IF>0, -> L1
 D = %2100000000180074 :: Editor's note Type 0 Vector, with 16-bit elements starting in segment 6 at 32-bit word offset 1D.
XNB = %60000 :: Editor's note: Looks like it is accessing segment 6

XNB + D[B]
L4: BN = N10
 IF BN, -> L1
B = 0
B => N1
A =' XB1
AU <= -1
ES2: A => B
B & %7F
B COMP 32
B = NOTE[B]
B => N3
B = 1
B <= N3
IF >0, -> ES1
B <= 16
ES1: B V N1
B => N1
AU <= -8
A COMP 0
IF /=0, -> ES2
B = 0
B => N3
B => N5
B => N7
B => N9
:: Editor's Note: Load B with the value of XB0 and then do a loop to count up to the value in XB0 * 4
B = XB0
B & %FFFF
B * 4
B -: 0
L2: B CINC 0
IF /=0, -> L2
B = XB0
B => N10
B <= N11
B => N0
B = XB1
B & %FF00FF
B => N8
B = XB1
B <= -8
B & %FF00FF
B => N6
B = 2
B => N3
XNB + 2

DL = N1
B = N14
B => N2
B = %F0(7)
B => N1

L3: B  = N7
B + N6
B => N7
B & N1
B & N4
B => N5
B = N9
B + N8
B => N9
B -/= -1
B V N4
B -/= -1
B & N1
B V N5
B COMP 0
B = N1
B -/= N2
B => N1
BN= IF/=0
B =' N0
B COMP 0
B => N0
B =' N3
B & 3
B => N3
B -2
B => N4
B = BN
B => HOOT
IF /=0, ->L3
B = N10
B & 1
B COMP 1
IF/=0, ->L4
:: XENTER LE(0)
FIN: :: XENTER STOP(0,0)
END
*END OF SEGMENT
