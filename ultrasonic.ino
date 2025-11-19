#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TRIG_PIN 23
#define ECHO_PIN 19

//Ultrasonic distance sensor di esp32

LiquidCrystal_I2C lcd(0x27, 16, 2);   // ganti ke 0x3F jika LCD kamu pakai 0x3F

int tinggi_sensor_cm = 200; // tinggi sensor dari lantai (ubah sesuai pemasangan)

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // ==== I2C Boots ====
  Wire.begin(21, 22);  // SDA=21, SCL=22
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Ultrasonic Ready");
  delay(1000);
}

long bacaJarak() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = duration * 0.034 / 2;

  return distance;
}

void loop() {
  long jarak_kepala = bacaJarak();
  int tinggi_badan = tinggi_sensor_cm - jarak_kepala;

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Jarak: ");
  lcd.print(jarak_kepala);
  lcd.print(" cm");

  lcd.setCursor(0,1);
  lcd.print("Tinggi: ");
  lcd.print(tinggi_badan);
  lcd.print(" cm");

  Serial.print("Tinggi Badan: ");
  Serial.print(tinggi_badan);
  Serial.println(" cm");

  delay(500);
}
