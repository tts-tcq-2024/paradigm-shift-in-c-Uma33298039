#include "temperature_monitor.h"
#include "value_range_check.h"
#include "warning.h"

const float TEMPERATURE_LOWER_LIMIT = 0.0;
const float TEMPERATURE_UPPER_LIMIT = 45.0;
const float TEMPERATURE_WARNING_TOLERANCE = 0.05 * TEMPERATURE_UPPER_LIMIT;

int isTemperatureOk(float temperature) {
    checkEarlyWarning(temperature, TEMPERATURE_LOWER_LIMIT, TEMPERATURE_UPPER_LIMIT, TEMPERATURE_WARNING_TOLERANCE, "Warning: Approaching temperature discharge!", "Warning: Approaching temperature peak!");
   return isValueInRange(temperature, TEMPERATURE_LOWER_LIMIT, TEMPERATURE_UPPER_LIMIT, "Temperature out of range!");
}
