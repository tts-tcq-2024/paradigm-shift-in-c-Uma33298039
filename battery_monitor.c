#include "battery_monitor.h"
#include "temperature_monitor.h"
#include "soc_monitor.h"
#include "charge_rate_check.h"


int batteryIsOk(float temperature, float soc, float chargeRate) {
    return isTemperatureOk(temperature) && isSocOk(soc) && isChargeRateOk(chargeRate);
}
