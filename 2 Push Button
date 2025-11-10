// Dua tombol push button, masing-masing dijalankan di core berbeda
// Tombol 1 = GPIO 47 (Core 0)
// Tombol 2 = GPIO 21 (Core 1)

#define BTN1 47
#define BTN2 21

TaskHandle_t TaskButton1;
TaskHandle_t TaskButton2;

void TaskReadButton1(void *pvParameters) {
  pinMode(BTN1, INPUT_PULLUP);  // Active LOW
  bool lastState = HIGH;

  for (;;) {
    bool current = digitalRead(BTN1);
    if (current != lastState) {
      if (current == LOW)
        Serial.println("Core 0: Tombol 1 DITEKAN");
      else
        Serial.println("Core 0: Tombol 1 DILEPAS");
      lastState = current;
    }
    vTaskDelay(pdMS_TO_TICKS(50));  // debounce sederhana
  }
}

void TaskReadButton2(void *pvParameters) {
  pinMode(BTN2, INPUT_PULLUP);  // Active LOW
  bool lastState = HIGH;

  for (;;) {
    bool current = digitalRead(BTN2);
    if (current != lastState) {
      if (current == LOW)
        Serial.println("Core 1: Tombol 2 DITEKAN");
      else
        Serial.println("Core 1: Tombol 2 DILEPAS");
      lastState = current;
    }
    vTaskDelay(pdMS_TO_TICKS(50));
  }
}

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("ESP32-S3 Dual Core: Tombol 1 di GPIO47 (Core0), Tombol 2 di GPIO21 (Core1)");

  // Jalankan task pembaca tombol di core masing-masing
  xTaskCreatePinnedToCore(
    TaskReadButton1,  // Fungsi task
    "TaskButton1",    // Nama task
    2048,             // Stack size
    NULL,             // Parameter
    1,                // Prioritas
    &TaskButton1,     // Handle
    0                 // Jalankan di Core 0
  );

  xTaskCreatePinnedToCore(
    TaskReadButton2,
    "TaskButton2",
    2048,
    NULL,
    1,
    &TaskButton2,
    1                 // Jalankan di Core 1
  );
}

void loop() {
  // Kosong: semua dikerjakan oleh task
}
