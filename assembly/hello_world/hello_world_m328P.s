.nolist                  ; We don't want to actually include defs in our listing file.
.include "m328Pdef.inc"      ; m168def.inc defines all the pins on the Mega168 so we can
                  ; use them by their names rather than addresses (not fun).
.list                  ; We DO want to include the following code in our listing ;D

      rjmp      main       ; You usually place these two lines after all your
main:                  ; directives. They make sure that resets work correctly.

      ldi      r16,0xFF ; LoaD Immediate. This sets r16 = 0xFF (255)
      out      DDRB,r16 ; Out writes to SRAM, which is one way of accessing
                   ; pins. DDRB controls PORTB's in/out state.

      ldi      r16,0x00 ; r16 is where we'll store current LED state
                   ; 0x00 means all off. This is preserved over loops.

loop:                  ; This is a label (like main above) where we can come back to

      com      r16       ; Flip all the bits in r16 (one's complement)
                  ; So, originally, we go from 0x00 (off) to 0xFF (on)

      out      PORTB,r16 ; set all B pins to current state. PORTB is where our favorite flashing pin is (pin 13)!


; Waiting for a specified time:
; Ok, so we want to wait one second between each LED flip.
; Our Arduino should be clocked at 16Mhz, so that means we have to wait
; 16 million cycles between flips. Different instructions take different 
; amounts of clock cycles to complete, so we have to count the cycles 
; to get an accurate wait time. We're going to use a combination of a
; word and a byte to get the number of cycles right, since just a single
; byte or word can't hold near enough to wait for our needed time.

; Counting cycles:
; Below you'll see a couple instructions with numbers in their comments.
; The numbers represent how many clock cycles the instruction takes.
; You can find all of these cycle amounts in the atmega168 datasheet.
; 1/2 means it can take either one or two cycles depending on the flag
; state. For these branch instructions (BRNE), they take one cycle if
; the condition is false, and two cycles if it's true. We'll only care
; about the two cycle case, since that will be happening 99% of the time.
; Also, just for extra laziness we wont care about the outside loop's cycles.
; The inner is the really time critical one anyway ;D

; The math:
; The Arduino is clocked at 16Mhz, or 16000000 cycles per second.
; Our main loop takes 4 cycles to complete one loop, since SBIW
; takes 2 cycles and BRNE will (usually) take 2 cycles. This means
; that we need to find an X < 256 and Y < 65536 so that X*Y*4 = 16000000.
; X=100 and Y=40000 fit that bill quite nicely, so we'll go with those.
; The outer loop runs 100 times, and the inner runs 40000 times per outer
; loop. This gives us about 1 second per flip!

      ldi      r17,100            ; r17 is our outer loop counter
outer:
      ; ZH and ZL are a word pseudo-register. It's actually a combination
      ; of r31 and r30, giving us 16 bits to use for SBIW. Handy!
      ; The HIGH and LOW macros just give us the high and low bits of a
      ; number.

      ldi      ZH,HIGH(40000)       ; 1
      ldi      ZL,LOW(40000)       ; 1

inner:
      ; These next two instructions SuBtract Immediate from Word and
      ; BRanch if Not Equal. Basically, we subtract one from the Z psuedo
      ; register (which begins with ZL, the low bits), and then, if we haven't
      ; reached 0, go back to the inner label. Otherwise we keep on going with
      ; the check for the outer loop!

      sbiw      ZL,1             ;2   \_ Main Loop (4 cycles)
      brne      inner             ;1/2 /

      ; The following instructions DECrement and BRanch if Not Equal. BRNE
      ; works exactly the same as above. DEC is shorthand for subtract one
      ; from this register. Only takes one clock cycle, too!

      dec      r17             ;1
      brne      outer             ;1/2

      ; Finally we've reached the end of the loop. Relative JuMP just brings
      ; us back to the label listed. Back to loop we go!

      rjmp      loop
