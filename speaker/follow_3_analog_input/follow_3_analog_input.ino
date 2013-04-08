/*
  keyboard

 Plays a pitch that changes based on a changing analog input

 circuit:
 * 3 photo resistors from +5V to analog in 0 through 5
 * 3 10K resistors from analog in 0 through 5 to ground
 * 8-ohm speaker on digital pin 8

 http://arduino.cc/en/Tutorial/Tone3
 but photoresistor instead
 */

#include "../pitches.h"

const unsigned int BOUND_RATE = 9600;

const int THRESHOLD = 100;    // minimum reading of the sensors that generates a note

// notes to play, corresponding to the 3 sensors:
int notes[] = {NOTE_A4, NOTE_B4,NOTE_C3};

void setup() {
    Serial.begin(BOUND_RATE);
}

void loop() {
  for (int thisSensor = 0; thisSensor < 3; thisSensor++) {
    // get a sensor reading:
    int sensorReading = analogRead(thisSensor);
    Serial.println(sensorReading);

    // if the sensor is pressed hard enough:
    if (sensorReading < THRESHOLD) {
      // play the note corresponding to this sensor:
      tone(8, notes[thisSensor], 20);
    }
  }
}
