#include <Arduino.h>
const int soundSensorPin = 8;
const int ledPin = 7;

void setup() {
  pinMode(soundSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Initialize serial communication
}



void loop() {
  int soundValue = digitalRead(soundSensorPin);
    Serial.println(soundValue); // Print message to serial monitor
  delay(500);
  if (soundValue == 0) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Sound detected!"); // Print message to serial monitor
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("No sound detected."); // Print message to serial monitor
  }
  delay(1000);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}