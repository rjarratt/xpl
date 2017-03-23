*SEGMENT 1234
BEGIN
::Contrary to the HASE example, the second descriptor has to have an origin of 524368 because the values in the vector are 64-bit rather than 32-bit.
::At least that has to be the case until I understand how 32-bit values can be loaded into ACC and operated on by the AU orders.
::Calculates scalar product of two vectors, expected result in A is 935 (dec), 3A7 (hex)

V32/0 BASE:0
V64/NB DESTINATION:3
V64/NB SOURCE:0

NB = BASE
D = DESTINATION
XD = SOURCE
SMVB +32
XD = 
:: 21301    42C1  STS XD_LD V64 NB 1
:: 2A700    55C0  STS SMVE lit Z 32
::          0020
:: 39700    73C0  STS BMVB lit Z 32
::          0020
:: 21302    42C2  STS XD_LD V64 NB 2
:: 2A700    55C0       STS SMVE lit Z 34
::          0022
:: 21300    42C0  STS XD_LD V64 NB 0
:: 2B700    57C0  STS SMVF lit Z 32
::          0020
:: 31303    62C3  STS D_LD V64 NB 3
:: 3D700    7BC0  STS BSCN lit Z 104
::          0068
:: 39700    73C0  STS BMVB lit Z 72
::          0048
:: 31303    62C4  STS D_LD V64 NB 4
:: 3E700    7DC0  STS BCMP lit Z 48   0111 1101 11
::          0030
:: 10765    21F5  B LD S0 D 0
:: 10000    2000  B LD lit Z 0
:: 21305    42C5  STS XD_LD V64 NB 5
:: 31306    62C6  STS D_LD V64 NB 6
:: 2E700    5DC0  STS SCMP lit Z 46
::          002E
::020006    1007  Org BReq lit Z 7   (Different to web site because the literals take up space too)
:: 3D700    7BC0  STS BSCN lit Z 95
::          005F
:: 36001    6C01  STS MOD lit Z 1
:: 21305    42C5  STS XD_LD V64 NB 5
:: 14001    2801  B ADD lit Z 1
:: 0000     0038  Org BR lit Z -8   (Different to web site because the literals take up space too)
::STOP: - -> STOP
END
*END OF SEGMENT
