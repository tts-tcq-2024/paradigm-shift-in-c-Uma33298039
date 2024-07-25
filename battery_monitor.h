#ifndef BATTERY_MONITOR_H
#define BATTERY_MONITOR_H

#include <stdio.h>
#include <assert.h>
#include "temperature_monitor.h"
#include "soc_monitor.h"

extern const float CHARGE_RATE_UPPER_LIMIT;
extern const float CHARGE_RATE_WARNING_TOLERANCE;

void printMessage(const char* Message);
int isValueInRange(float value, float min, float max, const char* Message);
void checkWarnings(float value, float lowerLimit, float upperLimit, float warningTolerance, const char* lowerWarningMsg, const char* upperWarningMsg);
int isInRange(float value, float max, const char* Message);
int isChargeRateOk(float chargeRate);
int batteryIsOk(float temperature, float soc, float chargeRate);

#endif /* BATTERY_MONITOR_H */
