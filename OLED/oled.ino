#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// === Konfigurasi Pin I2C ===
#define SDA_PIN 14
#define SCL_PIN 13

// === Ukuran layar OLED ===
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// === Objek display OLED ===
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// === Variabel global dibagikan antar-core ===
volatile unsigned long counter = 0;

// === Task handle ===
TaskHandle_t TaskCore0;
TaskHandle_t TaskCore1;

// === Task Core 0 : Hitung waktu / counter ===
void taskCore0(void *pvParameters) {
  while (true) {
    counter++;   // naik terus setiap 100 ms
    delay(100);
  }
}

// === Task Core 1 : Tampilkan ke OLED ===
void taskCore1(void *pvParameters) {
  while (true) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(0, 10);
    display.println("ESP32-S3 Dual Core");

    display.setCursor(0, 30);
    display.print("Counter: ");
    display.println(counter);

    display.display();
    delay(1000);
  }
}

// === Setup ===
void setup() {
  Serial.begin(115200);
  delay(1000);

  // Inisialisasi I2C dan OLED
  Wire.begin(SDA_PIN, SCL_PIN);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("Gagal inisialisasi OLED!");
    while (true);
  }

  // Tampilan awal
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 20);
  display.println("Inisialisasi...");
  display.display();
  delay(1000);

  // Jalankan task Core 0 (counter)
  xTaskCreatePinnedToCore(
    taskCore0,    // Fungsi task
    "TaskCore0",  // Nama task
    2048,         // Stack size
    NULL,
    1,            // Prioritas
    &TaskCore0,
    0             // Jalankan di Core 0
  );

  // Jalankan task Core 1 (tampilkan OLED)
  xTaskCreatePinnedToCore(
    taskCore1,
    "TaskCore1",
    4096,
    NULL,
    1,
    &TaskCore1,
    1             // Jalankan di Core 1
  );
}

void loop() {
  // Semua dijalankan lewat task RTOS
}
