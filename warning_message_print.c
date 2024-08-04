#include<stdio.h>
#include "warning_message_print.h"

void printWarningMessage(const char* WarningMessage) {
    printf("%s\n", WarningMessage);
}

void printLowWarning(float value, float min, float tolerance, const char* lowWarning) {
    if (value >= min && value <= min + tolerance) {
        printf("%s\n", lowWarning);
    }
}

void printHighWarning(float value, float max, float tolerance, const char* highWarning) {
    if (value >= max - tolerance && value <= max) {
        printf("%s\n", highWarning);
    }
}
