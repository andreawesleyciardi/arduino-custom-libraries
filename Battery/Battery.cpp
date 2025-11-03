#include "Battery.h"

Battery::Battery(bool _withAutoCheck) {
  withAutoCheck = _withAutoCheck;
  isLow = false;
  lastAutoCheck = 0;
}

void Battery::setup() {
  check();
}

void Battery::check(void (*feedback)(long batteryValue, bool wasAutomaticCheck), bool wasAutomaticCheck) {
  long batteryValue = random(0, 100);
  if (batteryValue < 30) {
    isLow = true;
  }
  else {
    isLow = false;
  }
  if (feedback) {
    feedback(batteryValue, wasAutomaticCheck);
  }
  Serial.print(F("🔋 Battery level: "));
  Serial.println(batteryValue);
}

void Battery::autoCheck(void (*feedback)(long batteryValue, bool wasAutomaticCheck)) {
  long autoCheckInterval = 300000; // 5 minutes
  if (isLow) {
    autoCheckInterval = 150000; // 2.5 minutes
  }
  if (millis() - lastAutoCheck >= autoCheckInterval) {
    lastAutoCheck = millis();
    check(feedback, true);
  }
}

bool Battery::low() {
  return isLow;
}
