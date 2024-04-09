#include <Arduino.h>
const int rainDropSensorDigitalPin = 8; //0和1
const int rainDropSensorAnalogPin = A0; //雨越大，值越小
const int ledPin = 7;

void setup() {
  pinMode(rainDropSensorDigitalPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Initialize serial communication
}



void loop() {
  int value = digitalRead(rainDropSensorDigitalPin);
    Serial.println(value); // Print message to serial monitor
   int analogValue = analogRead(rainDropSensorAnalogPin); // read the analog value of the raindrop sensor
  Serial.println(analogValue);
  if (value == 0) { //下雨的时候是0
    digitalWrite(ledPin, HIGH);
    Serial.println("Rain detected!"); // Print message to serial monitor
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("Rain detected."); // Print message to serial monitor
  }

  delay(1000);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}