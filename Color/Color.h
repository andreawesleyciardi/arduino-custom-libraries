#ifndef COLOR_H
#define COLOR_H

#include <Arduino.h>

class Color {
  public:
    Color(); // Default constructor
    Color(const Color &_color); // Copy constructor
    Color(uint8_t _red, uint8_t _green, uint8_t _blue, String _name = "");

    uint8_t red;
    uint8_t green;
    uint8_t blue;
    String name;
};

// Predefined color wheel
extern const Color ColorWheel[];

#define COLOR_WHEEL_SIZE 12

// Utility functions
int getColorWheelIndexByName(String _name);
Color getColorByName(String _name);

// Fallback color
extern const Color ColorOff;

#endif
