#include <stdio.h>
#include <assert.h>
#include "battery_monitor.h"

int main() {
    // Valid cases
    assert(batteryIsOk(30, 75, 0.6));  // Valid case - random input
    assert(batteryIsOk(0, 20, 0.8));   // Valid case checking the lower limit of temperature, socket, and chargeRate

    // Temperature out of range
    assert(!batteryIsOk(-1, 50, 0.7));  // Temperature below lower limit
    assert(!batteryIsOk(46, 50, 0.7));  // Temperature above upper limit

    // SOC out of range
    assert(!batteryIsOk(35, 15, 0.7));  // SOCKET below lower limit
    assert(!batteryIsOk(35, 85, 0.7));  // SOCKET above upper limit

    // Charge rate out of range
    assert(!batteryIsOk(35, 50, 0.9));  // Charge rate above upper limit

    printf("All tests passed!\n");

    return 0;
}
