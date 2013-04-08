/*
 * ReadAnalogVoltage
 * Reads an analog input on pin 0, converts it to voltage, and prints the result to the serial monitor.
 * Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
 */

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  Serial.println(voltage);
}
