#include <stdio.h>
#include <assert.h> 
int isOutOfRange(float value, float lower, float upper, const char *msg) 
{ 
 if (value < lower || value > upper) 
{ printf("%s out of range!\n", msg); 
 return 1; 
} 
 return 0; 
} 
int batteryIsOk(float temperature, floatsoc, float chargeRate) 
{ 
 return !(isOutOfRange(temperature, 0, 45, "Temperature") || isOutOfRange(soc, 20, 80, "State of Charge") || isOutOfRange(chargeRate, 0, 0.8, "Charge Rate")); 
} 
int main() 
{ assert(batteryIsOk(25, 70, 0.7)); 
 assert(!batteryIsOk(50, 85, 0)); }
