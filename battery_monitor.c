#include "battery_monitor.h"

const float CHARGE_RATE_UPPER_LIMIT = 0.8;
const float CHARGE_RATE_WARNING_TOLERANCE = 0.05 * CHARGE_RATE_UPPER_LIMIT;

int isChargeRateOk(float chargeRate) {
    int inRange = isInRange(chargeRate, CHARGE_RATE_UPPER_LIMIT, "Charge Rate out of range!");
    if (inRange && chargeRate >= CHARGE_RATE_UPPER_LIMIT - CHARGE_RATE_WARNING_TOLERANCE) {
        printf("Warning: Approaching charge rate peak!\n");
    }
    return inRange;
}
int batteryIsOk(float temperature, float soc, float chargeRate) {
    return isTemperatureOk(temperature) && isSocOk(soc) && isChargeRateOk(chargeRate);
}
