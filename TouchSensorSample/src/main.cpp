#include <Arduino.h>


#define LED_PIN 13 // Define the LED pin
#define TOUCH_PIN 2 // Define the touch pin
void setup() {
  pinMode(TOUCH_PIN, INPUT); // Set the touch pin as input
  pinMode(LED_PIN, OUTPUT); // Set the LED pin as output
  Serial.begin(9600); // Initialize serial communication
}


void loop() {
  int touchValue = digitalRead(TOUCH_PIN); // Read the touch sensor value
  if (touchValue == HIGH) {
    Serial.println("Touch detected!"); // Print a message if touch is detected
    digitalWrite(LED_PIN, HIGH); // Turn on the LED
  } else {
    digitalWrite(LED_PIN, LOW); // Turn off the LED
  }
  delay(100); // Delay for 100 milliseconds
}

