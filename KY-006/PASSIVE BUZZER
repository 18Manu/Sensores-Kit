 #include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1

#define BUZZER_PIN 2

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

char *messages[] = {
  "Do", "Re", "Mi", "Fa", "Sol", "La", "Si"
};
void sonido(int frecuencia, float duracion) {
  int indiceNota = (frecuencia - 659) / 50;  // Calcula el índice basado en la frecuencia
  tone(BUZZER_PIN, frecuencia, duracion * 1000);
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(messages[indiceNota]);
  display.display();
  delay(duracion * 1000);
  noTone(BUZZER_PIN);
  display.clearDisplay();
  display.display();
}


void setup() {
  Serial.begin(115200);

  pinMode(BUZZER_PIN, OUTPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }

  display.display();
  delay(2000);
  display.clearDisplay();
}


void loop() {
  for (int i = 0; i < sizeof(messages) / sizeof(messages[0]); i++) {
    sonido(659 + i * 50, 0.5);  // Adjust the frequency based on your preference
    delay(500);  // Pause for 0.5 seconds between notes
  }
}
