#include <Arduino.h>
#include <IRremote.h>
IRsend irSend;
// Define IR LED pin
const int IR_LED_PIN = 3;

// Define IR code
const unsigned long IR_CODE = 0x00FF00FF;

void setup() {
  // Initialize IR LED pin as output
  pinMode(IR_LED_PIN, OUTPUT);
}


void loop() {
  // Send IR code
  irSend.sendNEC(IR_CODE, 32);
  

  // Delay for 1 second
  delay(1000);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}