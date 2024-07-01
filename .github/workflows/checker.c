#include <stdio.h>
#include <assert.h> 
typedef enum { 
OK = 0, 
TEMPERATURE_OUT_OF_RANGE, 
SOC_OUT_OF_RANGE,
CHARGE_RATE_OUT_OF_RANGE
 } BatteryStatus;

BatteryStatus batteryIsOk(float temperature, float soc, float chargeRate) { 
return (temperature < 0 || temperature > 45) ? (printf("Temperature out of range!\n"), TEMPERATURE_OUT_OF_RANGE) : (soc < 20 || soc > 80) ? (printf("State of Charge out of range!\n"), SOC_OUT_OF_RANGE) : (chargeRate > 0.8) ? (printf("Charge Rate out of range!\n"), CHARGE_RATE_OUT_OF_RANGE) : OK; } 
int main() { 
assert(batteryIsOk(25, 70, 0.7) == OK); 
assert(batteryIsOk(50, 85, 0) == TEMPERATURE_OUT_OF_RANGE); 
return 0; 
    
} 
