#include <ESP32Servo.h>

#define SERVO_PIN 4

Servo servo;

void setup() {
  servo.attach(SERVO_PIN);
}

void loop() {

  // 0° → 180° (5 saniye)
  for (int pos = 0; pos <= 180; pos++) {
    servo.write(pos);
    delay(5000 / 180);   // ≈27 ms
  }

  // 180° → 0° (5 saniye)
  for (int pos = 180; pos >= 0; pos--) {
    servo.write(pos);
    delay(5000 / 180);
  }
}