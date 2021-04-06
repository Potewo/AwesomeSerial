#include "AwesomeSerial.h"

AwesomeSerial s;
uint8_t ledArray[] = {2, 3, 4, 5, 6, 7, 8, 9};

void showLed(uint8_t);

void setup() {
  for (int i = 0; i < sizeof(ledArray) / sizeof(uint8_t); i++) {
    pinMode(ledArray[i], OUTPUT);
  }
  s.init(8, 9600);
}

void loop() {
  char key = s.read();

  if (key == 'R') {
    s.send("hello\n");
  }

  if (key == 'S') {
    int i = s.receive();
    for (int j = 0; j < i; j++) {
      showLed(s.buf[j]);
      delay(1000);
    }
  }
}

void showLed(uint8_t data) {
  for (int i = 7; i >= 0; i--) {
    bool status = data >> i & 0b00000001;
    digitalWrite(ledArray[7 - i], status);
  }
}
