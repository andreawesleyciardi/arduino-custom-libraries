#ifndef STATUSES_H
#define STATUSES_H

enum class GameSessionStatus : uint8_t {
  Setting,
  Starting,
  Playing,
  Paused,
  Resetting,
  Ended
};

inline const char* GameSessionStatusToString(GameSessionStatus status) {
  switch (status) {
    case GameSessionStatus::Setting:   return "Setting";
    case GameSessionStatus::Starting:  return "Starting";
    case GameSessionStatus::Playing:   return "Playing";
    case GameSessionStatus::Paused:    return "Paused";
    case GameSessionStatus::Resetting: return "Resetting";
    case GameSessionStatus::Ended:     return "Ended";
    default:                           return "Unknown";
  }
}

#endif  // STATUSES_H