#ifndef TARGET_H
#define TARGET_H

#include <Arduino.h>

#include "Color.h"
#include "ColorPalette.h"

enum class TargetType : uint8_t {
  Unknown        = 0x00,
  StrikeLite     = 0x01,  // Tier 1
  StrikeVision   = 0x02,  // Tier 2
  StrikeAI       = 0x03   // Tier 3
};

inline String targetTypeToString(TargetType type) {
  switch (type) {
    case TargetType::StrikeLite:   return "StrikeLite";
    case TargetType::StrikeVision: return "StrikeVision";
    case TargetType::StrikeAI:     return "StrikeAI";
    default:                       return "Unknown";
  }
}

static const uint8_t TargetColorIndexesPalette[] = {
  static_cast<uint8_t>(ColorPalette::getIndexByName("Lime")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Purple")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Red")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Lime")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Magenta")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Ultramarine")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Yellow")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Orange")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Blue")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Purple"))
};

struct TargetInfo {
  uint8_t id = 0xFF;
  uint8_t mac[6];
  uint8_t hubMac[6];
  uint8_t colorIndex = 0xFF;
  uint8_t entityColorIndex = 0xFF;
  bool enabled = true;
  uint8_t indexInEntity = -1;
  unsigned long unreachableFrom = 0;

  bool isValid() const {
    return id != 0xFF && hubMac[0] != 0;
  }

  String getColorName() const {
    if (colorIndex >= sizeof(TargetColorIndexesPalette)) return "Unknown";
    Color color = ColorPalette::getByIndex(TargetColorIndexesPalette[colorIndex]);
    return color.name;
  }
};

struct TargetSessionInfo {
  bool enabled = true;
  uint8_t indexInEntity = 0;
  uint8_t entityColorIndex = 0xFF;
};

#endif