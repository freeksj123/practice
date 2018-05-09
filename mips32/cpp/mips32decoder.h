#ifndef MIPS32DECODER_H

#define MIPS32DECODER_H


#include "mips32opcode.h"

#include "mips32funct.h"



inline uint32_t getOpcode(uint32_t inst) { return inst >> 26; }
inline uint32_t getFunct(uint32_t inst) { return inst & 0b0111111; }
inline uint32_t getRS(uint32_t inst) { return (inst & 0b00000011111000000000000000000000) >> 21; }
inline uint32_t getRT(uint32_t inst) { return (inst & 0b00000000000111110000000000000000) >> 16; }
inline uint32_t getRD(uint32_t inst) { return (inst & 0b00000000000000001111100000000000) >> 11; }
inline uint32_t getImmediate(uint32_t inst) { return inst & 0b01111111111111111; }
inline uint32_t getShamt(uint32_t inst) { return (inst & 0b011111000000) >> 6; }
inline uint32_t getAddress(uint32_t inst) { return inst & 0b011111111111111111111111111; }

inline bool isADD(uint32_t opcode, uint32_t funct) { return opcode == SPECIAL && funct == ADD; }
inline bool isADDU(uint32_t opcode, uint32_t funct) { return opcode == SPECIAL && funct == ADDU; }
inline bool isSUB(uint32_t opcode, uint32_t funct) { return opcode == SPECIAL && funct == SUB; }
inline bool isSUBU(uint32_t opcode, uint32_t funct) { return opcode == SPECIAL && funct == SUBU; }
inline bool isADDI(uint32_t opcode) { return opcode == ADDI; }
inline bool isADDIU(uint32_t opcode) { return opcode == ADDIU; }
inline bool isMULT(uint32_t opcode, uint32_t funct) { return opcode == SPECIAL && funct == MULT; }
inline bool isMULTU(uint32_t opcode, uint32_t funct) { return opcode == SPECIAL && funct == MULTU; }
inline bool isDIV(uint32_t opcode, uint32_t funct) { return opcode == SPECIAL && funct == DIV; }
inline bool isDIVU(uint32_t opcode, uint32_t funct) { return opcode == SPECIAL && funct == DIVU; }
inline bool isLW(uint32_t opcode) { return opcode == LW; }
inline bool isLH(uint32_t opcode) { return opcode == LH; }
inline bool isLHU(uint32_t opcode) { return opcode == LHU; }
inline bool isLB(uint32_t opcode) { return opcode == LB; }
inline bool isLBU(uint32_t opcode) { return opcode == LBU; }
inline bool isSW(uint32_t opcode) { return opcode == SW; }
inline bool isSH(uint32_t opcode) { return opcode == SH; }
inline bool isSB(uint32_t opcode) { return opcode == SB; }
inline bool isLUI(uint32_t opcode) { return opcode == LUI; }
inline bool isMFUI(uint32_t opcode, uint32_t funct) { return opcode == SPECIAL && funct == MFUI; }
inline bool isMFLO(uint32_t opcode, uint32_t funct) { return opcode == SPECIAL && funct == MFLO; }
inline bool isMFCZ(uint32_t opcode, uint32_t funct) { return opcode == SPECIAL && funct == MFCZ; }
inline bool isMTCZ(uint32_t opcode, uint32_t funct) { return opcode == SPECIAL && funct == MTCZ; }
inline bool isAND(uint32_t opcode, uint32_t funct) { return opcode == SPECIAL && funct == AND; }
inline bool isANDI(uint32_t opcode, uint32_t funct) { return opcode == ANDI; }
inline bool isOR(uint32_t opcode, uint32_t funct) { return opcode == SPECIAL && funct == OR; }
inline bool isORI(uint32_t opcode) { return opcode == ORI; }
inline bool isXOR(uint32_t opcode, uint32_t funct) { return opcode == SPECIAL && funct == XOR; }
inline bool isXORI(uint32_t opcode) { return opcode == XORI; }
inline bool isNOR(uint32_t opcode, uint32_t funct) { return opcode == SPECIAL && funct == NOR; }
inline bool isSLT(uint32_t opcode, uint32_t funct) { return opcode == SPECIAL && funct == SLT; }
inline bool isSLTU(uint32_t opcode, uint32_t funct) { return opcode == SPECIAL && funct == SLTU; }
inline bool isSLTI(uint32_t opcode) { return opcode == SLTI; }
inline bool isSLL(uint32_t opcode, uint32_t funct) { return opcode == SPECIAL && funct == SLL; }
inline bool isSRL(uint32_t opcode, uint32_t funct) { return opcode == SPECIAL && funct == SRL; }
inline bool isSRA(uint32_t opcode, uint32_t funct) { return opcode == SPECIAL && funct == SRA; }
inline bool isSLLV(uint32_t opcode, uint32_t funct) { return opcode == SPECIAL && funct == SLLV; }
inline bool isSRLV(uint32_t opcode, uint32_t funct) { return opcode == SPECIAL && funct == SRLV; }
inline bool isSRAV(uint32_t opcode, uint32_t funct) { return opcode == SPECIAL && funct == SRAV; }
inline bool isBEQ(uint32_t opcode) { return opcode == BEQ; }
inline bool isBNE(uint32_t opcode) { return opcode == BNE; }
inline bool isJ(uint32_t opcode) { return opcode == J; }
inline bool isJR(uint32_t opcode, uint32_t funct) { return opcode == SPECIAL && funct == JR; }
inline bool isJAL(uint32_t opcode) { return opcode == JAL; }


#endif // MIPS32DECODER_H

