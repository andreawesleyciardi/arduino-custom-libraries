#ifndef RGBLED_H
#define RGBLED_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#include <Color.h>

enum class PulseState { Idle, Rising, Falling };

class RGBLed {
public:
  // Discrete RGB LED (3 pins)
  RGBLed(uint8_t _redPin, uint8_t _greenPin, uint8_t _bluePin);

  // Addressable RGB LED (NeoPixel, 1 pin)
  RGBLed(uint8_t _dataPin, uint8_t _numPixels = 1);

  void setup(bool startOn = false);

  void on(String colorName = "", bool toRemember = false);
  void off();
  void blink(String colorName = "", uint16_t delayTime = 200, uint8_t times = 3);

  void startPulse(String colorName = "", uint8_t steps = 20, uint16_t delayTime = 20);
  void stopPulse();
  void updatePulse();

  void setBrightness(uint8_t _brightness);
  void setPrimaryColorName(String colorName);

  bool isOn = false;

private:
  // Mode flag
  bool useNeoPixel = false;

  // Discrete pins
  uint8_t redPin, greenPin, bluePin;

  // NeoPixel
  Adafruit_NeoPixel* strip = nullptr;

  // Brightness
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