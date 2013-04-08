/*
   Button
   Turns on and off a light emitting diode(LED) connected to digital
   pin 13, when pressing a pushbutton attached to pin 2.

   The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
   attached to pin 13.

   http://www.arduino.cc/en/Tutorial/Button
 */

const unsigned int BUTTON_PIN = 2;     // the number of the pushbutton pin
const unsigned int LED_PIN =  13;      // the number of the LED pin

int buttonState = LOW;         // variable for reading the pushbutton status

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
}

void loop(){
    buttonState = digitalRead(BUTTON_PIN);

    if (buttonState == HIGH) {
        digitalWrite(LED_PIN, HIGH);
    } else {
        digitalWrite(LED_PIN, LOW);
    }
}
