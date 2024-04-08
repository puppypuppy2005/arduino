#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}

#define TOUCH_PIN 2 // Define the touch pin

void setup() {
  pinMode(TOUCH_PIN, INPUT); // Set the touch pin as input
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // put your main code here, to run repeatedly:
  int touchValue = digitalRead(TOUCH_PIN); // Read the touch sensor value
  if (touchValue == HIGH) {
    Serial.println("Touch detected!"); // Print a message if touch is detected
  }
  delay(100); // Delay for 100 milliseconds
}