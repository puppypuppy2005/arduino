#include <Arduino.h>
//红外传感器示例

int infraredPin = 7;
int ledPin = 8;

void setup() {
  pinMode(infraredPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int infraredData = digitalRead(infraredPin);
  
  if (infraredData == LOW) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
//  Serial.println(infraredData);
  delay(1000);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}