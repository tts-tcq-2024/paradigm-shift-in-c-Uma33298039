#include "soc_monitor.h"
#include "battery_monitor.h"  //printMessage function

const float SOC_LOWER_LIMIT = 20.0;
const float SOC_UPPER_LIMIT = 80.0;
const float SOC_WARNING_TOLERANCE = 0.05 * SOC_UPPER_LIMIT;

int isSocOk(float soc) {
    int inRange = isValueInRange(soc, SOC_LOWER_LIMIT, SOC_UPPER_LIMIT, "State of Charge out of range!");
    if (inRange) {
        checkWarnings(soc, SOC_LOWER_LIMIT, SOC_UPPER_LIMIT, SOC_WARNING_TOLERANCE, "Warning: Approaching SoC discharge!", "Warning: Approaching SoC peak!");
    }
    return inRange;
}
