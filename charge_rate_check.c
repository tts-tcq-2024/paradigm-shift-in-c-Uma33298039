#include "charge_rate_check.h"
#include "value_range_check.h"
#include "warning.h"

int isChargeRateOk(float chargeRate) {
    checkEarlyWarningForChargeRate(chargeRate, 0.8, 0.04, "Warning: Approaching maximum charge rate");
    return isChargeRateInRange(chargeRate, 0.8, "Charge Rate out of range!");
}
