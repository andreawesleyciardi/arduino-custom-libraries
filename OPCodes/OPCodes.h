#ifndef OPCODES_H
#define OPCODES_H

// Pairing & Verification (0x01–0x0F)
#define OPCODE_PAIRING_REQUEST       0x01
#define OPCODE_PAIRING_RESPONSE      0x02
#define OPCODE_VERIFICATION_REQUEST  0x03
#define OPCODE_VERIFICATION_RESPONSE 0x04
#define OPCODE_HEARTBEAT             0x05
#define OPCODE_BLINK_COMMAND         0x06

// Score Updates (0x10–0x1F)
#define OPCODE_SCORE_UPDATE          0x10
#define OPCODE_SCORE_RESET           0x11
// #define OPCODE_SCORE_INCREMENT       0x12
// #define OPCODE_SCORE_DECREMENT       0x13

// LED/display commands (0x20–0x2F)
// #define OPCODE_ENTITY_COLOR			 0x20

// Hub-originated events (0x30–0x3F)
#define OPCODE_SESSION_STATUS 		 0x30
#define OPCODE_TARGET_SESSION_INFO	 0x31
#define OPCODE_TARGET_DISABLE 		 0x34
#define OPCODE_SHOW_TARGET_COLOR	 0x35
#define OPCODE_GAMEMODE_LITTARGET	 0x36

// Target-originated events (0x40–0x4F)
#define OPCODE_HIT_REQUEST           0x40

#endif
