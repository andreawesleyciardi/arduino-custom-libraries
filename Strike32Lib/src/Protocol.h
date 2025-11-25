#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <Target.h>
#include <Score.h>
#include <OPCodes.h>
#include <Statuses.h>

enum class OnPipe {
  pairingPipe,
  targetPipe
};

struct PacketHeader {
  uint8_t opcode;
};

// Pairing Structures
struct PairingSolicitationPacket {
  uint8_t opcode;       // OPCODE_PAIRING_SOLICITATION
  uint8_t hubMac[6];
};

struct PairingRequestPacket {
  uint8_t opcode;       // OPCODE_PAIRING_REQUEST
  uint8_t targetMac[6];
  TargetType type;
};

struct PairingResponsePacket {
  uint8_t opcode;       // OPCODE_PAIRING_RESPONSE
  uint8_t hubMac[6];    // Hub’s MAC address (so Target knows who it belongs to)
  uint8_t targetMac[6];
  uint8_t id;
  uint8_t colorIndex;
};



// Verification Structures
struct VerificationRequestPacket {
  uint8_t opcode;   // OPCODE_VERIFICATION_REQUEST
  uint8_t hubMac[6];
  uint8_t id;
};

struct VerificationResponsePacket {
  uint8_t opcode;   // OPCODE_VERIFICATION_RESPONSE
  uint8_t id;
};


struct HeartbeatRequestPacket {
  uint8_t opcode;   // OPCODE_HEARTBEAT_REQUEST
};

struct HeartbeatResponsePacket {
  uint8_t opcode;   // OPCODE_HEARTBEAT_RESPONSE
  uint8_t id;
};

struct BlinkCommandPacket {
  uint8_t opcode;   // OPCODE_BLINK_COMMAND
  // Add fields if needed
};



#pragma pack(push, 1)
struct TargetSessionInfoRequestPacket {
  uint8_t opcode;   // OPCODE_TARGET_SESSION_INFO
  TargetSessionInfo sessionInfo;
};
#pragma pack(pop)

struct IdentifyTargetRequestPacket {
  uint8_t opcode;   // OPCODE_IDENTIFY_TARGET
  bool switchOn;
};


struct HitRequestPacket {
  uint8_t opcode;   // OPCODE_HIT_REQUEST
  uint8_t hubMac[6];
  uint8_t id;
};

struct HitResponsePacket {
  uint8_t opcode;     // OPCODE_SCORE_UPDATE or OPCODE_SCORE_RESET
  uint8_t value;
  ScoreStatus status;
};

struct SessionStatusPacket {
  uint8_t opcode;     // OPCODE_SESSION_STATUS
  GameSessionStatus status;
};

struct GameModeLitTargetRequestPacket {
  uint8_t opcode;     // OPCODE_GAMEMODE_LITTARGET
  uint8_t indexInEntity;
};

#endif