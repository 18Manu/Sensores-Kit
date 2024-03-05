#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int sensorPin = A0;
const int ledPin = 12; 

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Error al iniciar el display OLED"));
    for(;;);
  }
  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {
  int lightLevel = analogRead(sensorPin);
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.print("Nivel de luz: ");
  display.println(lightLevel);
  display.display();

  if(lightLevel > 150) { 
    digitalWrite(ledPin, HIGH); // Enciende el LED si el nivel de luz es alto
  } else {
    digitalWrite(ledPin, LOW); // Apaga el LED si el nivel de luz es bajo
  }

  delay(1000);
}
