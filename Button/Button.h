#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
  public:
    Button(uint8_t pin, uint16_t debounceMs = 50, uint16_t longPressMs = 2000);
    void setup();
    bool wasPressed();     // Detect short press
    bool wasLongPressed(void (*feedback)() = nullptr, uint16_t debounceFeedback = 1000);
    bool isLongPressed();  // Detect long press

  private:
    uint8_t buttonPin;
    uint16_t debounceTime;
    uint16_t longPressTime;
    bool lastState;
    bool currentState;
    unsigned long lastDebounceTime;
    unsigned long pressStartTime;
};

#endif
