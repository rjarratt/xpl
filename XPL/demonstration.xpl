*SEGMENT 0
BEGIN
DATAVEC DATA(32)
8,0
514,0
516,0
518,0
1476395018,524288
1476395018,524328
0,0
0,0
528,529
530,531
532,533
534,535
536,537
538,539
540,541
542,543
544,545
546,547
548,549
550,551
552,553
554,555
556,557
558,559
560,561
562,563
564,565
566,567
568,569
570,571
572,573
574,575
576,577
578,579
560,561
END
END
*END OF SEGMENT
*SEGMENT 1
BEGIN
V32/0 V32ZERO:0
V32/NB V32NB0:0
V32/NB V32NB1:1
V32/NB V32NB2:2
V32/NB V32NB3:3
V32/NB V32NB4:4
V32/NB V32NB6:6
V32/NB V32NB8:8
V32/NB V32NB9:9
V32/NB V32NB10:10
V32/NB V32NB11:11
V32/NB V32NB12:12
V32/NB V32NB13:13
V32/NB V32NB14:14
V32/NB V32NB15:15
V32/NB V32NB16:16
V32/NB V32NB17:17
V32/NB V32NB18:18
V32/NB V32NB20:20
V32/STK STACK.TOP:0
V64/NB V64NB0:0
V64/NB V64NB1:1
V64/NB V64NB2:2
V64/NB V64NB3:3
�
NB = 16
SF =NB+ 22
B = V32NB0
B + V32NB1
B * V32NB2
B => V32NB3
B - V32NB4
B / V32NB6	:: should probably omit this as it's treated as a dummy order
B -/= V32NB8
B V V32NB10
B <= 3
B & V32NB12
B /: V32NB18	:: should probably omit this as it's treated as a dummy order
B -: V32NB17
B => V32NB11
B = V32NB10
B + V32NB20
B => V32NB13
B *= V32NB9
STACK V32NB11
NB =SF+ -2
SF =NB+ 20
A =' V32NB1
AU + V32NB3
AU * V32NB4
A => V32NB0
AU - V32NB6
AU / V32NB8
AU -/= V32NB11
AU V V32NB12
AU <= 2
AU & V32NB15
AU /: V32NB16
AU -: V32NB18
A => V32NB15
A =' V32NB14
AU + V32NB20
A => V32NB13
A *= V32NB9
B = STACK.TOP
B => V32NB10
NB = V32ZERO
SF =NB+ 6
D = V64NB0
XD = V64NB1
MOD 5
XMOD 3
D => V64NB2
XD => V64NB3
D *= V64NB1
STOP: - -> STOP
END
*END OF SEGMENT