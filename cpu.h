// cpu.h
#ifndef CPU_H
#define CPU_H

#include <stdint.h>

// 6502 CPU structure
typedef struct cpu
{
    uint8_t A;    // Accumulator
    uint8_t X;    // X Register
    uint8_t Y;    // Y Register
    uint16_t PC;  // Program Counter
    uint8_t S;    // Stack Pointer
    
    //flags eli Processor status
    uint8_t C; // Carry flag
    uint8_t Z; // Zero flag
    uint8_t I; // Interrupt Disable flag
    uint8_t D; // Decimal flag
    uint8_t B; // Break flag //turha????
    uint8_t V; // Overflow flag
    uint8_t N; // Negative flag
} Cpu;
void loadROM(const char* rom_path);
void clockTick(Cpu* cpu);
void run(Cpu* cpu);
void start(Cpu* cpu);
void reset(Cpu* cpu);

#endif // CPU_H
