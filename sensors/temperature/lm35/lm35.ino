const unsigned int TEMP_SENSOR_PIN = A0;
const float SUPPLY_VOLTAGE = 5.0;
const unsigned int BAUD_RATE = 9600;
const unsigned int DELAY = 1000;

void setup() {
  Serial.begin(BAUD_RATE);
}

const float get_temperature() {
  const int sensor_voltage = analogRead(TEMP_SENSOR_PIN);
  return (SUPPLY_VOLTAGE * sensor_voltage * 100.0) / 1024.0;
}

void loop() {
  Serial.print(get_temperature());
  Serial.println(" C");
  delay(DELAY);
}

