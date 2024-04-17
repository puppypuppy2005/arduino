#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Adafruit_Sensor.h>
#include <DHT.h> // Add missing DHT library

const char* ssid = "MyWifi";
const char* password = "123456";



#define DHTPIN D1    // Pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT sensor type

DHT dht(DHTPIN, DHTTYPE);


ESP8266WebServer server(80);

const int LED_PIN = D0; // Replace 13 with the actual pin number

void handleRoot() {
  String html = "<html><body><h1>LED Control</h1>";
  html += "<button onclick=\"location.href='/on'\">Turn On</button>";
  html += "<button onclick=\"location.href='/off'\">Turn Off</button>";
  html += "<button onclick=\"location.href='/temperature'\">Show Temperature</button>";
  html += "<button onclick=\"location.href='/humidity'\">Show Humidity</button>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}
void showTemperature() {
  float temperature = dht.readTemperature();
  float temperature_f = dht.readTemperature(true);
  float humidity = dht.readHumidity();


  server.send(200, "text/html;charset=utf-8", "Temperature: " + String(temperature) + "摄氏度\nTemperature: " + String(temperature_f) + "华氏度");

}

void showHumidity() {
  float humidity = dht.readHumidity();
  String humidityString = String(humidity); // Convert humidity to a string
  server.send(200, "text/html;charset=utf-8", "Humidity: " + humidityString + "%"); // Concatenate humidityString instead of humidity

}
void handleOn() {
  // Code to turn on the LED
  digitalWrite(LED_PIN, HIGH);
  server.send(200, "text/plain", "LED turned on");
}

void handleOff() {
  // Code to turn off the LED
  digitalWrite(LED_PIN, LOW);
  server.send(200, "text/plain", "LED turned off");
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  WiFi.softAP(ssid, password);

  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);
  server.on("/temperature", showTemperature);
  server.on("/humidity", showHumidity);
  dht.begin();
  server.begin();
}

void loop() {
  server.handleClient();

}

