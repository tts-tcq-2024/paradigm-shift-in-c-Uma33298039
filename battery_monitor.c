#include "battery_monitor.h"
#include "Temperature_range_check.h"
#include "soc_range_check.h"
#include "charge_rate_check.h"

int batteryIsOk(float temperature, float soc, float chargeRate) {
    return isTemperatureOk(temperature) && isSocOk(soc) && isChargeRateOk(chargeRate);
}
