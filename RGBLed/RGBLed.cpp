#include "RGBLed.h"

RGBLed::RGBLed(uint8_t _redPin, uint8_t _greenPin, uint8_t _bluePin) {
  redPin = _redPin;
  greenPin = _greenPin;
  bluePin = _bluePin;
}

void RGBLed::setup(bool startOn) {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  if (startOn) on(); else off();
}

void RGBLed::on(String colorName, bool toRemember) {
  if (colorName == "") colorName = primaryColorName;
  if (toRemember) primaryColorName = colorName;

  Color c = getColorByName(colorName);

  // Apply brightness scaling
  uint8_t r = map(c.red, 0, 255, 0, brightness);
  uint8_t g = map(c.green, 0, 255, 0, brightness);
  uint8_t b = map(c.blue, 0, 255, 0, brightness);

  analogWrite(redPin, 255 - r);
  analogWrite(greenPin, 255 - g);
  analogWrite(bluePin, 255 - b);
  isOn = true;
}

void RGBLed::off() {
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);
  isOn = false;
}

void RGBLed::blink(String colorName, uint8_t delayTime, uint8_t times) {
  if (colorName == "") colorName = primaryColorName;
  for (uint8_t i = 0; i < times; i++) {
    on(colorName);
    delay(delayTime);
    off();
    delay(delayTime);
  }
}

void RGBLed::setBrightness(uint8_t _brightness) {
  brightness = constrain(_brightness, 0, 255);
}

void RGBLed::startPulse(String colorName, uint8_t steps, uint16_t delayMs) {
  if (colorName == "") colorName = primaryColorName;
  pulseColor = colorName;
  pulseSteps = steps;
  pulseDelay = delayMs;
  pulseStep = 0;
  pulseState = PulseState::Rising;
  pulseActive = true;
  lastPulseUpdate = millis();
}

void RGBLed::stopPulse() {
  pulseActive = false;
  pulseState = PulseState::Idle;
  setBrightness(255);  // Restore full brightness
  on();                // Show primary color
}

void RGBLed::updatePulse() {
  if (!pulseActive) return;
  if (millis() - lastPulseUpdate < pulseDelay) return;

  lastPulseUpdate = millis();
  uint8_t b = map(pulseStep, 0, pulseSteps, 0, 255);
  setBrightness(b);
  on(pulseColor);

  if (pulseState == PulseState::Rising) {
    pulseStep++;
    if (pulseStep >= pulseSteps) {
      pulseStep = pulseSteps;
      pulseState = PulseState::Falling;
    }
  } else if (pulseState == PulseState::Falling) {
    if (pulseStep == 0) {
      pulseStep = 0;
      pulseState = PulseState::Rising;
    } else {
      pulseStep--;
    }
  }
}

void RGBLed::setPrimaryColorName(String colorName) {
  primaryColorName = colorName;
}