/*
  Multiple tone player

 Plays multiple tones on multiple pins in sequence

 circuit:
 * 2 8-ohm speaker on digital pins 6 and 7

 http://arduino.cc/en/Tutorial/Tone4
 */

void setup() {

}

void loop() {
   // turn off tone function for pin 7:
   noTone(7);
  // play a note on pin 6 for 200 ms:
  tone(6, 440, 200);
  delay(200);

  // turn off tone function for pin 6:
  noTone(6);
  // play a note on pin 7 for 500 ms:
  tone(7, 494, 500);
  delay(500);
}
