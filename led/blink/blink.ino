/*
   Blink
   Turns on an LED_PIN on for one second, then off for one second, repeatedly.

   This example code is in the public domain.
 */

const unsigned int LED_PIN = 12;

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    digitalWrite(LED_PIN, HIGH);   // turn the LED_PIN on (HIGH is the voltage level)
    delay(1000);               // wait for a second
    digitalWrite(LED_PIN, LOW);    // turn the LED_PIN off by making the voltage LOW
    delay(1000);               // wait for a second
}
