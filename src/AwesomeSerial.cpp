#include "AwesomeSerial.h"

void AwesomeSerial::init(int bufSize, unsigned long baud) {
  Serial.begin(baud);
  AwesomeSerial::bufSize = bufSize;
  AwesomeSerial::buf = new uint8_t[bufSize];
}

void AwesomeSerial::send(const char* data) {
  Serial.print(data);
  while (true) {
    if (Serial.available()) {
      char OK = Serial.read();
      if (OK == 'O') {
        break;
      }
    }
  }
}

int AwesomeSerial::receive() {
  int N;
  while (1) {
    if (Serial.available() == 1) {
      N = Serial.read();
      break;
    }
  }
  Serial.print('O');
  while (1) {
    if (Serial.available() == N) {
      for (int i = 0; i < N; i++) {
        buf[i] = Serial.read();
      }
      break;
    }
  }
  Serial.print('O');
  return N;
}

int AwesomeSerial::read() {
  return Serial.read();
}
