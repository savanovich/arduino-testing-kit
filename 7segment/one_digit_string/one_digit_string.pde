#include <SegmentsDisplay.h>

const unsigned int A_PIN = 2;
const unsigned int B_PIN = 3;
const unsigned int C_PIN = 4;
const unsigned int D_PIN = 5;
const unsigned int E_PIN = 6;
const unsigned int F_PIN = 7;
const unsigned int G_PIN = 8;
const unsigned int DP_PIN = 12;

OneDigitDisplay display;

void setup() {
    display.setup(A_PIN, B_PIN, C_PIN, D_PIN, E_PIN, F_PIN, G_PIN, DP_PIN);
}

void loop() {
    display.show("let's play");
    display.clean();

    display.show(String("Hello world!"));
    display.clean();
}

