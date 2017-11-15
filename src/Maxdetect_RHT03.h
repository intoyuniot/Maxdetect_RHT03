//Adapted for IntoRobot by Robin, Sept 19, 2015

#ifndef MAXDETECT_RHT03_H
#define MAXDETECT_RHT03_H

#include "Arduino.h"

#define PAYLOAD_BITS 40
#define PAYLOAD_BYTES (PAYLOAD_BITS/8)

class Maxdetect_RHT03
{
    public:
        Maxdetect_RHT03(int pin);
        double getTemperature();
        double getHumidity();
        void update();
        void handleInterrupt();
        static Maxdetect_RHT03 *currentlyListeningInstance;

    private:
        int pin;
        double temperature;
        double humidity;
        int state;
        unsigned long listeningStartTime = 0;
        volatile unsigned long lastInterruptTime = 0;
        volatile int interruptCount = 0;
        volatile unsigned char payload[PAYLOAD_BYTES];
};

#endif
