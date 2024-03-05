#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Definir los pines
#define PIN_FIRE_ANALOG 14
#define PIN_FIRE_DIGITAL 4
#define PIN_LED 13  // Cambia esto al pin donde está conectado tu LED

// Inicializar el objeto del display OLED
Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup() {
  // Iniciar la comunicación serial
  Serial.begin(9600);

  // Inicializar el display OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Error al iniciar el display OLED"));
    for(;;);
  }

  // Mostrar un mensaje de bienvenida en el display
  display.display();
  delay(2000);
  display.clearDisplay();

  // Configurar pines como entrada o salida
  pinMode(PIN_FIRE_DIGITAL, INPUT);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  // Leer los valores del sensor de fuego
  int firesensor_analog = analogRead(PIN_FIRE_ANALOG);
  int firesensor_digital = digitalRead(PIN_FIRE_DIGITAL);

  // Imprimir información en el Monitor Serial
  Serial.print("Analog: ");
  Serial.print(firesensor_analog);
  Serial.print(", Digital: ");
  Serial.println(firesensor_digital);

  // Verificar si se detecta fuego o no
  if (firesensor_analog < 1000) {
    Serial.println("Fuego detectado");
    mostrarMensaje("Fuego detectado");
  } else if (digitalRead(PIN_LED) == LOW) {
    Serial.println("No hay fuego");
    mostrarMensaje("No hay fuego");
  } else {
    Serial.println("Esperando...");
    mostrarMensaje("Esperando...");
  }

  // Esperar antes de la siguiente iteración
  delay(100);
}

// Función para mostrar un mensaje en el display OLED
void mostrarMensaje(String mensaje) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print(mensaje);
  display.display();
}
