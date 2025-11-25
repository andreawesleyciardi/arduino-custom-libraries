#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <Arduino.h>

struct FeedbackEffect {
  String name;       // "blink", "pulse", "chase"
  uint16_t delayTime = 0;
  uint8_t times = 0;
  uint8_t speed = 0;
  bool holdLast = false;
};

struct Feedback {
  String colorName;
  FeedbackEffect effect;
};

// Static table of feedback states
struct FeedbackEntry {
  const char* key;
  Feedback feedback;
};

static const FeedbackEntry feedbackTable[] = {
  { "hub_ready",   { "Fucsia",   { "blink", 500, 3 } } },
  { "target_ready",{ "Blue",     { "blink", 500, 3 } } },
  { "target_win",  { "Green",    { "chase", 50, 0, true } } }
};

// Lookup helper
inline Feedback getFeedback(const String& key) {
  for (auto& entry : feedbackTable) {
    if (key.equalsIgnoreCase(entry.key)) {
      return entry.feedback;
    }
  }
  return { "White", { "blink", 200, 1 } }; // fallback
}

#endif