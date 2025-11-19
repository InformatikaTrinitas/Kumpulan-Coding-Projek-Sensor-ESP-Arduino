// Pin sensor PIR SR602

//ESP32
const int pirPin = 27;

// Variabel untuk menyimpan status PIR
int pirState = LOW;

void setup() {
  Serial.begin(115200);

  pinMode(pirPin, INPUT);

  Serial.println("Sensor SR602 siap...");
}

void loop() {
  int val = digitalRead(pirPin);

  if (val == HIGH && pirState == LOW) {
    Serial.println("Gerakan terdeteksi!");
    pirState = HIGH;
  } 
  else if (val == LOW && pirState == HIGH) {
    Serial.println("Tidak ada gerakan.");
    pirState = LOW;
  }

  delay(100);
}
