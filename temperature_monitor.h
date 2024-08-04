#ifndef TEMPERATURE_MONITOR_H
#define TEMPERATURE_MONITOR_H

extern const float TEMPERATURE_LOWER_LIMIT;
extern const float TEMPERATURE_UPPER_LIMIT;
extern const float TEMPERATURE_WARNING_TOLERANCE;

int isTemperatureOk(float temperature);

#endif 
