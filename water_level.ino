#define WATER_SENSOR_PIN 32   // pin ADC untuk water level sensor

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);   // resolusi ADC ESP32 (0–4095)
}

void loop() {
  int adcValue = analogRead(WATER_SENSOR_PIN);  
  float voltage = adcValue * (3.3 / 4095.0);   // konversi ADC ke volt
  
  Serial.print("ADC: ");
  Serial.print(adcValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");
  
  delay(500);
}
