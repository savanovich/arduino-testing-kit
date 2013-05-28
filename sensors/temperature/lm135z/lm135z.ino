int sensePin = 14; // Pin A0

float sensorValue = 0; //Set the sensor values as a floating number
float kelvinValue = 0;
float celsiusValue = 0;
float fahrenheitValue = 0;

const unsigned int TEMP_SENSOR_PIN = A0;
/* const float SUPPLY_VOLTAGE = 5.0; */
const float SUPPLY_VOLTAGE = 5.0;

void setup()
{
  Serial.begin(9600);
  pinMode(sensePin, INPUT);
}
const float get_temperature() {
  const int sensor_voltage = analogRead(TEMP_SENSOR_PIN);
  return (SUPPLY_VOLTAGE * sensor_voltage * 100.0) / 1024.0;
}

void loop() 
{
  sensorValue = analogRead(A0); //reads voltage on Pin A0
  /* Serial.println(sensorValue); */
  /* Serial.print(get_temperature()); */
  /* Serial.println(" C"); */

  kelvinValue = ((sensorValue * 5.0) / 1023) ; // convert Value to Kelvin

  celsiusValue = kelvinValue - 273.15;  // convert Kelvin to Celsius

  /* fahrenheitValue = (celsiusValue) * (9.0/5.0) + 32.0; // convert Celsius to Fahrenheit */

  /* Serial.print("The temperature in Fahrenheit is: "); */

  /* Serial.println(fahrenheitValue); */

  /* Serial.print("The temperature in Celsius is: "); */

  Serial.println(sensorValue);
  Serial.println(kelvinValue);

  /* Serial.println("- - - - - - - - - - - - - - - - - - - - -"); */

  delay(3000);
}
