#ifndef ENTITY_H
#define ENTITY_H

#include <Arduino.h>
#include <Color.h>
#include <ColorPalette.h>

static const uint8_t EntityColorIndexesPalette[] = {
  static_cast<uint8_t>(ColorPalette::getIndexByName("Cyan")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Fucsia")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Green")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Orange")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Blue")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Red")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Ultramarine")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Yellow")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Purple")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Magenta")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Lime")),
  static_cast<uint8_t>(ColorPalette::getIndexByName("Seafoam"))
};

#endif