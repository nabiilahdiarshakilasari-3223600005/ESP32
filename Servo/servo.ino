#include <Arduino.h>
#include <ESP32Servo.h>

Servo myServo;  // Membuat objek servo

void setup() {
  Serial.begin(115200);
  
  // Attach servo ke pin 17
  myServo.attach(17);  
  
  Serial.println("Servo Test on GPIO 17");
}

void loop() {
  // Servo berputar dari 0° ke 180°
  for (int pos = 0; pos <= 180; pos++) {
    myServo.write(pos);
    Serial.printf("Servo position: %d\n", pos);
    delay(15);
  }

  // Servo berputar dari 180° ke 0°
  for (int pos = 180; pos >= 0; pos--) {
    myServo.write(pos);
    Serial.printf("Servo position: %d\n", pos);
    delay(15);
  }
}
