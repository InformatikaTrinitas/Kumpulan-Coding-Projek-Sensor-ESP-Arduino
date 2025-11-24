#include <SPI.h>
#include <MFRC522.h>

// Pin untuk ESP32
#define RST_PIN 22
#define SS_PIN 5

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

void setup() {
  Serial.begin(115200);          // ESP32 biasanya pakai 115200 baud
  SPI.begin(18, 19, 23);         // SCK, MISO, MOSI ESP32
  mfrc522.PCD_Init();            // Init MFRC522
  delay(4);
  mfrc522.PCD_DumpVersionToSerial(); // Tampilkan versi RC522
  Serial.println(F("Tempelkan kartu/tag RFID ke sensor..."));
}

void loop() {
  // Jika tidak ada kartu baru, langsung return
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Pilih kartu
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Dump info kartu ke serial
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}
