#include "ColorPalette.h"

const Color ColorPalette::palette[] = {
  Color(255, 0, 0, "Red"),
  Color(255, 128, 0, "Orange"),
  Color(255, 255, 0, "Yellow"),
  Color(128, 255, 0, "Lime"),
  Color(0, 255, 0, "Green"),
  Color(0, 255, 128, "Seafoam"),
  Color(0, 255, 255, "Cyan"),
  Color(0, 128, 255, "Ultramarine"),
  Color(0, 0, 255, "Blue"),
  Color(128, 0, 255, "Purple"),
  Color(255, 0, 255, "Magenta"),
  Color(255, 0, 128, "Fucsia"),
  Color(255, 255, 255, "White")
};

const uint8_t ColorPalette::paletteSize = sizeof(ColorPalette::palette) / sizeof(Color);

const Color& ColorPalette::getByIndex(uint8_t index) {
  return palette[index % paletteSize];
}

const Color& ColorPalette::getByName(const String& name) {
  int index = getIndexByName(name);
  return index >= 0 ? palette[index] : ColorOff;
}

uint8_t ColorPalette::getIndexByName(const String& name) {
  for (uint8_t i = 0; i < paletteSize; ++i) {
    if (palette[i].name.equalsIgnoreCase(name)) {
      return i;
    }
  }
}

uint8_t ColorPalette::size() {
  return paletteSize;
}