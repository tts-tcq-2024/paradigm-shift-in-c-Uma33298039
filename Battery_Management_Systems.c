#include <stdio.h>
#include <assert.h>
int BatteryisOutOfRange(float value, float lower, float upper, const char *msg) 
{
 if (value < lower || value > upper) 
{ printf("%s out of range!\n",msg);
return 1;
 } 
return 0; } 
int Checkbatteryvalue_IsOk(float temperature, floatsoc, float chargeRate) 
{ return !(BatteryisOutOfRange(temperature, 0, 45, "Temperature") || BatteryisOutOfRange(soc, 20, 80, "State of Charge") || BatteryisOutOfRange(chargeRate, 0, 0.8, "Charge Rate")); }
 int main() 
{ 
assert(Checkbatteryvalue_IsOk(25, 70, 0.7)); 
assert(!Checkbatteryvalue_IsOk(50, 85, 0)); 
}
