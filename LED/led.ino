// 3 LED, masing-masing task sendiri
// merah = 2, hijau = 5, biru = 16
// merah -> Core 0 ; hijau & biru -> Core 1

#define LED_RED   2
#define LED_GREEN 5
#define LED_BLUE  16

void TaskLED_Red(void *pvParameters) {
  pinMode(LED_RED, OUTPUT);
  for (;;) {
    digitalWrite(LED_RED, HIGH);
    vTaskDelay(pdMS_TO_TICKS(300));
    digitalWrite(LED_RED, LOW);
    vTaskDelay(pdMS_TO_TICKS(300));
  }
}

void TaskLED_Green(void *pvParameters) {
  pinMode(LED_GREEN, OUTPUT);
  for (;;) {
    digitalWrite(LED_GREEN, HIGH);
    vTaskDelay(pdMS_TO_TICKS(500));
    digitalWrite(LED_GREEN, LOW);
    vTaskDelay(pdMS_TO_TICKS(500));
  }
}

void TaskLED_Blue(void *pvParameters) {
  pinMode(LED_BLUE, OUTPUT);
  for (;;) {
    digitalWrite(LED_BLUE, HIGH);
    vTaskDelay(pdMS_TO_TICKS(700));
    digitalWrite(LED_BLUE, LOW);
    vTaskDelay(pdMS_TO_TICKS(700));
  }
}

void setup() {
  Serial.begin(115200);
  delay(200);
  Serial.println("ESP32-S3: 3 LED tasks (Red=2, Green=5, Blue=16)");

  // LED Merah -> Core 0
  xTaskCreatePinnedToCore(TaskLED_Red, "LED_Red", 2048, NULL, 1, NULL, 0);

  // LED Hijau -> Core 1
  xTaskCreatePinnedToCore(TaskLED_Green, "LED_Green", 2048, NULL, 1, NULL, 1);

  // LED Biru -> Core 1
  xTaskCreatePinnedToCore(TaskLED_Blue, "LED_Blue", 2048, NULL, 1, NULL, 1);
}

void loop() {
  // kosong: semua dikerjakan oleh task
}
