#ifndef RGBLED_H
#define RGBLED_H

#include <Arduino.h>
#include <Color.h>

enum class PulseState { Idle, Rising, Falling };

class RGBLed {
public:
  RGBLed(uint8_t _redPin, uint8_t _greenPin, uint8_t _bluePin);
  void setup(bool startOn = false);

  void on(String colorName = "", bool toRemember = false);
  void off();
  void blink(String colorName = "", uint8_t delayTime = 200, uint8_t times = 3);

  void startPulse(String colorName = "", uint8_t steps = 20, uint16_t delayMs = 20);
  void stopPulse();
  void updatePulse();  // Call periodically in loop or scheduler

  void setBrightness(uint8_t _brightness);
  bool isOn = false;
  void setPrimaryColorName(String colorName);

private:
  uint8_t redPin;
  uint8_t greenPin;
  uint8_t bluePin;
  uint8_t brightness = 255;

  // Color memory
  String primaryColorName = "White";

  // Pulse state
  bool pulseActive = false;
  String pulseColor = "";
  uint8_t pulseSteps = 0;
  uint16_t pulseDelay = 0;
  uint8_t pulseStep = 0;
  PulseState pulseState = PulseState::Idle;
  unsigned long lastPulseUpdate = 0;
};

#endif