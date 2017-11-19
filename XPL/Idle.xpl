*SEGMENT 6
BEGIN
:: Editor's Notes *******************************************************************************************************
:: Listing identifies this as "IDLE" printed 11.58.52 12.05.78.  Listing marekd as "MU5 IDLE LOOP MUSIC PROGRAM ES", ES presumably standing for Eric Sunderland.
:: The original had a blank line between *SEGMENT and BEGIN, but the manual does not allow for it, so it has been removed because the correct grammar is unclear
:: TODO: The segment number above should be -1, the XPL compiler currently does not support -1 as a segment number. The program looks like it sets XPLD to
:: indicate that it is to execute in segment 6, so the segment number is set to 6.
::
:: To make this program work some changes have had to be made. It is possible that the program does not work as originally coded
:: because it is not running under MUSS. The particular problems seems to be to do with how XNB is set up to point to some variables
:: related to the number of iterations required for the delay loop(s).
:: 
:: Details on program operation
::
:: The program is driven by the engineer's handkeys. If switches 0 and 2 are set then a "snake" is displayed on the display lamps.
:: If the 4 least significant handswitches are set the program terminates.
:: If the 4 least significant handswitches are set to any other number greater than 9 then the program loops waiting to start.
::
:: The value of the least significant 4 handswitches determines which out of 10 different XNB blocks will be used for the XB0 and XB1
:: variables. A descriptor stores the XNB offsets for each of the blocks.
::
:: Variables
:: XPLD From the MUSS Basic Library Manual (p2.5), this seems to be used at some point to determine the segment number in which code is to be executed.
:: N14 contains the engineer's handswitches. Seems to duplicate N20
:: N15 is the outer loop counter. It counts down to -1 and is then turned into a positive number by masking the sign bit.
:: N20 contains the engineer's handswitches. Seems to duplicate N14
:: XB0 used to load N10 and to control a delay loop at L2. It is only ever loaded, never stored, there are multiple "blocks" of XB1 selected by the handswitches.
:: XB1 used to select the initial note. It is only ever loaded, never stored, there are multiple "blocks" of XB1 selected by the handswitches.
:: 
:: **********************************************************************************************************************
VV/0 EHK:%30B,INSC:%103 :: Editor's note. Engineer's Handkeys and Instruction Counter.

V64/0 XPLD:27
V32/0 PW0:0, PW1:1, PO2:2
V32/XNB XB0:0, XB1:1
V32/NB N0:0, N1:1,N2:2,N3:3,N4:4,N5:5,N6:6,N7:7,N8:8,N9:9
V32/NB N10:10,N11:11,N14:14,N15:15,N20:20

-> BEG
DATAVEC NOTE(4)
15,[14]
14,13,12,11,10,9,8,7,7,6,5,4,4,3,2,2,1,1
0,15,15,15,14,14,13,13,12,12,11,11,11,10,10,10
9,9,8,8,8,7,7,7,6,6,6,5,5,5,5,4,4,4,3,3,3,3,2,2,2,1,1,1,1
0,[18]
END
:: Editor's note. The offsets vector is not original and has been added to make the program work without MUSS
:: It provides XNB offsets to get to the block of variables XBVALS (also added) at the end of the program at an absolute location.
DATAVEC OFFSETS(16)
%200
%202
%204
%206
%208
%20A
%20C
%20E
%210
%212
END
BEG:

SF = 164
B = %200180000
B => XPLD
::XENTER CREATE.SEGMENT(0,6,%1F00,-1) :: Editor's note: Creates segment 6 of size %1F00 words, with default page size.
::XENTER UPDATE.TP(0,"T04SCR4",%40000D04")
B = PW0
B COMP 0
IF <0, -> FIN
A =' %FF000000FF
A => XPLD
:: L1 is a loop that polls the Engineer's Handswitches. In the least significant 4 bits: 15=terminate, >9 poll waiting to star
L1: NB = 164
SF = 200
:: XENTER EE(0)
B = EHK
B => N14
B => N20
MS = %40402020
::XENTER LE(0)
L10: B = 0
B => N10
B = N14
B & 15
B COMP 15
IF =0, ->FIN
B COMP 9
IF>0, -> L1
:: The descriptor in D below is supposed to store the XNB offset (from %60000) for one of 10 different blocks selected by the handswitches.
:: The blocks each contain the values for XB0 and XB1 for the selected block. The original code hard codes the value of D as
:: %2100000000180074, but this seems to point into the middle of the code and not correspond to any particular vector. Perhaps the fact
:: that the line was indented in the original listing means that it was an uncertain value, or possibly incomplete code. There is no
:: vector in the listing that corresponds to any kind of XNB offsets, and I wonder if this is something that MUSS provided.
 D = %2100000000180074
XNB = %60000
::XNB + D[B]
XNB + OFFSETS[B]
L4: BN = N10
IF BN, -> L10
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
B = XB0
B & %FFFF
B * 4
B -: 0
L2: B CINC 0
IF /=0, -> L2
B = XB0
B => N10
B <= -13
B => N0
B <= -1
B + N0
B => N15
B & %7FFF
B => N0
B = N15
B <= -15
B => N15
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
B = N20
B & %F000
B COMP %9000
IF /=0, -> L3A


DL = N1
L3A: B = %80(7)
B => N1
B = %80008000
B => N2

:: The main loop
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
B COMP -1
B => N0
B =' N3
B & 3
B => N3
SPM = 0
B -2
B => N4
IF /=0, ->L3
XNB => N9
::XENTER EE(0)
B = 0
B => INSC
MS = %20 :: Editor's note, inhibit instruction counter.
B = EHK
B => N20

MS = %2020
:: XENTER LE(0)
B = N20
B & %F000
B COMP %A000
IF <0, -> CONTA
IF =0, -> SNAKE
B COMP %B000
IF/=0, ->CONT

NB + 18
B = N2
B & %F00
B COMP %300
IF >0, -> F1
B = 0
F1: B <= 1
B V %8084
D = %210(8)180000
B => D[0]
MOD 1
B = %0256
B => D[0]

::XENTER CA(0,6,%1D) :: Sets Execute and Read access on segment 6

B = N2
B & 15
B => N4
::B = F2
B => N0
X = N2
X <= -4
X & 15
AOD = %F80
::XENTER CA(0,6,%1E) :: Sets Read and Write access on segment 6
NB + -18
-> CONT

CONTA: B = N20
B => N14
-> CONT

SNAKE: A =' XPLD
A <= 1
A => XPLD
DL = XPLD
-> CONT

CONT:
XNB = N9
B =' N15
B COMP -1
B => N15
B = %7FFF
B => N0
IF /=0, -> L3
-> L4
FIN: :: XENTER STOP(0,0)
:: Editor's note. The following code is not original
*LINE 512
DATAVEC XBVALS(32)
32767,0,[10]
END
END
*END OF SEGMENT
