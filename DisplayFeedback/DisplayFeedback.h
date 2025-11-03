#ifndef DISPLAY_FEEDBACK_H
#define DISPLAY_FEEDBACK_H

#include <RGBLed.h>
#include "Color.h"  // Assumes you already have a shared color map

enum SystemStatus {
  STATUS_OK,
  STATUS_ERROR,
  STATUS_PAIRING,
  STATUS_CONNECTED,
  STATUS_DISCONNECTED,
  STATUS_LOW_BATTERY,
  STATUS_CRITICAL_BATTERY
};

// Centralized feedback function
void showStatus(RGBLed& led, SystemStatus status, uint8_t blinkCount = 1);

#endif