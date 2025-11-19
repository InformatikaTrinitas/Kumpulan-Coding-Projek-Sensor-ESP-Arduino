#include "DHT.h"

#define DHTPIN 4      // Pin data DHT11
#define DHTTYPE DHT11  // Tipe sensor

//DHT 11 di ESP 32

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // cek apakah gagal membaca data
  if (isnan(h) || isnan(t)) {
    Serial.println("Gagal membaca data dari DHT11!");
    delay(2000);
    return;
  }

  Serial.print("Kelembaban: ");
  Serial.print(h);
  Serial.print(" %  |  Suhu: ");
  Serial.print(t);
  Serial.println(" °C");

  delay(2000); // baca tiap 2 detik
}
