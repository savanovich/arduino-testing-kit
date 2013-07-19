#include <SegmentsDisplay.h>

const byte LATCH_PIN = 8;
const byte CLOCK_PIN = 12;
const byte DATA_PIN = 11;

OneDigitBinaryCounterDisplay display;

void setup() {
    Serial.begin(9600);
    display.setup(LATCH_PIN, CLOCK_PIN, DATA_PIN);
}

void loop() {
    display.showString("PLAY");
    /* display.showString("STOP"); */

    /* display.showDouble(1.2345, 4); */
}

