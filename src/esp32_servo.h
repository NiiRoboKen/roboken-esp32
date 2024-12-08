#ifndef ESP32_SERVO_H_
#define ESP32_SERVO_H_
#include <interface.h>
#include <Arduino.h>

class NormalServo: public Servo {
    public:
    NormalServo(uint8_t channel, uint8_t pin) {
        this->channel = channel;
        this->pin = pin;
        ledcSetup(this->channel, this->FREQ, PWM_RESOLUTION);
        ledcAttachPin(this->pin, this->channel);
    }
    void set_degree(int angle) {
        float pulse_width = this->MIN_PULSE_WIDTH + (this->MAX_PULSE_WIDTH - this->MIN_PULSE_WIDTH) * angle / 180;
        int duty = (pulse_width - this->MIN_PULSE_WIDTH) / (this->MAX_PULSE_WIDTH - this->MIN_PULSE_WIDTH);
        ledcWrite(this->channel, pow(2, this->PWM_RESOLUTION) * duty);
    }
    private:
    const int FREQ = 50; // Hz
    const int PWM_RESOLUTION = 16; // bit
    const float MIN_PULSE_WIDTH = 0.5; // ms
    const float MAX_PULSE_WIDTH = 2.4; // ms
    uint8_t channel;
    uint8_t pin;
};

class Sg90: public NormalServo {};

class Mg996r: public NormalServo {};

#endif