#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <Target.h>
#include <Score.h>
#include <OPCodes.h>
#include <Statuses.h>

struct PacketHeader {
  uint8_t opcode;
};

// Pairing Structures
struct PairingRequestPacket {
  uint8_t opcode;       // Should be OPCODE_PAIRING_REQUEST
  uint32_t token;
  TargetType type;
};

struct PairingResponsePacket {
  uint8_t opcode;       // Should be OPCODE_PAIRING_RESPONSE
  uint8_t assignedID;
  uint8_t colorIndex;
};

struct HubPairingRequestPacket {
  uint8_t opcode;       // Should be OPCODE_PAIRING_POLL
};

// Verification Structures
struct VerificationRequestPacket {
  uint8_t opcode;   // Should be OPCODE_VERIFICATION_REQUEST
  uint8_t id;
};

struct VerificationResponsePacket {
  uint8_t opcode;   // Should be OPCODE_VERIFICATION_RESPONSE
  uint8_t id;
};


struct HeartbeatPacket {
  uint8_t opcode;   // Should be OPCODE_HEARTBEAT
};

struct BlinkCommandPacket {
  uint8_t opcode;   // Should be OPCODE_BLINK_COMMAND
  // Add fields if needed
};



#pragma pack(push, 1)
struct TargetSessionInfoRequestPacket {
  uint8_t opcode;   // should be OPCODE_TARGET_SESSION_INFO
  TargetSessionInfo sessionInfo;
};
#pragma pack(pop)

struct ShowTargetColorRequestPacket {
  uint8_t opcode;   // should be OPCODE_SHOW_TARGET_COLOR
  bool switchOn;
};


struct HitRequestPacket {
  uint8_t opcode;   // should be OPCODE_HIT_REQUEST
  uint8_t id;
};

struct HitResponsePacket {
  uint8_t opcode;     // Should be OPCODE_SCORE_UPDATE or OPCODE_SCORE_RESET
  uint8_t value;
  ScoreStatus status;
};

struct SessionStatusPacket {
  uint8_t opcode;     // Should be OPCODE_SESSION_STATUS
  GameSessionStatus status;
};

struct GameModeLitTargetRequestPacket {
  uint8_t opcode;     // Should be OPCODE_GAMEMODE_LITTARGET
  uint8_t indexInEntity;
};

#endif