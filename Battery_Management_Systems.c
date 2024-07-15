#include <stdio.h>
#include <assert.h>

int Check_battery_Value_Is_Ok(float temperature, float stateofcharge, float chargeRate) {
  if(temperature < 0 || temperature > 45) {
    printf("Temperature out of range!\n");
    return 0;
  } else if(stateofcharge < 20 || stateofcharge > 80) {
    printf("State of Charge out of range!\n");
    return 0;
  } else if(chargeRate > 0.8) {
    printf("Charge Rate out of range!\n");
    return 0;
  }
  return 1;
}

int main() {
  assert(Check_battery_Value_Is_Ok(25, 70, 0.7));
  assert(!Check_battery_Value_Is_Ok(50, 85, 0));
}
