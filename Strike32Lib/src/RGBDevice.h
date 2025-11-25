#ifndef RGBDEVICE_H
#define RGBDEVICE_H

#include <Arduino.h>

#include "Feedback.h"

class RGBDevice {
  public:
    void feedback(const String& key) {
      Feedback fb = getFeedback(key);   // <-- use the static lookup
      applyFeedback(fb);
    }

  protected:
    virtual void applyFeedback(const Feedback& fb) = 0; // implemented by subclasses
};

#endif