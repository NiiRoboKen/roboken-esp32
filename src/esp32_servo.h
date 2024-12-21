#ifndef ESP32_SERVO_H_
#define ESP32_SERVO_H_
#include <interface.h>
#include <Arduino.h>

class PwmServo : public Servo {
    public:
        PwmServo(uint8_t channel, uint32_t freq, uint32_t pwm_resolution, uint32_t min_pulse_width, uint32_t max_pulse_width) {
            this->channel = channel;
            this->freq = freq;
            this->pwm_resolution = pwm_resolution;
            this->min_pulse_width = min_pulse_width;
            this->max_pulse_width = max_pulse_width;
        }
        static PwmServo sg90(uint8_t channel) {
            return PwmServo(channel, PwmServo::FREQ, PwmServo::PWM_RESOLUTION, PwmServo::MIN_PULSE_WIDTH, PwmServo::MAX_PULSE_WIDTH);
        }
        void brgin(uint8_t pin){
            ledcSetup(this->channel, this->FREQ, this->pwm_resolution);
            ledcAttachPin(pin, this->channel); 
        }
        void set_degree(int angle) {
            float pulse_width = this->min_pulse_width + (this->max_pulse_width - this->min_pulse_width) * angle / 180;
            int duty = (pulse_width - this->min_pulse_width) / (this->max_pulse_width - this->min_pulse_width);
            ledcWrite(this->channel, pow(2, this->pwm_resolution) * duty);
        }
        static const uint32_t FREQ = 50; // Hz
        static const uint32_t PWM_RESOLUTION = 16; // bit
        static const uint32_t MIN_PULSE_WIDTH = 500; // us
        static const uint32_t MAX_PULSE_WIDTH = 2400; // us

    private:
        uint32_t freq; // Hz
        uint32_t pwm_resolution; // bit
        uint32_t min_pulse_width; // us
        uint32_t max_pulse_width; // us
        uint8_t channel;

};

#endif