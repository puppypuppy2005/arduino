#include <Arduino.h>
 #include <Adafruit_Sensor.h>

#include <DHT.h> // Add missing DHT library

#define DHTPIN 2     // Pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT sensor type

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}


void loop() {
  // put your main code here, to run repeatedly:
  float temperature = dht.readTemperature();
  float temperature_f = dht.readTemperature(true);
  float humidity = dht.readHumidity();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C\t");
  
  Serial.print(temperature_f);
  Serial.print(" °F\t");
  
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(2000);
}
