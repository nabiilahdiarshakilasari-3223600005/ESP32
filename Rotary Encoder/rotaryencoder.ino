#include <Arduino.h>

// Definisi pin sesuai koneksi
#define CLK 8
#define DT 9
#define SW 10

int counter = 0;             // Nilai hitungan encoder
int lastStateCLK;            // Menyimpan status terakhir pin CLK
int currentStateCLK;         // Status saat ini pin CLK
unsigned long lastButtonPress = 0;

void setup() {
  Serial.begin(115200);

  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP);  // SW aktif LOW, jadi gunakan internal pull-up

  lastStateCLK = digitalRead(CLK);
  Serial.println("=== Rotary Encoder ESP32-S3 ===");
}

void loop() {
  currentStateCLK = digitalRead(CLK);

  // Jika terjadi perubahan pada CLK
  if (currentStateCLK != lastStateCLK) {
    if (digitalRead(DT) != currentStateCLK) {
      counter--; // Putar ke kiri
      Serial.println("Putar kiri (CCW)");
    } else {
      counter++; // Putar ke kanan
      Serial.println("Putar kanan (CW)");
    }
    Serial.printf("Counter: %d\n", counter);
  }

  // Cek tombol encoder ditekan
  int btnState = digitalRead(SW);
  if (btnState == LOW) {
    if (millis() - lastButtonPress > 500) {  // Debounce tombol
      Serial.println("Tombol ditekan!");
      counter = 0; // Misalnya reset counter saat ditekan
      Serial.println("Counter di-reset ke 0");
    }
    lastButtonPress = millis();
  }

  lastStateCLK = currentStateCLK;
}
