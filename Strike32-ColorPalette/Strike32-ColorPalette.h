#ifndef COLOR_PALETTE_H
#define COLOR_PALETTE_H

#include "Strike32-Color.h"

class ColorPalette {
public:
  static const Color& getByIndex(uint8_t index);
  static const Color& getByName(const String& name);
  static uint8_t getIndexByName(const String& name);
  static uint8_t size();

private:
  static const Color palette[];
  static const uint8_t paletteSize;
};

#endif