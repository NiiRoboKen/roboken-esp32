#pragma onece

#include <roboken_std.hpp>
#include <Arduino.h>

class CytronMd : public roboken::Motor {
    public:
    CytronMd(uint8_t channel, uint8_t dir_pin) {
        this->channel = channel;
        this->dir_pin = dir_pin;
    }
    void cw(uint16_t speed) {
        digitalWrite(this->dir_pin, LOW);
        ledcWrite(this->channel, speed);
    }
    void ccw(uint16_t speed) {
        digitalWrite(this->dir_pin, HIGH);
        ledcWrite(this->channel, speed);
    }
    private:
    uint8_t channel;
    uint8_t dir_pin;
};
