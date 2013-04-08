/*
   Input Pullup Serial

   This example demonstrates the use of pinMode(INPUT_PULLUP). It reads a
   digital input on pin 2 and prints the results to the serial monitor.

   The circuit:
 * Momentary switch attached from pin 2 to ground
 * Built-in LED on pin 13

 Unlike pinMode(INPUT), there is no pull-down resistor necessary. An internal
 20K-ohm resistor is pulled to 5V. This configuration causes the input to
 read HIGH when the switch is open, and LOW when it is closed.

   Original: http://www.arduino.cc/en/Tutorial/InputPullupSerial
 */

const unsigned int BUTTON_PIN = 2;
const unsigned int LED_PIN = 13;

void setup(){
    Serial.begin(9600);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);

}

void loop(){
    int sensorVal = digitalRead(BUTTON_PIN);
    Serial.println(sensorVal);

    // Keep in mind the pullup means the pushbutton's
    // logic is inverted. It goes HIGH when it's open,
    // and LOW when it's pressed. Turn on pin 13 when the
    // button's pressed, and off when it's not:
    if (sensorVal == HIGH) {
        digitalWrite(LED_PIN, LOW);
    } else {
        digitalWrite(LED_PIN, HIGH);
    }
}
