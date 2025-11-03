#include "DisplayFeedback.h"

void showStatus(RGBLed& led, SystemStatus status, uint8_t blinkCount) {
  switch (status) {
    case STATUS_OK:
      led.blink("Green", 100, blinkCount);
      break;
    case STATUS_ERROR:
      led.blink("Red", 100, blinkCount);
      break;
    case STATUS_PAIRING:
      led.blink("Blue", 100, blinkCount);
      break;
    case STATUS_CONNECTED:
      led.on("Green");
      break;
    case STATUS_DISCONNECTED:
      led.on("Red");
      break;
    case STATUS_LOW_BATTERY:
      led.blink("Orange", 150, blinkCount);
      break;
    case STATUS_CRITICAL_BATTERY:
      led.blink("Red", 100, blinkCount * 2);
      break;
    default:
      led.off();
      break;
  }
}