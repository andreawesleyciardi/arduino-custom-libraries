#include "Color.h"

// Default constructor
Color::Color() {
  red = 0;
  green = 0;
  blue = 0;
  name = "Off";
}

// Copy constructor
Color::Color(const Color &_color) {
  red = _color.red;
  green = _color.green;
  blue = _color.blue;
  name = _color.name;
}

// Parameterized constructor
Color::Color(uint8_t _red, uint8_t _green, uint8_t _blue, String _name) {
  red = _red;
  green = _green;
  blue = _blue;
  name = _name;
}

// Color definitions
const Color ColorWheel[] = {
  Color(255,   0,    0,       "Red"),
  Color(255,   128,  0,       "Orange"),
  Color(255,   255,  0,       "Yellow"),
  Color(128,   255,  0,       "Lime"),
  Color(0,     255,  0,       "Green"),
  Color(0,     255,  128,     "Seafoam"),
  Color(0,     255,  255,     "Cyan"),
  Color(0,     128,  255,     "Ultramarine"),
  Color(0,     0,    255,     "Blue"),
  Color(128,   0,    255,     "Purple"),
  Color(255,   0,    255,     "Magenta"),
  Color(255,   0,    128,     "Fucsia"),
  Color(255,   255,  255,     "White")
};

// Get index by name (case-insensitive)
int getColorWheelIndexByName(String _name) {
  for (int i = 0; i < sizeof(ColorWheel) / sizeof(ColorWheel[0]); ++i) {
    if (ColorWheel[i].name.equalsIgnoreCase(_name)) {
      return i;
    }
  }
  return -1; // Not found
}

// Get color object by name
Color getColorByName(String _name) {
  int index = getColorWheelIndexByName(_name);
  if (index >= 0) {
    return ColorWheel[index];
  }
  return ColorOff;
}

// Fallback color
const Color ColorOff(0, 0, 0, "Off");
