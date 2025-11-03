#ifndef SCORE_H
#define SCORE_H

enum class ScoreStatus : uint8_t {
  Won       = 0x00,
  Lost      = 0x01,
  OnGoing   = 0x02,
  Even      = 0x03,
  Subtract  = 0x04,
  Add       = 0x05,
  Blocked   = 0x06,
  Error     = 0x07,
  Waiting   = 0x08
};

struct ScoreUpdated {
  uint8_t newScore;
  ScoreStatus status;
};

struct ScoreUpdatedPerTarget {
  uint8_t targetId;
  uint8_t newScore;
  ScoreStatus status;
};

#endif  // SCORE_H