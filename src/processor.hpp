//
// Created by shobhit on 26/10/23.
//

#ifndef INC_6502EMULATOR_PROCESSOR_HPP
#define INC_6502EMULATOR_PROCESSOR_HPP


#include <cstdint>

class Processor {

    // table to store how many cpu clock cycle is taken by a particular instruction
    // first index is the high nibble value
    // second index is the low nibble value
    int InstrTicksTable[16][16] = {
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {}
    };
public:
    uint16_t PC; // 16 bit Program Counter register
    uint8_t A;   // 8 bit Accumulator register
    uint8_t X;   // 8 bit Index register X specific to 6502
    uint8_t Y;   // 8 bit Index register Y specific to 6502
    uint8_t SP;  // 8 bit Stack Pointer register

    // 8 bit Flag Status register
    // from 7th to 0th bit
    // negative(N), overflow(O), reserved, break(B), decimal(D), interrupt disable(I), zero(Z), and carry(C) bit
    uint8_t FR;

    // cpu clock
    long cpuClock = 0;

    // Initialises the values of relevant registers before instruction fetch
    void VMInit();

    // increments the clock tick depending on opcode
    void updateClock(uint8_t opcode);

    // gives the location of top of the stack
    int retStackTopLoc();

    uint8_t lowNibble(uint8_t opcode);
    uint8_t highNibble(uint8_t opcode);

    void setNegativeBit();
    void setOverflowBit();
    void setBreakBit();
    void setDecimalBit();
    void setInterruptDisableBit();
    void setZeroBit();
    void setCarryBit();
};


#endif //INC_6502EMULATOR_PROCESSOR_HPP
