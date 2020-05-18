#include "ppm_reader.h"
#include <Arduino.h>

void PPM_ISR() {txInput.pulse();}

PPM_Reader::PPM_Reader(int pin, bool something) {
    _ppmPin = pin;
    _rawValues = new unsigned long[PPM_CHANNEL_COUNT];
    _validValues = new unsigned long[PPM_CHANNEL_COUNT];

    for(int i = 0; i < PPM_CHANNEL_COUNT; i++) {
        _rawValues[i] = 0;
        _validValues[i] = 0;
    }

    pinMode(_ppmPin, INPUT);
}

void PPM_Reader::start() {
    // attachInterrupt(digitalPinToInterrupt(_ppmPin), PPM_ISR, FALLING);
}

void PPM_Reader::stop() {
    // detachInterrupt(digitalPinToInterrupt(_ppmPin));
}

bool PPM_Reader::isReceiving() { return !_valid; }

void PPM_Reader::loop() {
    if(micros() - _lastPulse > PPM_BLANK_TIME) {
        _valid = true;
    }
}

void PPM_Reader::pulse() {
    unsigned long previous = _lastPulse;
    _lastPulse = micros();
    unsigned long time = _lastPulse - previous;

    if(time > PPM_BLANK_TIME) {
        _pulses = 0;
        _valid = false;
    } else {
        if(_pulses < PPM_CHANNEL_COUNT) {
            _rawValues[_pulses] = time;
            if(time >= PPM_MIN_VAL - PPM_MAX_ERR && time <= PPM_MAX_VAL + PPM_MAX_ERR) {
                _validValues[_pulses] = constrain(time, PPM_MIN_VAL, PPM_MAX_VAL);
            }
        }
    }
}

PPM_Reader txInput(12, true);
