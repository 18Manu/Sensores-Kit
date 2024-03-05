#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define OLED_SDA 21
#define OLED_SCL 22
#define OLED_RST 16

#define DHT_PIN 4
#define DHT_TYPE DHT11

Adafruit_SSD1306 display(OLED_RST);
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println(F("ESP32 Temp"));
  display.display();
  delay(1000);
}

void loop() {
  float temperature = readTemperature();
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(F("Temperatura: "));
  display.print(temperature);
  display.println(F(" C"));
  display.display();
  delay(1000);
}

float readTemperature() {
  float temperature = dht.readTemperature();
  
  if (isnan(temperature)) {
    Serial.println(F("Error al obtener la temperatura"));
    temperature = 0.0;
  }

  return temperature;
}
