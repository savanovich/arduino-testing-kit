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
long readVcc() {
  long result;
  // Read 1.1V reference against AVcc
  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  delay(2); // Wait for Vref to settle
  ADCSRA |= _BV(ADSC); // Convert
  while (bit_is_set(ADCSRA,ADSC));
  result = ADCL;
  result |= ADCH<<8;
  result = 1126400L / result; // Back-calculate AVcc in mV

  Serial.println(result/1000.0);
  return result/1000.0;
}

void loop() 
{
    int tempReading = analogRead(A0);  

    float voltage = tempReading * readVcc();
    voltage /= 1024.0; 

    // print out the voltage
    Serial.print(voltage); Serial.println(" volts");
    Serial.print(voltage*25/2.982); Serial.println(" C");

    delay(3000);
}
