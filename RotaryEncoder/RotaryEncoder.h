#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H

#include <Arduino.h>

class RotaryEncoder {
public:
  RotaryEncoder(uint8_t clkPin, uint8_t dtPin, uint8_t buttonPin);
  void setup();

  void enable();
  void disable();
  void interrupt();                 // For ISR-based rotation
  void setInterrupt(void (*userFunc)(), int mode = CHANGE);

  int getDirection();              // For polling-based rotation
  bool wasPressed();              // For polling-based button press

  bool hasChanged();              // ✅ New: detects rotation
  int getDelta();                 // ✅ New: returns accumulated delta

  bool enabled = true;

private:
  uint8_t clkPin;
  uint8_t dtPin;
  uint8_t buttonPin;

  int oldCLK = LOW;
  int oldDT = LOW;
  int direction = 0;

  int delta = 0;                  // ✅ New: accumulated rotation
  bool changed = false;          // ✅ New: flag for rotation

  bool lastButtonState = HIGH;
  bool buttonPressed = false;

  unsigned long lastRotateTime = 0;
  unsigned long lastButtonTime = 0;

  const unsigned long debounceDelay = 50;
};

#endif