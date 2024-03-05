//KY - 016 RGB LED
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int redPin = 2;    // Pin para el canal rojo del KY-016
int greenPin = 4;  // Pin para el canal verde del KY-016
int bluePin = 15;  // Pin para el canal azul del KY-016

void setup() {
  Serial.begin(115200);

  // Inicializar la pantalla OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Error al iniciar el OLED"));
    for(;;);
  }

  // Inicializar los pines para el KY-016
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {
  setColor(255, 0, 0);   // Rojo
  displayColor("Rojo");
  delay(1000);

  setColor(0, 255, 0);   // Verde
  displayColor("Verde");
  delay(1000);

  setColor(0, 0, 255);   // Azul
  displayColor("Azul");
  delay(1000);
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void displayColor(const char* colorName) {
  // Mostrar información en la pantalla OLED
  Serial.print("Mostrando color: ");
  Serial.println(colorName);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Color actual: ");
  display.println(colorName);
  display.display();
  delay(1000);
}
