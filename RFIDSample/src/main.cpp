#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN); // Create MFRC522 instance

void setup() {
  Serial.begin(9600); // Initialize serial communication
  SPI.begin(); // Initialize SPI bus
  rfid.PCD_Init(); // Initialize MFRC522
}


void loop() {
  // Check if a new card is present
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    // Read card UID
    String uid = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
      uid += String(rfid.uid.uidByte[i] < 0x10 ? "0" : "");
      uid += String(rfid.uid.uidByte[i], HEX);
    }
    Serial.println("Card UID: " + uid);

    // Write data to the card
    byte data[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    byte dataLength = sizeof(data);
    if (rfid.MIFARE_Write(1, data, dataLength)) {
      Serial.println("Data written to card successfully");
    } else {
      Serial.println("Failed to write data to card");
    }

    // Read data from the card
    byte readData[dataLength];
    byte readDataLength = sizeof(readData);
    if (rfid.MIFARE_Read(1, readData, &readDataLength)) {
      Serial.print("Data read from card: ");
      for (byte i = 0; i < readDataLength; i++) {
        Serial.print(readData[i], HEX);
        Serial.print(" ");
      }
      Serial.println();
    } else {
      Serial.println("Failed to read data from card");
    }

    // Halt PICC
    rfid.PICC_HaltA();
    // Stop encryption on PCD
    rfid.PCD_StopCrypto1();
  }
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}