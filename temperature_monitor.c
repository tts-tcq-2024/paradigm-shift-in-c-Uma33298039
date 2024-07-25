#include "temperature_monitor.h"
#include "battery_monitor.h"  // printMessage function

const float TEMPERATURE_LOWER_LIMIT = 0.0;
const float TEMPERATURE_UPPER_LIMIT = 45.0;
const float TEMPERATURE_WARNING_TOLERANCE = 0.05 * TEMPERATURE_UPPER_LIMIT;

int isTemperatureOk(float temperature) {
    int inRange = isValueInRange(temperature, TEMPERATURE_LOWER_LIMIT, TEMPERATURE_UPPER_LIMIT, "Temperature out of range!");
    if (inRange) {
        checkWarnings(temperature, TEMPERATURE_LOWER_LIMIT, TEMPERATURE_UPPER_LIMIT, TEMPERATURE_WARNING_TOLERANCE, "Warning: Approaching temperature discharge!", "Warning: Approaching temperature peak!");
    }
    return inRange;
}
