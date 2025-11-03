#ifndef BATTERY_H
#define BATTERY_H

#include <Arduino.h>

class Battery {
  public:
    Battery(bool _withAutoCheck);
    void setup();
    void check(void (*feedback)(long batteryValue, bool wasAutomaticCheck) = nullptr, bool wasAutomaticCheck = false);             // Manual check via button
    void autoCheck(void (*feedback)(long batteryValue, bool wasAutomaticCheck) = nullptr);         // Scheduled check every 5 minutes or 2.5 minutes if battery level is low
    bool low();               // Returns battery status

  private:
    bool isLow;
    bool withAutoCheck;
    unsigned long lastAutoCheck;
};

#endif
