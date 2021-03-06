#include <SegmentsDisplay.h>

const byte A_PIN = 2;
const byte B_PIN = 3;
const byte C_PIN = 4;
const byte D_PIN = 5;
const byte E_PIN = 6;
const byte F_PIN = 7;
const byte G_PIN = 8;
const byte DP_PIN = 12;

const byte Y1_PIN = 14;
const byte Y2_PIN = 15;
const byte Y3_PIN = 16;
const byte Y4_PIN = 17;

FourDigitsDisplay display;


void setup() {
    display.setup(
            A_PIN, B_PIN, C_PIN, D_PIN, E_PIN, F_PIN, G_PIN,
            DP_PIN,
            Y1_PIN, Y2_PIN, Y3_PIN, Y4_PIN);
}

void loop() {
    display.showDouble(0.123, 3);
    display.clean();

    display.showDouble(456.7, 1);
    display.clean();

    display.showFloat(6789.1, 1);
    display.clean();

    display.showFloat(0.001, 3);
    display.clean();

    display.showFloat(6789.123, 3);
    display.clean();

    display.showFloat(678912.3, 1);
    display.clean();
}

