#include "Button.h"

Button::Button(uint8_t pin, uint16_t debounceMs, uint16_t longPressMs) {
  buttonPin = pin;
  debounceTime = debounceMs;
  longPressTime = longPressMs;
  lastState = HIGH;
  currentState = HIGH;
  lastDebounceTime = 0;
  pressStartTime = 0;
}

void Button::setup() {
  pinMode(buttonPin, INPUT_PULLUP);
}

bool Button::wasPressed() {
  bool reading = digitalRead(buttonPin);

  if (reading != lastState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceTime) {
    if (reading != currentState) {
      currentState = reading;
      if (currentState == LOW) {
        pressStartTime = millis();
        lastState = reading;
        return true;
      }
    }
  }

  lastState = reading;
  return false;
}

bool Button::isLongPressed() {
  if (digitalRead(buttonPin) == LOW) {
    if (pressStartTime == 0) {
      pressStartTime = millis();
    }
    if ((millis() - pressStartTime) >= longPressTime) {
      return true;
    }
  } else {
    pressStartTime = 0;
  }

  return false;
}

bool Button::wasLongPressed(void (*feedback)(), uint16_t debounceFeedback) {
  static bool longPressTriggered = false;
  static unsigned long lastFeedbackTime = 0;

  if (digitalRead(buttonPin) == LOW) {
    if (pressStartTime == 0) {
      pressStartTime = millis();
      longPressTriggered = false;
      lastFeedbackTime = millis();
    }

    // 🔁 Run feedback function if provided and debounce interval passed
    if (feedback && debounceFeedback > 0 && millis() - lastFeedbackTime >= debounceFeedback) {
      feedback();
      lastFeedbackTime = millis();
    }

    if (!longPressTriggered && (millis() - pressStartTime >= longPressTime)) {
      longPressTriggered = true;
      return true;
    }
  } else {
    pressStartTime = 0;
    longPressTriggered = false;
    lastFeedbackTime = 0;
  }

  return false;
}

