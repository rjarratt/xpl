*SEGMENT 1234
BEGIN

V32/0 BASE:0
V64/NB DESTINATION:3
V64/NB SOURCE:0
V64/NB HELLO.STR:1
V64/NB WORLD.STR:2
V64/NB DIGITS.STR:4
V64/NB LET.THERE.BE.LIGHT.STR:5
V64/NB LIGHT.STR:6

NB = BASE
D = DESTINATION
XD = SOURCE
SMVB +32
XD = HELLO.STR
SMVE +32 :: Not a real order in MU5, included because it is in HASE
BMVB +32
XD = WORLD.STR
SMVE +34
XD = SOURCE
SMVF +32
D = DESTINATION
BSCN +104
BMVB +72
D = DIGITS.STR
BCMP +48
:: 10765    21F5  B LD S0 D 0
B = 0
XD = LET.THERE.BE.LIGHT.STR
D = LIGHT.STR
LOOP: SCMP +46
IF =0, - -> STOP
BSCN +95
MOD 1
XD = LET.THERE.BE.LIGHT.STR
B + 1
- -> LOOP
STOP: - -> STOP
END
*END OF SEGMENT
