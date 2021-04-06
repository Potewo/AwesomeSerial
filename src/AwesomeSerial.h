#include <Arduino.h>

class AwesomeSerial {
  public:
    int bufSize;
    uint8_t* buf;
    void init(int bufSize, unsigned long baud);
    void send(const char* data);
    int receive();
    int read();
};
