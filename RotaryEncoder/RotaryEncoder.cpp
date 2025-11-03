#include "RotaryEncoder.h"

RotaryEncoder::RotaryEncoder(uint8_t _clkPin, uint8_t _dtPin, uint8_t _buttonPin)
  : clkPin(_clkPin), dtPin(_dtPin), buttonPin(_buttonPin) {}

void RotaryEncoder::setup() {
  pinMode(clkPin, INPUT_PULLUP);
  pinMode(dtPin, INPUT_PULLUP);
  pinMode(buttonPin, INPUT_PULLUP);

  oldCLK = digitalRead(clkPin);
  oldDT  = digitalRead(dtPin);
  lastButtonState = digitalRead(buttonPin);
}

void RotaryEncoder::enable() {
  enabled = true;
}

void RotaryEncoder::disable() {
  enabled = false;
}

void RotaryEncoder::setInterrupt(void (*userFunc)(), int mode) {
  attachInterrupt(digitalPinToInterrupt(dtPin), userFunc, mode);
}

void RotaryEncoder::interrupt() {
  if (!enabled) return;

  unsigned long now = millis();
  if (now - lastRotateTime < debounceDelay) return;

  int newCLK = digitalRead(clkPin);
  int newDT  = digitalRead(dtPin);
  direction = 0;

  if (newCLK != oldCLK) {
    if (oldCLK == LOW) {
      direction = -1 * (oldDT * 2 - 1);
      delta += direction;
      changed = true;
    }
  }

  oldCLK = newCLK;
  oldDT  = newDT;
  lastRotateTime = now;
}

int RotaryEncoder::getDirection() {
  interrupt();  // Poll rotation logic
  int result = direction;
  direction = 0;  // Reset after read
  return result;
}

bool RotaryEncoder::wasPressed() {
  unsigned long now = millis();
  bool currentState = digitalRead(buttonPin);

  if (currentState == LOW && lastButtonState == HIGH && (now - lastButtonTime > debounceDelay)) {
    lastButtonTime = now;
    lastButtonState = currentState;
    return true;
  }

  lastButtonState = currentState;
  return false;
}

bool RotaryEncoder::hasChanged() {
  interrupt();  // Ensure latest state
  bool result = changed;
  changed = false;
  return result;
}

int RotaryEncoder::getDelta() {
  interrupt();  // Ensure latest state
  int result = delta;
  delta = 0;
  return result;
}