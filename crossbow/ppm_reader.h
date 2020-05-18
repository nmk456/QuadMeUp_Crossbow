#ifndef PPM_INPUT
#define PPM_INPUT

#include "Arduino.h"
#include "tx_input.h"

#define PPM_CHANNEL_COUNT 10
#define PPM_MIN_VAL 1000
#define PPM_MAX_VAL 2000
#define PPM_MAX_ERR 10
#define PPM_BLANK_TIME 2500

class PPM_Reader : public TxInput {
    public:
        PPM_Reader(int pin, bool something);
        void start();
        void stop();
        bool isReceiving();
        void loop();
        void pulse();
        void (*setRcChannelCallback)(uint8_t channel, int value, int offset);
    private:
        int _ppmPin;
        volatile byte _pulses = 0;
        volatile unsigned long *_rawValues = NULL;
        volatile unsigned long *_validValues = NULL;
        volatile unsigned long _lastPulse = 0;
        volatile bool _valid = false;

};

extern PPM_Reader txInput;

#endif
