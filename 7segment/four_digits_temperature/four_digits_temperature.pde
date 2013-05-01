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

const byte TEMP_SENSOR_PIN = A5;
const float SUPPLY_VOLTAGE = 5.0;

void setup() {
    display.setup(
            A_PIN, B_PIN, C_PIN, D_PIN, E_PIN, F_PIN, G_PIN,
            DP_PIN,
            Y1_PIN, Y2_PIN, Y3_PIN, Y4_PIN);
}

const float get_temperature() {
  const int sensor_voltage = analogRead(TEMP_SENSOR_PIN);
  return (SUPPLY_VOLTAGE * sensor_voltage * 100.0) / 1024.0;
}

void loop() {
    String temp = display.doubleToString((double) get_temperature(), 1);
    Serial.println(temp);
    display.showString(temp + String('C'));
}

