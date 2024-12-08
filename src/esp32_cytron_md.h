#ifndef ESP32_CYTRON_MD_H_
#define ESP32_CYTRON_MD_H_

//#include <interface.h>
#include <motor.h>
#include <Arduino.h>

class CytronMd : public Motor {
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