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

// === Task handle ===
TaskHandle_t TaskCore1;

// === Task Core 1 : Tampilkan ke OLED ===
void taskCore1(void *pvParameters) {
  while (true) {
    display.clearDisplay();
    display.setTextSize(1);  // ukuran teks lebih besar
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 25);
    display.println("Hello World");
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

  // Jalankan task untuk OLED di Core 1
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
  // Tidak ada proses di loop utama
}
