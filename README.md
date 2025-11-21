#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD I2C (alamat umum 0x27, jika tidak tampil coba 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

int soilPin = A0;   // Sensor soil moisture ke A0
int soilValue = 0;  // Variabel untuk menampung nilai analog

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture");
  delay(1000);

  Serial.begin(9600);
}

void loop() {
  soilValue = analogRead(soilPin); // Baca nilai sensor

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Soil: ");
  lcd.print(soilValue); // tampilkan nilai analog (0 - 1023)

  // Tambahan info persentase kelembaban
  int moisturePercent = map(soilValue, 1023, 0, 0, 100); 
  if (moisturePercent < 0) moisturePercent = 0;
  if (moisturePercent > 100) moisturePercent = 100;

  lcd.setCursor(0, 1);
  lcd.print("Moist: ");
  lcd.print(moisturePercent);
  lcd.print("%");

  Serial.print("Soil Value: ");
  Serial.print(soilValue);
  Serial.print(" | Moisture: ");
  Serial.print(moisturePercent);
  Serial.println("%");

  delay(500);
}
