#include <stdio.h>
#include <assert.h>

const float TEMPERATURE_LOWER_LIMIT = 0.0;
const float TEMPERATURE_UPPER_LIMIT = 45.0;
const float SOC_LOWER_LIMIT = 20.0;
const float SOC_UPPER_LIMIT = 80.0;
const float CHARGE_RATE_UPPER_LIMIT = 0.8;

const float TEMPERATURE_WARNING_TOLERANCE = 0.05 * TEMPERATURE_UPPER_LIMIT;
const float SOC_WARNING_TOLERANCE = 0.05 * SOC_UPPER_LIMIT;
const float CHARGE_RATE_WARNING_TOLERANCE = 0.05 * CHARGE_RATE_UPPER_LIMIT;

void printMessage(const char* Message) {
    printf("%s\n", Message);
}

int isValueInRange(float value, float min, float max, const char* Message) {
    if (value < min || value > max) {
        printMessage(Message);
        return 0;
    }
    return 1;
}

void checkWarnings(float value, float lowerLimit, float upperLimit, float warningTolerance, const const char* lowerWarningMsg, const char* upperWarningMsg) {
    if (value <= lowerLimit + warningTolerance) {
         printf("%s\n", lowerWarningMsg);
    }
    if (value >= upperLimit - warningTolerance) {
         printf("%s\n", upperWarningMsg);
    }
}

int isInRange(float value, float max, const char* Message) {
    if (value > max) {
        printMessage(Message);
        return 0;
    }
    return 1;
}

int isTemperatureOk(float temperature) {
    int inRange= isValueInRange(temperature, TEMPERATURE_LOWER_LIMIT, TEMPERATURE_UPPER_LIMIT, "Temperature out of range!");
     if (inRange) {
        checkWarnings(temperature, TEMPERATURE_LOWER_LIMIT, TEMPERATURE_UPPER_LIMIT, TEMPERATURE_WARNING_TOLERANCE, "Warning: Approaching temperature discharge!", "Warning: Approaching temperature peak!");
    }
    return inRange;
}

int isSocOk(float soc) {
    int inRange= isValueInRange(soc, SOC_LOWER_LIMIT, SOC_UPPER_LIMIT, "State of Charge out of range!");
     if (inRange) {
        checkWarnings(soc, SOC_LOWER_LIMIT, SOC_UPPER_LIMIT, SOC_WARNING_TOLERANCE, "Warning: Approaching SoC discharge!", "Warning: Approaching SoC peak!");
    }
    return inRange;
}

int isChargeRateOk(float chargeRate) {
    int inRange= isInRange(chargeRate, CHARGE_RATE_UPPER_LIMIT, "Charge Rate out of range!");
      if (inRange && chargeRate >= CHARGE_RATE_UPPER_LIMIT - CHARGE_RATE_WARNING_TOLERANCE) {
        printf("Warning: Approaching charge rate peak!\n");
    }
    return inRange;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    return isTemperatureOk(temperature) && isSocOk(soc) && isChargeRateOk(chargeRate);
}

int main() {
    // Valid cases
    assert(batteryIsOk(30, 75, 0.6));  // Valid case - random input
    assert(batteryIsOk(0, 20, 0.8));  // Valid case checking the lower limit of temperature, soc and chargeRate
    //assert(batteryIsOk(45, 80, 0.8));  // Valid case checking the upper limit of temperature and soc
    
    // Invalid temperature cases
    //assert(!batteryIsOk(-1, 75, 0.6));  // Temperature below lower limit
    //assert(!batteryIsOk(46, 75, 0.6));  // Temperature above upper limit
    
    // Invalid soc cases
    //assert(!batteryIsOk(30, 19, 0.6));  // soc below lower limit
    //assert(!batteryIsOk(30, 81, 0.6));  // soc above upper limit
    
    // Invalid chargeRate case
    //assert(!batteryIsOk(30, 75, 0.9));  // chargeRate above upper limit
    
    // Combination of invalid cases
   // assert(!batteryIsOk(-1, 19, 0.7));  // temperature and soc out of range
   // assert(!batteryIsOk(30, 19, 0.9));  // soc and chargeRate out of range
   // assert(!batteryIsOk(-1, 75, 0.9));  // temperature and chargeRate out of range
   // assert(!batteryIsOk(-1, 19, 0.9));  // All parameters out of range
 return 0;
}
