#include <stdio.h>
#include <assert.h>

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

int isInRange(float value, float max, const char* Message) {
    if (value > max) {
        printMessage(Message);
        return 0;
    }
    return 1;
}

int isTemperatureOk(float temperature) {
    return isValueInRange(temperature, 0, 45, "Temperature out of range!");
}

int isSocOk(float soc) {
    return isValueInRange(soc, 20, 80, "State of Charge out of range!");
}

int isChargeRateOk(float chargeRate) {
    return isInRange(chargeRate, 0.8, "Charge Rate out of range!");
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    return isTemperatureOk(temperature) && isSocOk(soc) && isChargeRateOk(chargeRate);
}

int main() {
    // Valid cases
    assert(batteryIsOk(30, 75, 0.6));  // Valid case - random input
    assert(batteryIsOk(0, 20, 0.8));  // Valid case checking the lower limit of temperature, soc and chargeRate
    assert(batteryIsOk(45, 80, 0.8));  // Valid case checking the upper limit of temperature and soc
    
    // Invalid temperature cases
    assert(!batteryIsOk(-1, 75, 0.6));  // Temperature below lower limit
    assert(!batteryIsOk(46, 75, 0.6));  // Temperature above upper limit
    
    // Invalid soc cases
    assert(!batteryIsOk(30, 19, 0.6));  // soc below lower limit
    assert(!batteryIsOk(30, 81, 0.6));  // soc above upper limit
    
    // Invalid chargeRate case
    assert(!batteryIsOk(30, 75, 0.9));  // chargeRate above upper limit
    
    // Combination of invalid cases
    assert(!batteryIsOk(-1, 19, 0.7));  // temperature and soc out of range
    assert(!batteryIsOk(30, 19, 0.9));  // soc and chargeRate out of range
    assert(!batteryIsOk(-1, 75, 0.9));  // temperature and chargeRate out of range
    assert(!batteryIsOk(-1, 19, 0.9));  // All parameters out of range
 return 0;
}
