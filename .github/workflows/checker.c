#include <stdio.h>
 #include <assert.h>
 int batteryIsOk(float temperature, float soc, float chargeRate) 
{ int isOk = 1; 
switch (1) 
{ 
case (temperature < 0 || temperature > 45): 
printf("Temperature out of range!\n");
isOk = 0;
break; 
case (soc < 20 || soc > 80):
 printf("State of Charge out of range!\n");
 isOk = 0; 
break; 
case (chargeRate > 0.8):
 printf("Charge Rate out of range!\n");
 isOk = 0; 
break; 
default:
 break; 
} 
return isOk; 
} 
int main() 
{ assert(batteryIsOk(25, 70, 0.7));
 assert(!batteryIsOk(50, 85, 0)); } 
