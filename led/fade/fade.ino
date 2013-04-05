/*
 * Fade
 * This example shows how to fade an LED on pin 9
 * using the analogWrite() function.
 */

const unsigned int LED_PIN = 9;       // the pin that the LED is attached to

byte brightness = 0;    // how bright the LED is
byte fadeAmount = 5;    // how many points to fade the LED by

void setup()  {
    pinMode(LED_PIN, OUTPUT);
}

void loop()  {
    analogWrite(LED_PIN, brightness);

    // change the brightness for next time through the loop:
    brightness = brightness + fadeAmount;

    // reverse the direction of the fading at the ends of the fade:
    if (brightness == 0 || brightness == 255) {
        fadeAmount = -fadeAmount;
    }
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
}
