#ifndef SOC_MONITOR_H
#define SOC_MONITOR_H

extern const float SOC_LOWER_LIMIT;
extern const float SOC_UPPER_LIMIT;
extern const float SOC_WARNING_TOLERANCE;

int isSocOk(float soc);

#endif 
