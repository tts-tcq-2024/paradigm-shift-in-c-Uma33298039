#include <stdio.h>
#include "battery_monitor.h"

void printMessage(const char* Message) {
    printf("%s\n", Message);
}

int isValueInRange(float value, float min, float max, const char* Message) {
    if (value < min || value > max) {
        printMessage(Message);
        return 0;
    }
    return 1;
}

void checkWarnings(float value, float lowerLimit, float upperLimit, float warningTolerance, const char* lowerWarningMsg, const char* upperWarningMsg) {
    if (value <= lowerLimit + warningTolerance) {
         printf("%s\n", lowerWarningMsg);
    }
    if (value >= upperLimit - warningTolerance) {
         printf("%s\n", upperWarningMsg);
    }
}

int isInRange(float value, float max, const char* Message) {
    if (value > max) {
        printMessage(Message);
        return 0;
    }
    return 1;
}
