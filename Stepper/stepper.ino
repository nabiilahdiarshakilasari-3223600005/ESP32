#include <Arduino.h>

// Pin A4988
#define DIR_PIN 17
#define STEP_PIN 16

void setup() {
  Serial.begin(115200);
  Serial.println("ESP32-S3 + A4988 Stepper Test");

  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);

  // Set arah awal
  digitalWrite(DIR_PIN, HIGH);
}

void loop() {
  // ---- Putar searah jarum jam ----
  Serial.println("Putar searah jarum jam");
  digitalWrite(DIR_PIN, HIGH);  // arah CW

  for (int i = 0; i < 200; i++) { // 200 step = 1 putaran
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(800); // kecepatan step
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(800);
  }

  delay(1000);

  // ---- Putar berlawanan arah jarum jam ----
  Serial.println("Putar berlawanan jarum jam");
  digitalWrite(DIR_PIN, LOW);  // arah CCW

  for (int i = 0; i < 200; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(800);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(800);
  }

  delay(1000);
}
