#include <stdio.h>
#include <assert.h>
int verify_BatteryRange(float value, float lower, float upper, const char *msg) 
{
 if (value < lower || value > upper) 
{ 
 printf("%s out of range!\n",msg);
 return 1;
 } 
 return 0; 
} 
int Check_batteryvalue_IsOk(float temperature, float stateofcharge, float chargeRate) 
{ 
 return !(verify_BatteryRange(temperature, 0, 45, "Temperature") || verify_BatteryRange(soc, 20, 80, "State of Charge") || verify_BatteryRange(chargeRate, 0, 0.8, "Charge Rate"));
}
int main() 
{ 
assert(Check_batteryvalue_IsOk(25, 70, 0.7)); 
assert(!Check_batteryvalue_IsOk(50, 85, 0)); 
}
