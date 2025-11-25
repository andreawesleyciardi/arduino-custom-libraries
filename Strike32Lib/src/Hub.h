#ifndef HUB_H
#define HUB_H

#include <Arduino.h>
#include "Color.h"
#include "ColorPalette.h"

static const uint8_t HubColorIndexesPalette[] = {
  static_cast<uint8_t>(ColorPalette::getIndexByName("Fucsia")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Lime")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Purple")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Lime")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Magenta")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Ultramarine")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Yellow")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Orange")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Blue")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Purple"))
};

struct HubInfo {
  uint8_t id = 0xFF;
  uint8_t mac[6];
  uint8_t colorIndex = 0xFF;
  bool enabled = true;

  bool isValid() const {
    return id != 0xFF && mac[0] != 0;
  }

  String getColorName() const {
    if (colorIndex >= sizeof(HubColorIndexesPalette)) return "Unknown";
    Color color = ColorPalette::getByIndex(HubColorIndexesPalette[colorIndex]);
    return color.name;
  }
};

#endif