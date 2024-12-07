#ifndef ESP32_ROBOKEN_INTERFACE
#define ESP32_ROBOKEN_INTERFACE

#include <interface.h>
#include <Arduino.h>

class CytronMd: public Motor {
    public:
    CytronMd(uint8_t channel, uint8_t dir_pin) {
        this->channel = channel;
        this->dir_pin = dir_pin;
    }
    void cw(uint16_t speed) {
        digitalWrite(this->dir_pin, LOW);
        ledcWrite(channel, this->channel);
    }
    void ccw(uint16_t speed) {
        digitalWrite(this->dir_pin, LOW);
        ledcWrite(channel, this->channel);
    }
    private:
    uint8_t channel;
    uint8_t dir_pin;
};

#endif