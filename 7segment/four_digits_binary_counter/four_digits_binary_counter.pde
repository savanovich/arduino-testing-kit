#include <SegmentsDisplay.h>

const byte LATCH_PIN = 8;
const byte CLOCK_PIN = 12;
const byte DATA_PIN = 11;

const byte Y1_PIN = 14;
const byte Y2_PIN = 15;
const byte Y3_PIN = 16;
const byte Y4_PIN = 17;

FourDigitsBinaryCounterDisplay display;

void setup() {
    display.setup(
            LATCH_PIN, CLOCK_PIN, DATA_PIN,
            Y1_PIN, Y2_PIN, Y3_PIN, Y4_PIN);
}

void loop() {
    display.showString("PLAY");
    display.showString("STOP");

    display.showDouble(1.2345, 4);
}

