#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define ANCHO_PANTALLA 128 // Ancho de la pantalla OLED, en píxeles
#define ALTURA_PANTALLA 64 // Altura de la pantalla OLED, en píxeles

// Declaración para un display SSD1306 conectado a I2C (pines SDA, SCL)
Adafruit_SSD1306 display(ANCHO_PANTALLA, ALTURA_PANTALLA, &Wire, -1);

const int trigPin = 5;
const int echoPin = 18;

// Definir la velocidad del sonido en cm/uS
#define VELOCIDAD_SONIDO 0.034
#define CM_A_PULGADA 0.393701

long duracion;
int distanciaCm;
int distanciaPulgada;

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT); // Configura el trigPin como Salida
  pinMode(echoPin, INPUT);  // Configura el echoPin como Entrada

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Error en la asignación de SSD1306"));
    for (;;);
  }
  delay(500);
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(WHITE);
}

void loop() {
  // Limpia el trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Establece el trigPin en estado ALTO durante 10 microsegundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Lee el echoPin, devuelve el tiempo de viaje de la onda de sonido en microsegundos
  duracion = pulseIn(echoPin, HIGH);
  
  // Calcula la distancia
  distanciaCm = duracion * VELOCIDAD_SONIDO / 2;
  
  // Convierte a pulgadas
  distanciaPulgada = distanciaCm * CM_A_PULGADA;
  
  // Imprime la distancia en el Monitor Serial
  Serial.print("Distancia (cm): ");
  Serial.println(distanciaCm);
  Serial.print("Distancia (pulgadas): ");
  Serial.println(distanciaPulgada);

  display.clearDisplay();
  display.setCursor(0, 25);
  // Muestra la distancia en cm
  display.print(distanciaCm);
  display.print(" cm");
  
  // Muestra la distancia en pulgadas
  /* display.print(distanciaPulgada);
  display.print(" in");*/
  display.display(); 

  delay(500);  
}
