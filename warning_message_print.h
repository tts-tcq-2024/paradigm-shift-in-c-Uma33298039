#ifndef WARNINGMESSAGE_PRINTER_H
#define WARNINGMESSAGE_PRINTER_H
#ifndef EARLYWARNINGMESSAGE_PRINTER_H
#define EARLYWARNINGMESSAGE_PRINTER_H

void printWarningMessage(const char* WarningMessage);
void printLowWarning(float value, float min, float tolerance, const char* lowWarning);
void printHighWarning(float value, float max, float tolerance, const char* highWarning);

#endif
#endif
