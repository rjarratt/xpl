*SEGMENT 1234
BEGIN

VV/NB CONSOLE.INTERRUPT:0
VV/NB TELETYPE.DATA:6
VV/NB TELETYPE.CONTROL:7

NB = %600               :: console base as 64-bit address (i.e. 0x300 x 2)
A =' %F                 :: Value that resets console interrupt bits
A => CONSOLE.INTERRUPT  :: Set Console Interrupt in Console V-Store
A =' 0                  :: TTY output mode
A => TELETYPE.CONTROL   :: Set teletype control
A =' %40                 :: @ sign
A => TELETYPE.DATA      :: Set teletype data
A =' CONSOLE.INTERRUPT  :: Read Console Interrupt
STOP: - -> STOP
END
*END OF SEGMENT
