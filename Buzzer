#define BUZZER 15

void toneManual(int pin, int frequency, int duration) {
  int period = 1000000 / frequency;     // periode dalam mikrodetik
  int halfPeriod = period / 2;
  long cycles = (long)frequency * duration / 1000;

  for (long i = 0; i < cycles; i++) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(halfPeriod);
    digitalWrite(pin, LOW);
    delayMicroseconds(halfPeriod);
  }
}

void setup() {
  pinMode(BUZZER, OUTPUT);
  Serial.begin(115200);
  Serial.println("ESP32-S3: Manual tone generator on GPIO 15");
}

void loop() {
  Serial.println("Nada 1kHz");
  toneManual(BUZZER, 1000, 500);  // mainkan 1 kHz selama 500 ms
  delay(300);

  Serial.println("Nada 2kHz");
  toneManual(BUZZER, 2000, 500);  // mainkan 2 kHz selama 500 ms
  delay(300);
}
