#include <stdint.h>
#include <stdio.h>
#include "cpu.h"
//6502 simulator try :/

#define MEMORY_SIZE 65536

uint8_t memory[MEMORY_SIZE];



int timer;
int time;
int delay;
void loadROM(const char* rom_path){
    
}
void LDA_Immediate(Cpu* cpu){
    printf("lda immidiate called\n");
    cpu->PC++;
    uint8_t value = memory[cpu->PC];
    cpu->A = value;

    cpu->Z = (cpu->A == 0);

    
    cpu->N = (cpu->A & 0x80) != 0;
    printf("Memory at A: 0x%02X\n", cpu->A);
    delay = 2;
}
void LDX_Immediate(Cpu* cpu){
    printf("ldX immidiate called\n");
    cpu->PC++;
    uint8_t value = memory[cpu->PC];
    cpu->X = value;

    cpu->Z = (cpu->X == 0);

    
    cpu->N = (cpu->X & 0x80) != 0;
    printf("Memory at X: 0x%02X\n", cpu->X);
    delay = 2;
}
void LDY_Immediate(Cpu* cpu){
    printf("ldy immidiate called\n");
    cpu->PC++;
    uint8_t value = memory[cpu->PC];
    cpu->Y = value;

    cpu->Z = (cpu->Y == 0);

    
    cpu->N = (cpu->Y & 0x80) != 0;
    printf("Memory at Y: 0x%02X\n", cpu->Y);
    delay = 2;
}
void LDA_Zero_Page(Cpu* cpu){
    printf("lda zero page called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t address = (uint16_t)zp_address;
    printf("Memory at right value???: 0x%02X\n", address);
    uint8_t value = memory[address];
    
    cpu->A = value;

    cpu->Z = (cpu->A == 0);

    
    cpu->N = (cpu->A & 0x80) != 0;
    printf("Memory at A: 0x%02X\n", cpu->A);
    delay = 3;
}
void LDX_Zero_Page(Cpu* cpu){
    printf("ldx zero page called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t address = (uint16_t)zp_address;
    printf("Memory at right value???: 0x%02X\n", address);
    uint8_t value = memory[address];
    
    cpu->X = value;

    cpu->Z = (cpu->X == 0);

    
    cpu->N = (cpu->X & 0x80) != 0;
    printf("Memory at X: 0x%02X\n", cpu->X);
    delay = 3;
}
void LDY_Zero_Page(Cpu* cpu){
    printf("ldy zero page called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t address = (uint16_t)zp_address;
    printf("Memory at right value???: 0x%02X\n", address);
    uint8_t value = memory[address];
    
    cpu->Y = value;

    cpu->Z = (cpu->Y == 0);

    
    cpu->N = (cpu->Y & 0x80) != 0;
    printf("Memory at Y: 0x%02X\n", cpu->Y);
    delay = 3;
}
void LDA_Zero_Page_X(Cpu* cpu) {
    printf("lda zero page X called\n");
    
    
    cpu->PC ++;
    printf("Calculated pc: 0x%02X\n", cpu->PC);
    
    uint8_t zp_address = memory[cpu->PC];
    uint16_t base_address = (uint16_t)zp_address;
    
    printf("Calculated baseaddress: 0x%02X\n", memory[cpu->PC]);
    
    uint8_t address = (base_address + cpu->X) & 0xFF;
    
    
    printf("Calculated address: 0x%02X\n", address);

   
    uint8_t value = memory[address];
    
    
    cpu->A = value;

    
    cpu->Z = (cpu->A == 0);

    
    cpu->N = (cpu->A & 0x80) != 0;

    
    printf("Memory at A: 0x%02X\n", cpu->A);
    delay = 4;
}
void LDX_Zero_Page_Y(Cpu* cpu) {
    printf("ldx zero page Y called\n");
    
    
    cpu->PC ++;
    printf("Calculated pc: 0x%02X\n", cpu->PC);
    
    uint8_t zp_address = memory[cpu->PC];
    uint16_t base_address = (uint16_t)zp_address;
    
    printf("Calculated baseaddress: 0x%02X\n", memory[cpu->PC]);
    
    uint8_t address = (base_address + cpu->Y) & 0xFF;
    
    
    printf("Calculated address: 0x%02X\n", address);

    
    uint8_t value = memory[address];
    
    
    cpu->X = value;

    
    cpu->Z = (cpu->X == 0);

    
    cpu->N = (cpu->X & 0x80) != 0;

    
    printf("Memory at X: 0x%02X\n", cpu->X);
    delay = 4;
}
void LDY_Zero_Page_X(Cpu* cpu) {
    printf("ldY zero page X called\n");
    
    
    cpu->PC ++;
    printf("Calculated pc: 0x%02X\n", cpu->PC);
    uint8_t zp_address = memory[cpu->PC];
    uint16_t base_address = (uint16_t)zp_address;
    
    printf("Calculated baseaddress: 0x%02X\n", memory[cpu->PC]);
    uint8_t address = (base_address + cpu->X) & 0xFF;
    
    printf("Calculated address: 0x%02X\n", address);

    uint8_t value = memory[address];
    
    cpu->Y = value;

    cpu->Z = (cpu->Y == 0);

    cpu->N = (cpu->Y & 0x80) != 0;

    printf("Memory at Y: 0x%02X\n", cpu->Y);
    delay = 4;
}
void LDA_Absolute(Cpu* cpu){
    printf("lda absolute called\n");
    
    cpu->PC ++;
    uint8_t low = memory[cpu->PC]; 
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];
    uint16_t address = (high << 8) | low;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];
    printf("value: 0x%02X\n", value);
    cpu->A = value;
    printf("Memory at A after lda absolute: 0x%02X\n", cpu->A);
    cpu->Z = (cpu->A == 0);

    
    cpu->N = (cpu->A & 0x80) != 0;
    delay = 4;
}
void LDX_Absolute(Cpu* cpu){
    printf("ldX absolute called\n");
    
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];
    uint16_t address = (high << 8) | low;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];
    printf("value: 0x%02X\n", value);
    cpu->X = value;
    printf("Memory at X after lda absolute: 0x%02X\n", cpu->X);
    cpu->Z = (cpu->X == 0);

    cpu->N = (cpu->X & 0x80) != 0;
    delay = 4;
}
void LDY_Absolute(Cpu* cpu){
    printf("ldy absolute called\n");
    
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];
    uint16_t address = (high << 8) | low;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];
    printf("value: 0x%02X\n", value);
    cpu->Y = value;
    printf("Memory at Y after lda absolute: 0x%02X\n", cpu->Y);
    cpu->Z = (cpu->Y == 0);

    cpu->N = (cpu->Y & 0x80) != 0;
    delay = 4;
}
void LDA_Absolute_X(Cpu* cpu){
    printf("lda absolute xxxxx called\n");
    
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];   
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];  
    uint16_t base = (high << 8) | low;
    printf("base: 0x%02X\n", base);
    uint16_t address = base + cpu->X;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];
    printf("value: 0x%02X\n", value);
    cpu->A = value;
    printf("Memory at A after lda absolute: 0x%02X\n", cpu->A);

    cpu->Z = (cpu->A == 0);

    cpu->N = (cpu->A & 0x80) != 0;
    delay = 4;
    if ((base & 0xFF00) != (address & 0xFF00)) {
        printf("Page boundary crossed!\n");
        delay++;  
    }

}
void LDY_Absolute_X(Cpu* cpu){
    printf("lda absolute xxxxx called\n");
    
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];   
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];  
    uint16_t base = (high << 8) | low;
    printf("base: 0x%02X\n", base);
    uint16_t address = base + cpu->X ;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];
    printf("value: 0x%02X\n", value);
    cpu->Y = value;
    printf("Memory at A after lda absolute: 0x%02X\n", cpu->Y);

    cpu->Z = (cpu->Y == 0);


    cpu->N = (cpu->Y & 0x80) != 0;
    delay = 4;
    if ((base & 0xFF00) != (address & 0xFF00)) {
        printf("Page boundary crossed!\n");
        delay++;  
    }
}
void LDA_Absolute_Y(Cpu* cpu){
    printf("lda absolute yyyy called\n");
    
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];   
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];  
    uint16_t base = (high << 8) | low;
    printf("base: 0x%02X\n", base);
    uint16_t address = base + cpu->Y;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];
    printf("value: 0x%02X\n", value);
    cpu->A = value;
    printf("Memory at A after lda absolute: 0x%02X\n", cpu->A);

    cpu->Z = (cpu->A == 0);


    cpu->N = (cpu->A & 0x80) != 0;
    delay = 4;
    if ((base & 0xFF00) != (address & 0xFF00)) {
        printf("Page boundary crossed!\n");
        delay++;  
    }
}
void LDX_Absolute_Y(Cpu* cpu){
    printf("ldx absolute YYYY called\n");
    
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];   
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];  
    uint16_t base = (high << 8) | low;
    printf("base: 0x%02X\n", base);
    uint16_t address = base + cpu->Y;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];
    printf("value: 0x%02X\n", value);
    cpu->X = value;
    printf("Memory at A after ldx absolute: 0x%02X\n", cpu->X);

    cpu->Z = (cpu->X == 0);

    cpu->N = (cpu->X & 0x80) != 0;
    delay = 4;
    if ((base & 0xFF00) != (address & 0xFF00)) {
        printf("Page boundary crossed!\n");
        delay++;  
    }
}
void LDA_Indirect_X(Cpu* cpu){
    printf("lda indirect  xxxx called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    printf("zp: 0x%02X\n", zp_address);
    uint16_t base_address = (uint16_t)zp_address;
    printf("base addressss: 0x%02X\n", base_address);
    uint16_t addressAfterX = base_address + cpu->X;
    printf(" addressAfterX: 0x%02X\n", addressAfterX);
    uint8_t low = memory[addressAfterX];  
    printf(" low: 0x%02X\n", addressAfterX);
    addressAfterX++;
    uint8_t high = memory[addressAfterX];
    printf(" high: 0x%02X\n", addressAfterX);
    uint16_t base = (high << 8) | low;
    printf("Memory address at base in lda indirect X: 0x%02X\n", base);
    uint8_t value = memory[base];
    cpu->A = value;

    printf("Memory at A after lda indirect X: 0x%02X\n", cpu->A);

    cpu->Z = (cpu->A == 0);

    cpu->N = (cpu->A & 0x80) != 0;
    delay = 6;
}
void LDA_Indirect_Y(Cpu* cpu) {
    printf("lda indirect Y called\n");

    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    printf("zp: 0x%02X\n", zp_address);

    uint8_t low = memory[zp_address];
    uint8_t high = memory[(uint8_t)(zp_address + 1)];
    uint16_t base = (high << 8) | low;
    printf("Base address from zero page: 0x%04X\n", base);

    uint16_t address = base + cpu->Y;
    printf("Final address after adding Y: 0x%04X\n", address);

    uint8_t value = memory[address];
    cpu->A = value;
    printf("Loaded value into A: 0x%02X\n", cpu->A);


    cpu->Z = (cpu->A == 0);
    cpu->N = (cpu->A & 0x80) != 0;


    delay = 5;

    if ((base & 0xFF00) != (address & 0xFF00)) {
        printf("Page boundary crossed!\n");
        delay++;
    }
}
//adc ja sbc alkaa
void ADC_Immediate(Cpu* cpu) {
    cpu->PC++; 
    uint8_t M = memory[cpu->PC];
    uint16_t result = cpu->A + M + cpu->C;

    cpu->V = (~(cpu->A ^ M) & (cpu->A ^ result) & 0x80) != 0;

    if (result == 0) {
        cpu->Z = 1; 
    } else {
        cpu->Z = 0;  
    }

    if (result > 0xFF) {
        cpu->C = 1;  
    } else {
        cpu->C = 0;  
    }

    cpu->A = (uint8_t) result;

    printf("Memory at A after ADC Immediate: 0x%02X\n", cpu->A);
    delay = 2;
}
void SBC_Immediate(Cpu* cpu) {
    cpu->PC++; 
    uint8_t M = memory[cpu->PC];
    uint16_t result = cpu->A + ~M + cpu->C;

    cpu->V = (~(cpu->A ^ M) & (cpu->A ^ result) & 0x80) != 0;

    if (result == 0) {
        cpu->Z = 1; 
    } else {
        cpu->Z = 0;  
    }

    if (result > 0xFF) {
        cpu->C = 1;  
    } else {
        cpu->C = 0;  
    }

    cpu->A = (uint8_t) result;

    printf("Memory at A after SBC Immediate: 0x%02X\n", cpu->A);
    delay = 2;
}
void ADC_Absolute(Cpu* cpu){

    cpu->PC ++;
    uint8_t low = memory[cpu->PC];   
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];  
    uint16_t base = (high << 8) | low;
    uint8_t M = memory[base];
    uint16_t result = cpu->A + M + cpu->C;

    cpu->V = (~(cpu->A ^ M) & (cpu->A ^ result) & 0x80) != 0;

    if (result == 0) {
        cpu->Z = 1; 
    } else {
        cpu->Z = 0;  
    }

    if (result > 0xFF) {
        cpu->C = 1;  
    } else {
        cpu->C = 0;  
    }

    cpu->A = (uint8_t) result;

    printf("Memory at A after ADC absolute: 0x%02X\n", cpu->A);
    delay = 4;
}
void SBC_Absolute(Cpu* cpu){

    cpu->PC ++;
    uint8_t low = memory[cpu->PC];   
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];  
    uint16_t base = (high << 8) | low;
    uint8_t M = memory[base];
    uint16_t result = cpu->A + ~M + cpu->C;

    cpu->V = (~(cpu->A ^ M) & (cpu->A ^ result) & 0x80) != 0;

    if (result == 0) {
        cpu->Z = 1; 
    } else {
        cpu->Z = 0;  
    }

    if (result > 0xFF) {
        cpu->C = 1;  
    } else {
        cpu->C = 0;  
    }

    cpu->A = (uint8_t) result;

    printf("Memory at A after SBC absolute: 0x%02X\n", cpu->A);
    delay = 4;
}
void ADC_Zero_Page(Cpu* cpu){
    printf("adc zero page called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t address = (uint16_t)zp_address;
    printf("Memory at right value???: 0x%02X\n", address);
    uint8_t M = memory[address];
    
    uint16_t result = cpu->A + M + cpu->C;

    cpu->V = (~(cpu->A ^ M) & (cpu->A ^ result) & 0x80) != 0;

    if (result == 0) {
        cpu->Z = 1; 
    } else {
        cpu->Z = 0;  
    }

    if (result > 0xFF) {
        cpu->C = 1;  
    } else {
        cpu->C = 0;  
    }

    cpu->A = (uint8_t) result;

    printf("Memory at A after ADC zero page: 0x%02X\n", cpu->A);
    delay = 3;
}
void SBC_Zero_Page(Cpu* cpu){

    printf("SBC zero page called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t address = (uint16_t)zp_address;
    printf("Memory at right value???: 0x%02X\n", address);
    uint8_t M = memory[address];
    
    uint16_t result = cpu->A + ~M + cpu->C;

    cpu->V = (~(cpu->A ^ M) & (cpu->A ^ result) & 0x80) != 0;

    if (result == 0) {
        cpu->Z = 1; 
    } else {
        cpu->Z = 0;  
    }

    if (result > 0xFF) {
        cpu->C = 1;  
    } else {
        cpu->C = 0;  
    }

    cpu->A = (uint8_t) result;

    printf("Memory at A after SBC zero page: 0x%02X\n", cpu->A);
    delay = 3;
}

void ADC_Indirect_X(Cpu* cpu) {
    printf("adc indirect xxxx called\n");

    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    printf("zp: 0x%02X\n", zp_address);

    uint8_t addressAfterX = (zp_address + cpu->X) & 0xFF;
    printf("addressAfterX: 0x%02X\n", addressAfterX);

    uint8_t low = memory[addressAfterX];
    uint8_t high = memory[(addressAfterX + 1) & 0xFF]; 
    printf("low: 0x%02X\n", low);
    printf("high: 0x%02X\n", high);

    uint16_t effective_address = ((uint16_t)high << 8) | low;
    printf("Memory address at base in lda indirect X: 0x%04X\n", effective_address);

    uint8_t M = memory[effective_address];
    printf("A before: 0x%02X, M: 0x%02X, C: %d\n", cpu->A, M, cpu->C);

    uint16_t result = cpu->A + M + cpu->C;

    cpu->V = (~(cpu->A ^ M) & (cpu->A ^ result) & 0x80) != 0;
    cpu->Z = ((uint8_t)result == 0);
    cpu->C = (result > 0xFF);

    cpu->A = (uint8_t)result;
    printf("Memory at A after ADC indirect X: 0x%02X\n", cpu->A);
    delay = 6;
}
void SBC_Indirect_X(Cpu* cpu) {
    printf("SBC indirect xxxx called\n"); 

    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    printf("zp: 0x%02X\n", zp_address);

    uint8_t addressAfterX = (zp_address + cpu->X) & 0xFF;
    printf("addressAfterX: 0x%02X\n", addressAfterX);

    uint8_t low = memory[addressAfterX];
    uint8_t high = memory[(addressAfterX + 1) & 0xFF]; 
    printf("low: 0x%02X\n", low);
    printf("high: 0x%02X\n", high);

    uint16_t effective_address = ((uint16_t)high << 8) | low;
    printf("Memory address at base in lda indirect X: 0x%04X\n", effective_address);

    uint8_t M = memory[effective_address];
    printf("A before: 0x%02X, M: 0x%02X, C: %d\n", cpu->A, M, cpu->C);

    uint16_t result = cpu->A + ~M + cpu->C;

    cpu->V = (~(cpu->A ^ M) & (cpu->A ^ result) & 0x80) != 0;
    cpu->Z = ((uint8_t)result == 0);
    cpu->C = (result > 0xFF);

    cpu->A = (uint8_t)result;
    printf("Memory at A after SBC indirect X: 0x%02X\n", cpu->A);
    delay = 6;
}
void ADC_Indirect_Y(Cpu* cpu){
    printf("adc indirect  YYYYYY called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    printf("zp: 0x%02X\n", zp_address);
    uint16_t base_address = (uint16_t)zp_address;
    printf("base addressss: 0x%02X\n", base_address);
    uint16_t addressAfterX = base_address + cpu->Y;
    printf(" addressAfterX: 0x%02X\n", addressAfterX);

    uint8_t low = memory[addressAfterX];  
    printf(" low: 0x%02X\n", addressAfterX);
    addressAfterX++;
    uint8_t high = memory[addressAfterX];
    printf(" high: 0x%02X\n", addressAfterX);
    uint16_t base = (high << 8) | low;
    uint16_t effective_address = base + cpu->Y;
    if ((base & 0xFF00) != (effective_address & 0xFF00)) {
        printf("Page boundary crossed!\n");
        delay = 6; 
    } else {
        delay = 5;
    }
    printf("Memory address at base in lda indirect Y: 0x%02X\n", base);
    uint8_t M = memory[base];
    
    uint16_t result = cpu->A + M + cpu->C;

    cpu->V = (~(cpu->A ^ M) & (cpu->A ^ result) & 0x80) != 0;

    if (result == 0) {
        cpu->Z = 1; 
    } else {
        cpu->Z = 0;  
    }

    if (result > 0xFF) {
        cpu->C = 1;  
    } else {
        cpu->C = 0;  
    }

    cpu->A = (uint8_t) result;

    printf("Memory at A after ADC indirect X: 0x%02X\n", cpu->A);
}
void SBC_Indirect_Y(Cpu* cpu){
    printf("SBC indirect  YYYYYY called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    printf("zp: 0x%02X\n", zp_address);
    uint16_t base_address = (uint16_t)zp_address;
    printf("base addressss: 0x%02X\n", base_address);
    uint16_t addressAfterX = base_address + cpu->Y;
    printf(" addressAfterX: 0x%02X\n", addressAfterX);

    uint8_t low = memory[addressAfterX];  
    printf(" low: 0x%02X\n", addressAfterX);
    addressAfterX++;
    uint8_t high = memory[addressAfterX];
    printf(" high: 0x%02X\n", addressAfterX);
    uint16_t base = (high << 8) | low;
    printf("Memory address at base in lda indirect Y: 0x%02X\n", base);
    uint16_t effective_address = base + cpu->Y;


    if ((base & 0xFF00) != (effective_address & 0xFF00)) {
        printf("Page boundary crossed!\n");
        delay = 6; 
    } else {
        delay = 5;
    }
    uint8_t M = memory[base];
    
    uint16_t result = cpu->A + ~M + cpu->C;

    cpu->V = (~(cpu->A ^ M) & (cpu->A ^ result) & 0x80) != 0;

    if (result == 0) {
        cpu->Z = 1; 
    } else {
        cpu->Z = 0;  
    }

    if (result > 0xFF) {
        cpu->C = 1;  
    } else {
        cpu->C = 0;  
    }

    cpu->A = (uint8_t) result;

    printf("Memory at A after SBC indirect X: 0x%02X\n", cpu->A);
}
void ADC_Zero_Page_X(Cpu* cpu){
    printf("adc zero page X called\n");

    cpu->PC++;
    printf("Calculated pc: 0x%02X\n", cpu->PC);


    uint8_t zp_address = memory[cpu->PC];
    printf("Base address from instruction: 0x%02X\n", zp_address);

    uint8_t address = (zp_address + cpu->X) & 0xFF;
    printf("Calculated zero page address: 0x%02X\n", address);

    uint8_t M = memory[address];
    printf("Memory value at address: 0x%02X\n", M);

    uint16_t result = cpu->A + M + cpu->C;
    printf("A before: 0x%02X, C: %d -> Result: 0x%04X\n", cpu->A, cpu->C, result);


    cpu->V = (~(cpu->A ^ M) & (cpu->A ^ result) & 0x80) != 0; 
    cpu->C = (result > 0xFF);
    cpu->Z = ((uint8_t)result == 0); 
    cpu->N = ((result & 0x80) != 0); 

    cpu->A = (uint8_t)result;

    printf("Memory at A after ADC: 0x%02X\n", cpu->A);
    delay = 4;
}
void SBC_Zero_Page_X(Cpu* cpu){
    printf("SBC zero page X called\n");

    cpu->PC++;
    printf("Calculated pc: 0x%02X\n", cpu->PC);

    uint8_t zp_address = memory[cpu->PC];
    printf("Base address from instruction: 0x%02X\n", zp_address);

    uint8_t address = (zp_address + cpu->X) & 0xFF;
    printf("Calculated zero page address: 0x%02X\n", address);

    uint8_t M = memory[address];
    printf("Memory value at address: 0x%02X\n", M);

    uint16_t result = cpu->A + ~M + cpu->C;
    printf("A before: 0x%02X, C: %d -> Result: 0x%04X\n", cpu->A, cpu->C, result);

    cpu->V = (~(cpu->A ^ M) & (cpu->A ^ result) & 0x80) != 0;
    cpu->C = (result > 0xFF);
    cpu->Z = ((uint8_t)result == 0);
    cpu->N = ((result & 0x80) != 0); 


    cpu->A = (uint8_t)result;

    printf("Memory at A after SBC: 0x%02X\n", cpu->A);
    delay = 4;
}
void ADC_Absolute_X(Cpu* cpu){
    printf("adc absolute X called\n");

    cpu->PC++;
    uint8_t low = memory[cpu->PC];
    cpu->PC++;
    uint8_t high = memory[cpu->PC];

    uint16_t base_address = (high << 8) | low;
    printf("Base address: 0x%04X\n", base_address);

    uint16_t address = base_address + cpu->X;
    if ((base_address & 0xFF00) != (address & 0xFF00)) {
        printf("Page boundary crossed!\n");
        delay = 5;
    } else {
        delay = 4;
    }
    printf("Address after adding X: 0x%04X\n", address);

    uint8_t M = memory[address];
    printf("Memory value at address: 0x%02X\n", M);

    uint16_t result = cpu->A + M + cpu->C;
    printf("A before: 0x%02X, C: %d -> Result: 0x%04X\n", cpu->A, cpu->C, result);

    cpu->V = (~(cpu->A ^ M) & (cpu->A ^ result) & 0x80) != 0;
    cpu->C = (result > 0xFF);
    cpu->Z = ((uint8_t)result == 0);
    cpu->N = ((result & 0x80) != 0);

    cpu->A = (uint8_t)result;

    printf("Memory at A after ADC: 0x%02X\n", cpu->A);
}
void SBC_Absolute_X(Cpu* cpu){
    printf("SBC absolute X called\n");

    cpu->PC++;
    uint8_t low = memory[cpu->PC];
    cpu->PC++;
    uint8_t high = memory[cpu->PC];

    uint16_t base_address = (high << 8) | low;
    printf("Base address: 0x%04X\n", base_address);

    uint16_t address = base_address + cpu->X;
    printf("Address after adding X: 0x%04X\n", address);
    
    
    if ((base_address & 0xFF00) != (address & 0xFF00)) {
        printf("Page boundary crossed!\n");
        delay = 5;
    } else {
        delay = 4;
    }

    uint8_t M = memory[address];
    printf("Memory value at address: 0x%02X\n", M);


    uint16_t result = cpu->A + ~M + cpu->C;
    printf("A before: 0x%02X, C: %d -> Result: 0x%04X\n", cpu->A, cpu->C, result);


    cpu->V = (~(cpu->A ^ M) & (cpu->A ^ result) & 0x80) != 0;
    cpu->C = (result > 0xFF);
    cpu->Z = ((uint8_t)result == 0);
    cpu->N = ((result & 0x80) != 0);


    cpu->A = (uint8_t)result;

    printf("Memory at A after SBC: 0x%02X\n", cpu->A);
}

void ADC_Absolute_Y(Cpu* cpu){
    printf("adc absolute X called\n");

    cpu->PC++;
    uint8_t low = memory[cpu->PC];
    cpu->PC++;
    uint8_t high = memory[cpu->PC];
    
    uint16_t base_address = (high << 8) | low;
    printf("Base address: 0x%04X\n", base_address);

    uint16_t address = base_address + cpu->Y;
    printf("Address after adding X: 0x%04X\n", address);
    if ((base_address & 0xFF00) != (address & 0xFF00)) {
        printf("Page boundary crossed!\n");
        delay = 5;
    } else {
        delay = 4;
    }

    uint8_t M = memory[address];
    printf("Memory value at address: 0x%02X\n", M);

    uint16_t result = cpu->A + M + cpu->C;
    printf("A before: 0x%02X, C: %d -> Result: 0x%04X\n", cpu->A, cpu->C, result);

    cpu->V = (~(cpu->A ^ M) & (cpu->A ^ result) & 0x80) != 0;
    cpu->C = (result > 0xFF);
    cpu->Z = ((uint8_t)result == 0);
    cpu->N = ((result & 0x80) != 0);

    cpu->A = (uint8_t)result;
    
    printf("Memory at A after ADC: 0x%02X\n", cpu->A);
    
}
void SBC_Absolute_Y(Cpu* cpu){
    printf("SBC absolute X called\n");

    cpu->PC++;
    uint8_t low = memory[cpu->PC];
    cpu->PC++;
    uint8_t high = memory[cpu->PC];
    
    uint16_t base_address = (high << 8) | low;
    printf("Base address: 0x%04X\n", base_address);

    uint16_t address = base_address + cpu->Y;
    printf("Address after adding X: 0x%04X\n", address);
    if ((base_address & 0xFF00) != (address & 0xFF00)) {
        printf("Page boundary crossed!\n");
        delay = 5;
    } else {
        delay = 4;
    }

    uint8_t M = memory[address];
    printf("Memory value at address: 0x%02X\n", M);

    uint16_t result = cpu->A + ~M + cpu->C;
    printf("A before: 0x%02X, C: %d -> Result: 0x%04X\n", cpu->A, cpu->C, result);

    cpu->V = (~(cpu->A ^ M) & (cpu->A ^ result) & 0x80) != 0;
    cpu->C = (result > 0xFF);
    cpu->Z = ((uint8_t)result == 0);
    cpu->N = ((result & 0x80) != 0);

    cpu->A = (uint8_t)result;
    
    printf("Memory at A after SBC: 0x%02X\n", cpu->A);
}
void JMP_Absolute(Cpu* cpu) {
    printf("JMP absolute CALLED\n");
    cpu->PC++;
    uint8_t low = memory[cpu->PC];
    cpu->PC++;
    uint8_t high = memory[cpu->PC];
    uint16_t address = (high << 8) | low;
    cpu->PC = address;

    printf("PC after JMP ABSOLUTE: 0x%02X\n", cpu->PC);
    delay = 3;
}
void JMP_Indirect(Cpu* cpu){
    printf("JMP indirect CALLED\n");
    cpu->PC++;
    uint8_t low = memory[cpu->PC];
    cpu->PC++;
    uint8_t high = memory[cpu->PC];
    uint16_t address = (high << 8) | low;
    cpu->PC = address;

    low = memory[cpu->PC];
    cpu->PC++;
    high = memory[cpu->PC];
    address = (high << 8) | low; 
    cpu->PC = address;
    printf("PC after JMP indirect: 0x%02X\n", cpu->PC);
    delay = 5;
}

void JSR_Absolute(Cpu* cpu) {
    printf("JSR ABSOLUTE CALLED\n");

    uint16_t returnAddress = cpu->PC + 2  ;

    memory[0x0100 + cpu->S--] = (uint8_t)(returnAddress & 0xFF);        
    memory[0x0100 + cpu->S--] = (uint8_t)((returnAddress >> 8) & 0xFF); 
    cpu->PC++;
    uint8_t low  = memory[cpu->PC++];
    uint8_t high = memory[cpu->PC++];
    uint16_t address = (high << 8) | low;

    cpu->PC = address;
    uint8_t pushedLow  = memory[0x0100 + cpu->S + 2];
    uint8_t pushedHigh = memory[0x0100 + cpu->S + 1];
    uint16_t pushedAddress = (pushedHigh << 8) | pushedLow;
    printf("Return address pushed to stack: 0x%04X\n", pushedAddress);
    printf("Stack pointer after push: 0x%02X\n", cpu->S);
    
    printf("PC after JSR ABSOLUTE: 0x%04X\n", cpu->PC);
    delay = 6;
}

void RTS_Implied(Cpu* cpu){
    uint8_t low = memory[0x0100 + cpu->S++];
    uint8_t high = memory[0x0100 + cpu->S++];

    uint16_t address = (high << 8) | low;
    cpu->PC = address;
    cpu->PC++;
    delay = 6;
}
void CMP_Immediate(Cpu* cpu) {
    printf("CMP Immidiate called at %d\n",cpu->PC);
    cpu->PC++;
    uint8_t value = memory[cpu->PC];

    uint8_t result = cpu->A - value;

    cpu->C = (cpu->A >= value) ? 1 : 0;

    cpu->Z = (cpu->A == value) ? 1 : 0;

    cpu->N = (result & 0x80) ? 1 : 0;

    printf("Flags after CMP immediate - C: %d Z: %d N: %d\n", cpu->C, cpu->Z, cpu->N);
    delay = 2;
}
void CMP_Zero_Page(Cpu* cpu){
    printf("CMP zero page called at %d\n",cpu->PC);
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t address = (uint16_t)zp_address;
    printf("Memory at right value???: 0x%02X\n", address);
    uint8_t value = memory[address];

    uint8_t result = cpu->A - value;

    cpu->C = (cpu->A >= value) ? 1 : 0;

    cpu->Z = (cpu->A == value) ? 1 : 0;

    cpu->N = (result & 0x80) ? 1 : 0;

    printf("Flags after CMP zero page - C: %d Z: %d N: %d\n", cpu->C, cpu->Z, cpu->N);
    delay = 3;
}
void CMP_Zero_Page_X(Cpu* cpu){
    printf("CMP zero page X called at %d\n",cpu->PC);
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t base_address = (uint16_t)zp_address;
    uint8_t address = (base_address + cpu->X) & 0xFF;
    printf("Memory at right value???: 0x%02X\n", address);
    uint8_t value = memory[address];

    uint8_t result = cpu->A - value;

    cpu->C = (cpu->A >= value) ? 1 : 0;

    cpu->Z = (cpu->A == value) ? 1 : 0;

    cpu->N = (result & 0x80) ? 1 : 0;

    printf("Flags after CMP zero page X - C: %d Z: %d N: %d\n", cpu->C, cpu->Z, cpu->N);
    delay = 4;
}

void CMP_Absolute(Cpu* cpu){
    printf("CMP absolute called at %d\n",cpu->PC);
    
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];
    cpu->PC ++;
    uint8_t high = memory[cpu->PC]; 
    uint16_t address = (high << 8) | low;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];

    uint8_t result = cpu->A - value;

    cpu->C = (cpu->A >= value) ? 1 : 0;

    cpu->Z = (cpu->A == value) ? 1 : 0;

    cpu->N = (result & 0x80) ? 1 : 0;

    printf("Flags after CMP absolute - C: %d Z: %d N: %d\n", cpu->C, cpu->Z, cpu->N);
    delay = 4;
}
void CMP_Absolute_X(Cpu* cpu){
    printf("CMP absolute x called at %d\n",cpu->PC);
    
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];
    uint16_t base_address = (high << 8) | low;
    
    uint16_t address = base_address + cpu->X;
    if ((base_address & 0xFF00) != (address & 0xFF00)) {
        printf("Page boundary crossed!\n");
        delay = 5;
    } else {
        delay = 4;
    }
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];

    uint8_t result = cpu->A - value;

    cpu->C = (cpu->A >= value) ? 1 : 0;

    cpu->Z = (cpu->A == value) ? 1 : 0;

    cpu->N = (result & 0x80) ? 1 : 0;

    printf("Flags after CMP absolute x - C: %d Z: %d N: %d\n", cpu->C, cpu->Z, cpu->N);
}
void CMP_Absolute_Y(Cpu* cpu){
    printf("CMP absolute y called at %d\n",cpu->PC);
    
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];
    uint16_t base_address = (high << 8) | low;
    
    uint16_t address = base_address + cpu->Y;
    printf("address: 0x%02X\n", address);
    if ((base_address & 0xFF00) != (address & 0xFF00)) {
        printf("Page boundary crossed!\n");
        delay = 5;
    } else {
        delay = 4;
    }
    uint8_t value = memory[address];

    uint8_t result = cpu->A - value;

    cpu->C = (cpu->A >= value) ? 1 : 0;

    cpu->Z = (cpu->A == value) ? 1 : 0;

    cpu->N = (result & 0x80) ? 1 : 0;

    printf("Flags after CMP absolute y - C: %d Z: %d N: %d\n", cpu->C, cpu->Z, cpu->N);
}
void CMP_Indirect_X(Cpu* cpu){
    printf("CMP indirect x called at %d\n",cpu->PC);
    
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];
    cpu->PC ++;
    uint8_t high = memory[cpu->PC]; 
    uint16_t base_address = (high << 8) | low;
    
    uint16_t address = base_address + cpu->X;
    printf("address: 0x%02X\n", address);
    uint8_t realaddress = memory[address];
    uint8_t value = memory[realaddress];
    uint8_t result = cpu->A - value;

    cpu->C = (cpu->A >= value) ? 1 : 0;

    cpu->Z = (cpu->A == value) ? 1 : 0;

    cpu->N = (result & 0x80) ? 1 : 0;

    printf("Flags after CMP indirect x - C: %d Z: %d N: %d\n", cpu->C, cpu->Z, cpu->N);
    delay = 6;
}
void CMP_Indirect_Y(Cpu* cpu){
    printf("CMP indirect y called at %d\n",cpu->PC);
    
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];
    uint16_t base_address = (high << 8) | low;
    
    uint16_t address = base_address + cpu->Y;

    if ((base_address & 0xFF00) != (address & 0xFF00)) {
        printf("Page boundary crossed!\n");
        delay = 6;
    } else {
        delay = 5;
    }

    printf("address: 0x%02X\n", address);
    uint8_t realaddress = memory[address];
    uint8_t value = memory[realaddress];
    uint8_t result = cpu->A - value;

    cpu->C = (cpu->A >= value) ? 1 : 0;

    cpu->Z = (cpu->A == value) ? 1 : 0;

    cpu->N = (result & 0x80) ? 1 : 0;

    printf("Flags after CMP indirect Y - C: %d Z: %d N: %d\n", cpu->C, cpu->Z, cpu->N);
    
}
void CPY_Immediate(Cpu* cpu){
    printf("CPY Immidiate called at %d\n",cpu->PC);
    cpu->PC++;
    uint8_t value = memory[cpu->PC];

    uint8_t result = cpu->Y - value;

    cpu->C = (cpu->Y >= value) ? 1 : 0;

    cpu->Z = (cpu->Y == value) ? 1 : 0;

    cpu->N = (result & 0x80) ? 1 : 0;

    printf("Flags after CPY immediate - C: %d Z: %d N: %d\n", cpu->C, cpu->Z, cpu->N);
    delay = 2;
}
void CPY_Zero_Page(Cpu* cpu){
    printf("CPY zero page called at %d\n",cpu->PC);
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t address = (uint16_t)zp_address;
    printf("Memory at right value???: 0x%02X\n", address);
    uint8_t value = memory[address];

    uint8_t result = cpu->Y - value;

    cpu->C = (cpu->Y >= value) ? 1 : 0;

    cpu->Z = (cpu->Y == value) ? 1 : 0;

    cpu->N = (result & 0x80) ? 1 : 0;

    printf("Flags after CPY zero page - C: %d Z: %d N: %d\n", cpu->C, cpu->Z, cpu->N);
    delay = 3;
}
void CPY_Absolute(Cpu* cpu){
    printf("CPY absolute called at %d\n",cpu->PC);
    
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];
    uint16_t address = (high << 8) | low;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];

    uint8_t result = cpu->Y - value;

    cpu->C = (cpu->Y >= value) ? 1 : 0;

    cpu->Z = (cpu->Y == value) ? 1 : 0;

    cpu->N = (result & 0x80) ? 1 : 0;

    printf("Flags after CPY absolute - C: %d Z: %d N: %d\n", cpu->C, cpu->Z, cpu->N);
    delay = 4;
}
void CPX_Immediate(Cpu* cpu){
    printf("CPX Immidiate called at %d\n",cpu->PC);
    cpu->PC++;
    uint8_t value = memory[cpu->PC];

    uint8_t result = cpu->X - value;

    cpu->C = (cpu->X >= value) ? 1 : 0;

    cpu->Z = (cpu->X == value) ? 1 : 0;

    cpu->N = (result & 0x80) ? 1 : 0;

    printf("Flags after CPX immediate - C: %d Z: %d N: %d\n", cpu->C, cpu->Z, cpu->N);
    delay = 2;
}
void CPX_Zero_Page(Cpu* cpu){
    printf("CPX zero page called at %d\n",cpu->PC);
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t address = (uint16_t)zp_address;
    printf("Memory at right value???: 0x%02X\n", address);
    uint8_t value = memory[address];

    uint8_t result = cpu->X - value;

    cpu->C = (cpu->X >= value) ? 1 : 0;

    cpu->Z = (cpu->X == value) ? 1 : 0;

    cpu->N = (result & 0x80) ? 1 : 0;

    printf("Flags after CPX zero page - C: %d Z: %d N: %d\n", cpu->C, cpu->Z, cpu->N);
    delay = 3;
}
void CPX_Absolute(Cpu* cpu){
    printf("CPX absolute called at %d\n",cpu->PC);
    
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];
    uint16_t address = (high << 8) | low;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];

    uint8_t result = cpu->X - value;

    cpu->C = (cpu->X >= value) ? 1 : 0;

    cpu->Z = (cpu->X == value) ? 1 : 0;

    cpu->N = (result & 0x80) ? 1 : 0;

    printf("Flags after CPX absolute - C: %d Z: %d N: %d\n", cpu->C, cpu->Z, cpu->N);
    delay = 4;
}
void STA_Zero_Page(Cpu* cpu){
    printf("STA zero page called at %d\n",cpu->PC);
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t address = (uint16_t)zp_address;
    printf("Memory at right value???: 0x%02X\n", address);
    memory[address] = cpu->A;
    printf("Value at memory[0x0010]: 0x%02X\n", memory[0x0010]);
    delay = 3;
}
void STA_Zero_Page_X(Cpu* cpu){
    printf("STA zero page X called at %d\n",cpu->PC);
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t base_address = (uint16_t)zp_address;
    uint8_t address = (base_address + cpu->X) & 0xFF;
    printf("Memory at right value???: 0x%02X\n", address);
    memory[address] = cpu->A;
    printf("Value at memory[0x0010]: 0x%02X\n", memory[0x0015]);
    delay = 4;
}
void STA_Absolute(Cpu* cpu){
    printf("STA absolute called at %d\n",cpu->PC);
    cpu->PC ++;
    uint8_t low = memory[cpu->PC]; 
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];
    uint16_t address = (high << 8) | low;

    memory[address] = cpu->A;

    printf("Value at memory[0x0010]: 0x%02X\n", memory[0x2000]);
    delay = 4;
}
void STA_Absolute_X(Cpu* cpu){
    printf("STA absolute X called at %d\n",cpu->PC);
    cpu->PC ++;
    uint8_t low = memory[cpu->PC]; 
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];
    
    uint16_t base = (high << 8) | low;
    uint16_t address = base + cpu->X;
    memory[address] = cpu->A;

    printf("Value at memory[0x0010]: 0x%02X\n", memory[0x2005]);
    delay = 5;
}
void STA_Absolute_Y(Cpu* cpu){
    printf("STA absolute Y called at %d\n",cpu->PC);
    cpu->PC ++;
    uint8_t low = memory[cpu->PC]; 
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];
    
    uint16_t base = (high << 8) | low;
    uint16_t address = base + cpu->Y;
    memory[address] = cpu->A;

    printf("Value at memory[0x0010]: 0x%02X\n", memory[0x2005]);
    delay = 5;
}
void STA_Indirect_X(Cpu* cpu){
    printf("STA indirect X called at %d\n",cpu->PC);
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];
    uint16_t base_address = (high << 8) | low;

    uint16_t address = base_address + cpu->X;
    printf("address: 0x%02X\n", address);
    cpu->PC = address;
    low = memory[cpu->PC];
    cpu->PC++;
    high = memory[cpu->PC];

    base_address = (high << 8) | low;
    printf("address: 0x%02X\n", base_address);
    memory[base_address] = cpu->A;

    printf("Value at memory[0x2000]: 0x%02X\n", memory[0x2000]);
    delay = 6;
}
void STA_Indirect_Y(Cpu* cpu){
    printf("STA indirect Y called at %d\n",cpu->PC);
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];
    uint16_t base_address = (high << 8) | low;

    uint16_t address = base_address + cpu->Y;
    printf("address: 0x%02X\n", address);
    cpu->PC = address;
    low = memory[cpu->PC];
    cpu->PC++;
    high = memory[cpu->PC];

    base_address = (high << 8) | low;
    printf("address: 0x%02X\n", base_address);
    memory[base_address] = cpu->A;

    printf("Value at memory[0x2000]: 0x%02X\n", memory[0x2000]);
    delay = 6;
}
//stx
void STX_Zero_Page(Cpu* cpu){
    printf("STX zero page called at %d\n",cpu->PC);
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t address = (uint16_t)zp_address;
    printf("Memory at right value???: 0x%02X\n", address);
    memory[address] = cpu->X;
    printf("Value at memory[0x0010]: 0x%02X\n", memory[0x0010]);
    delay = 3;
}
void STX_Zero_Page_Y(Cpu* cpu){
    printf("STX zero page Y called at %d\n",cpu->PC);
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t base_address = (uint16_t)zp_address;
    uint8_t address = (base_address + cpu->Y) & 0xFF;
    printf("Memory at right value???: 0x%02X\n", address);
    memory[address] = cpu->X;
    printf("Value at memory[0x0010]: 0x%02X\n", memory[0x0015]);
    delay = 4;
}
void STX_Absolute(Cpu* cpu){
    printf("STX absolute called at %d\n",cpu->PC);
    cpu->PC ++;
    uint8_t low = memory[cpu->PC]; 
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];
    uint16_t address = (high << 8) | low;

    memory[address] = cpu->X;

    printf("Value at memory[0x0010]: 0x%02X\n", memory[0x2000]);
    delay = 4;
}
void STY_Zero_Page(Cpu* cpu){
    printf("STY zero page called at %d\n",cpu->PC);
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t address = (uint16_t)zp_address;
    printf("Memory at right value???: 0x%02X\n", address);
    memory[address] = cpu->Y;
    printf("Value at memory[0x0010]: 0x%02X\n", memory[0x0010]);
    delay = 3;
}
void STY_Zero_Page_X(Cpu* cpu){
    printf("STA zero page X called at %d\n",cpu->PC);
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t base_address = (uint16_t)zp_address;
    uint8_t address = (base_address + cpu->X) & 0xFF;
    printf("Memory at right value???: 0x%02X\n", address);
    memory[address] = cpu->Y;
    printf("Value at memory[0x0010]: 0x%02X\n", memory[0x0015]);
    delay = 4;
}
void STY_Absolute(Cpu* cpu){
    printf("STA absolute called at %d\n",cpu->PC);
    cpu->PC ++;
    uint8_t low = memory[cpu->PC]; 
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];
    uint16_t address = (high << 8) | low;

    memory[address] = cpu->Y;

    printf("Value at memory[0x0010]: 0x%02X\n", memory[0x2000]);
    delay = 4;
}
//Stack Instructions
void TXS(Cpu* cpu){
    cpu->S = cpu->X;
    if (cpu->S == 0)
    {
        cpu->Z = 1;
    }else
    {
        cpu->Z = 0;
    }
    
    cpu->N = (cpu->S & 0x80) != 0;

    
    cpu->PC++;
    delay = 2;
}
void TSX(Cpu* cpu){
    cpu->X = cpu->S;
    if (cpu->X == 0)
    {
        cpu->Z = 1;
    }else{
        cpu->Z = 0;
    }

    cpu->N = (cpu->X & 0x80) != 0;

    
    cpu->PC++;
    delay = 2;
}
void PHA(Cpu* cpu){
    
    memory[0x0100 + cpu->S] = cpu->A;
    cpu->S--;
    delay = 3;
}
void PLA(Cpu* cpu){
    cpu->S++;

    cpu->A = memory[0x0100 + cpu->S];

    if (cpu->A == 0)
    {
        cpu->Z = 1;
    }else{
        cpu->Z = 0;
    }

    cpu->N = (cpu->A & 0x80) != 0;
    delay = 4;
}
void PHP(Cpu* cpu){
    uint8_t status = 0;
    status |= (cpu->C & 1);  
    status |= (cpu->Z << 1); 
    status |= (cpu->I << 2);  
    status |= (cpu->D << 3); 
    status |= (cpu->B << 4); 
    status |= (cpu->V << 6);  
    status |= (cpu->N << 7); 

    memory[0x0100 + cpu->S] = status;
    cpu->S--;
    delay = 3;

}
void PLP(Cpu* cpu){
    cpu->S++;

    uint8_t status = memory[0x0100 + cpu->S];

    cpu->C = status & 1;
    cpu->Z = (status >> 1) & 1;
    cpu->I = (status >> 2) & 1;
    cpu->D = (status >> 3) & 1;
    cpu->B = (status >> 4) & 1;
    cpu->V = (status >> 6) & 1;
    cpu->N = (status >> 7) & 1; 

    delay = 4;
}

void CLC(Cpu* cpu){
    cpu->PC++;
    cpu->C = 0;
    delay = 2;
}
void SEC(Cpu* cpu){
    cpu->PC++;
    cpu->C = 1;
    delay = 2;
}
void CLI(Cpu* cpu){
    cpu->PC++;
    cpu->I = 0;
    delay = 2;
}
void SEI(Cpu* cpu){
    cpu->PC++;
    cpu->I = 1;
    delay = 2;
}
void CLV(Cpu* cpu){
    cpu->PC++;
    cpu->V = 0;
    delay = 2;
}
void CLD(Cpu* cpu){
    cpu->PC++;
    cpu->D = 0;
    delay = 2;
}
void SED(Cpu* cpu){
    cpu->PC++;
    cpu->D = 1;
    delay = 2;
}
//Register Instructions
void TAX(Cpu* cpu){
    cpu->X = cpu->A;
    if (cpu->X == 0)
    {
        cpu->Z = 1;
    }else
    {
        cpu->Z = 0;
    }
    
    cpu->N = (cpu->X & 0x80) != 0;

    
    cpu->PC++;
    delay = 2;
}
void TXA(Cpu* cpu){
    cpu->A = cpu->X;
    if (cpu->A == 0)
    {
        cpu->Z = 1;
    }else
    {
        cpu->Z = 0;
    }
    
    cpu->N = (cpu->A & 0x80) != 0;

    
    cpu->PC++;
    delay = 2;
}
void DEX(Cpu* cpu){
    cpu->X--;
    if (cpu->X == 0)
    {
        cpu->Z = 1;
    }else
    {
        cpu->Z = 0;
    }
    
    cpu->N = (cpu->X & 0x80) != 0;

    
    cpu->PC++;
    delay = 2;
}
void INX(Cpu* cpu){
    cpu->X++;
    if (cpu->X == 0)
    {
        cpu->Z = 1;
    }else
    {
        cpu->Z = 0;
    }
    
    cpu->N = (cpu->X & 0x80) != 0;

    
    cpu->PC++;
    delay = 2;
}
void TAY(Cpu* cpu){
    cpu->Y = cpu->A;
    if (cpu->Y == 0)
    {
        cpu->Z = 1;
    }else
    {
        cpu->Z = 0;
    }
    
    cpu->N = (cpu->Y & 0x80) != 0;

    
    cpu->PC++;
    delay = 2;
}
void TYA(Cpu* cpu){
    cpu->A = cpu->Y;
    if (cpu->A == 0)
    {
        cpu->Z = 1;
    }else
    {
        cpu->Z = 0;
    }
    
    cpu->N = (cpu->A & 0x80) != 0;

    
    cpu->PC++;
    delay = 2;
}
void DEY(Cpu* cpu){
    cpu->Y--;
    if (cpu->Y == 0)
    {
        cpu->Z = 1;
    }else
    {
        cpu->Z = 0;
    }
    
    cpu->N = (cpu->Y & 0x80) != 0;

    
    cpu->PC++;
    delay = 2;
}
void INY(Cpu* cpu){
    cpu->Y++;
    if (cpu->Y == 0)
    {
        cpu->Z = 1;
    }else
    {
        cpu->Z = 0;
    }
    
    cpu->N = (cpu->Y & 0x80) != 0;

    
    cpu->PC++;
    delay = 2;
}
void NOP(Cpu* cpu){
    cpu->PC++;
    delay = 2;
}
//Branch Instructions
void BPL(Cpu* cpu){
    cpu->PC++;
    int8_t offset = (int8_t)memory[cpu->PC];
    if (cpu->N == 0)
    {
        cpu->PC += offset;
        delay = 3;
    }else
    {
        cpu->PC++;
        delay = 2;
    }
}
void BMI(Cpu* cpu){
    cpu->PC++;
    int8_t offset = (int8_t)memory[cpu->PC];
    uint16_t targetAddress = cpu->PC + offset;
    if (cpu->N == 1)
    {
        if (((cpu->PC & 0xFF00) != (targetAddress & 0xFF00))) {
            cpu->PC += offset; 
            delay = 4; 
        }else {
            cpu->PC += offset;
            delay = 3; 
        }
    }else
    {
        cpu->PC++;
        delay = 3;
    }
}
void BVC(Cpu* cpu){
    cpu->PC++;
    int8_t offset = (int8_t)memory[cpu->PC];
    if (cpu->V == 0)
    {
        cpu->PC += offset;
        delay = 3;
    }else
    {
        cpu->PC++;
        delay = 2;
    }
}
void BVS(Cpu* cpu){
    cpu->PC++;
    int8_t offset = (int8_t)memory[cpu->PC];
    uint16_t targetAddress = cpu->PC + offset;
    if (cpu->V == 1)
    {
        if (((cpu->PC & 0xFF00) != (targetAddress & 0xFF00))) {
            cpu->PC += offset; 
            delay = 4; 
        }else {
            cpu->PC += offset;
            delay = 3; 
        }
    }else
    {
        cpu->PC++;
        delay = 3;
    }
}
void BCC(Cpu* cpu){
    cpu->PC++;
    int8_t offset = (int8_t)memory[cpu->PC];
    if (cpu->C == 0)
    {
        cpu->PC += offset;
        delay = 3;
    }else
    {
        cpu->PC++;
        delay = 2;
    }
}
void BCS(Cpu* cpu){
    cpu->PC++;
    int8_t offset = (int8_t)memory[cpu->PC];
    uint16_t targetAddress = cpu->PC + offset;
    if (cpu->C == 1)
    {
        if (((cpu->PC & 0xFF00) != (targetAddress & 0xFF00))) {
            cpu->PC += offset; 
            delay = 4; 
        }else {
            cpu->PC += offset;
            delay = 3; 
        }
    }else
    {
        cpu->PC++;
        delay = 3;
    }
}
void BNE(Cpu* cpu){
    cpu->PC++;
    int8_t offset = (int8_t)memory[cpu->PC];
    if (cpu->Z == 0)
    {
        cpu->PC += offset;
        delay = 3;
    }else
    {
        cpu->PC++;
        delay = 2;
    }
}
void BEQ(Cpu* cpu){
    cpu->PC++;
    int8_t offset = (int8_t)memory[cpu->PC];
    uint16_t targetAddress = cpu->PC + offset;
    if (cpu->C == 1)
    {
        if (((cpu->PC & 0xFF00) != (targetAddress & 0xFF00))) {
            cpu->PC += offset; 
            delay = 4; 
        }else {
            cpu->PC += offset;
            delay = 3; 
        }
    }else
    {
        cpu->PC++;
        delay = 3;
    }
}
//Bitwise and Shift Instructions:

//AND
void AND_Immediate(Cpu* cpu) {
    printf("and immediate called\n");
    cpu->PC++;
    uint8_t value = memory[cpu->PC];
    
    cpu->A = cpu->A & value;

    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = (cpu->A & 0x80) ? 1 : 0;

    delay = 2;

    printf("Value at A: 0x%02X\n", cpu->A);
}
void AND_Zero_Page(Cpu* cpu) {
    printf("and Zero Page  called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t address = (uint16_t)zp_address;
    printf("Memory at right value???: 0x%02X\n", address);
    uint8_t value = memory[address];
    
    cpu->A = cpu->A & value;

    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = (cpu->A & 0x80) ? 1 : 0;

    delay = 3;

    printf("Value at A: 0x%02X\n", cpu->A);
}
void AND_Zero_Page_X(Cpu* cpu) {
    printf("and Zero Page x called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t base_address = (uint16_t)zp_address;
    
    printf("Calculated baseaddress: 0x%02X\n", memory[cpu->PC]);

    uint8_t address = (base_address + cpu->X) & 0xFF;
    
    uint8_t value = memory[address];
    cpu->A = cpu->A & value;

    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = (cpu->A & 0x80) ? 1 : 0;

    delay = 4;

    printf("Value at A: 0x%02X\n", cpu->A);
}
void AND_Absolute(Cpu* cpu) {
    printf("and absolute called\n");
    uint8_t low = memory[cpu->PC];
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];
    uint16_t address = (high << 8) | low;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];
    cpu->A = cpu->A & value;
    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = (cpu->A & 0x80) ? 1 : 0;

    delay = 4;

    printf("Value at A: 0x%02X\n", cpu->A);
}
void AND_Absolute_X(Cpu* cpu) {
    printf("and absolute x called\n");
    uint8_t low = memory[cpu->PC];   
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];  
    uint16_t base = (high << 8) | low;
    printf("base: 0x%02X\n", base);
    uint16_t address = base + cpu->X;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];
    cpu->A = cpu->A & value;
    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = (cpu->A & 0x80) ? 1 : 0;

    delay = 4;
    if ((base & 0xFF00) != (address & 0xFF00)) {
        printf("Page boundary crossed!\n");
        delay++;  
    }
    printf("Value at A: 0x%02X\n", cpu->A);
}
void AND_Absolute_Y(Cpu* cpu) {
    printf("and absolute Y called\n");
    uint8_t low = memory[cpu->PC];   
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];  
    uint16_t base = (high << 8) | low;
    printf("base: 0x%02X\n", base);
    uint16_t address = base + cpu->Y;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];
    cpu->A = cpu->A & value;
    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = (cpu->A & 0x80) ? 1 : 0;

    delay = 4;
    if ((base & 0xFF00) != (address & 0xFF00)) {
        printf("Page boundary crossed!\n");
        delay++;  
    }
    printf("Value at A: 0x%02X\n", cpu->A);
}
void AND_Indirect_X(Cpu* cpu) {
    printf("and indirect  xxxx called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    printf("zp: 0x%02X\n", zp_address);
    uint16_t base_address = (uint16_t)zp_address;
    printf("base addressss: 0x%02X\n", base_address);
    uint16_t addressAfterX = base_address + cpu->X;
    printf(" addressAfterX: 0x%02X\n", addressAfterX);

    uint8_t low = memory[addressAfterX];  
    printf(" low: 0x%02X\n", addressAfterX);
    addressAfterX++;
    uint8_t high = memory[addressAfterX];
    printf(" high: 0x%02X\n", addressAfterX);
    uint16_t base = (high << 8) | low;
    printf("Memory address at base in lda indirect X: 0x%02X\n", base);
    uint8_t value = memory[base];
    
    cpu->A = cpu->A & value;

    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = (cpu->A & 0x80) ? 1 : 0;

    delay = 6;

    printf("Value at A: 0x%02X\n", cpu->A);
}
void AND_Indirect_Y(Cpu* cpu) {
    printf("and indirect  xxxx called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    printf("zp: 0x%02X\n", zp_address);
    uint16_t base_address = (uint16_t)zp_address;
    printf("base addressss: 0x%02X\n", base_address);
    uint16_t addressAfterX = base_address + cpu->Y;
    printf(" addressAfterX: 0x%02X\n", addressAfterX);

    uint8_t low = memory[addressAfterX];  
    printf(" low: 0x%02X\n", addressAfterX);
    addressAfterX++;
    uint8_t high = memory[addressAfterX];
    printf(" high: 0x%02X\n", addressAfterX);
    uint16_t base = (high << 8) | low;
    printf("Memory address at base in lda indirect X: 0x%02X\n", base);
    uint8_t value = memory[base];
    
    cpu->A = cpu->A & value;

    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = (cpu->A & 0x80) ? 1 : 0;

    delay = 6;

    printf("Value at A: 0x%02X\n", cpu->A);
}
//EOR
void EOR_Immediate(Cpu* cpu) {
    printf("EOR immediate called\n");
    cpu->PC++;
    uint8_t value = memory[cpu->PC];
    
    cpu->A = cpu->A ^ value;

    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = (cpu->A & 0x80) ? 1 : 0;

    delay = 2;

    printf("Value at A: 0x%02X\n", cpu->A);
}
void EOR_Zero_Page(Cpu* cpu) {
    printf("EOR Zero Page  called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t address = (uint16_t)zp_address;
    printf("Memory at right value???: 0x%02X\n", address);
    uint8_t value = memory[address];
    
    cpu->A = cpu->A ^ value;

    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = (cpu->A & 0x80) ? 1 : 0;

    delay = 3;

    printf("Value at A: 0x%02X\n", cpu->A);
}
void EOR_Zero_Page_X(Cpu* cpu) {
    printf("EOR Zero Page x called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t base_address = (uint16_t)zp_address;
    
    printf("Calculated baseaddress: 0x%02X\n", memory[cpu->PC]);

    uint8_t address = (base_address + cpu->X) & 0xFF;
    
    uint8_t value = memory[address];
    cpu->A = cpu->A ^ value;

    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = (cpu->A & 0x80) ? 1 : 0;

    delay = 4;

    printf("Value at A: 0x%02X\n", cpu->A);
}
void EOR_Absolute(Cpu* cpu) {
    printf("EOR absolute called\n");
    uint8_t low = memory[cpu->PC];
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];
    uint16_t address = (high << 8) | low;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];

    cpu->A = cpu->A ^ value;
    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = (cpu->A & 0x80) ? 1 : 0;

    delay = 4;

    printf("Value at A: 0x%02X\n", cpu->A);
}
void EOR_Absolute_X(Cpu* cpu) {
    printf("EOR absolute x called\n");
    uint8_t low = memory[cpu->PC];   
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];  
    uint16_t base = (high << 8) | low;
    printf("base: 0x%02X\n", base);
    uint16_t address = base + cpu->X;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];
    cpu->A = cpu->A ^ value;
    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = (cpu->A & 0x80) ? 1 : 0;

    delay = 4;
    if ((base & 0xFF00) != (address & 0xFF00)) {
        printf("Page boundary crossed!\n");
        delay++;  
    }
    printf("Value at A: 0x%02X\n", cpu->A);
}
void EOR_Absolute_Y(Cpu* cpu) {
    printf("EOR absolute Y called\n");
    uint8_t low = memory[cpu->PC];   
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];  
    uint16_t base = (high << 8) | low;
    printf("base: 0x%02X\n", base);
    uint16_t address = base + cpu->Y;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];
    cpu->A = cpu->A ^ value;
    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = (cpu->A & 0x80) ? 1 : 0;

    delay = 4;
    if ((base & 0xFF00) != (address & 0xFF00)) {
        printf("Page boundary crossed!\n");
        delay++;  
    }
    printf("Value at A: 0x%02X\n", cpu->A);
}
void EOR_Indirect_X(Cpu* cpu) {
    printf("EOR indirect  xxxx called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    printf("zp: 0x%02X\n", zp_address);
    uint16_t base_address = (uint16_t)zp_address;
    printf("base addressss: 0x%02X\n", base_address);
    uint16_t addressAfterX = base_address + cpu->X;
    printf(" addressAfterX: 0x%02X\n", addressAfterX);
    uint8_t low = memory[addressAfterX];  
    printf(" low: 0x%02X\n", addressAfterX);
    addressAfterX++;
    uint8_t high = memory[addressAfterX];
    printf(" high: 0x%02X\n", addressAfterX);
    uint16_t base = (high << 8) | low;
    printf("Memory address at base in lda indirect X: 0x%02X\n", base);
    uint8_t value = memory[base];
    
    cpu->A = cpu->A ^ value;

    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = (cpu->A & 0x80) ? 1 : 0;

    delay = 6;

    printf("Value at A: 0x%02X\n", cpu->A);
}
void EOR_Indirect_Y(Cpu* cpu) {
    printf("EOR indirect  xxxx called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    printf("zp: 0x%02X\n", zp_address);
    uint16_t base_address = (uint16_t)zp_address;
    printf("base addressss: 0x%02X\n", base_address);
    uint16_t addressAfterX = base_address + cpu->Y;
    printf(" addressAfterX: 0x%02X\n", addressAfterX);
    uint8_t low = memory[addressAfterX];  
    printf(" low: 0x%02X\n", addressAfterX);
    addressAfterX++;
    uint8_t high = memory[addressAfterX];
    printf(" high: 0x%02X\n", addressAfterX);
    uint16_t base = (high << 8) | low;
    printf("Memory address at base in lda indirect X: 0x%02X\n", base);
    uint8_t value = memory[base];
    
    cpu->A = cpu->A ^ value;

    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = (cpu->A & 0x80) ? 1 : 0;

    delay = 6;

    printf("Value at A: 0x%02X\n", cpu->A);
}
//ORA
void ORA_Immediate(Cpu* cpu) {
    printf("ORA immediate called\n");
    cpu->PC++;
    uint8_t value = memory[cpu->PC];
    
    cpu->A = cpu->A | value;

    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = (cpu->A & 0x80) ? 1 : 0;

    delay = 2;

    printf("Value at A: 0x%02X\n", cpu->A);
}
void ORA_Zero_Page(Cpu* cpu) {
    printf("ORA Zero Page  called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t address = (uint16_t)zp_address;
    printf("Memory at right value???: 0x%02X\n", address);
    uint8_t value = memory[address];
    
    cpu->A = cpu->A | value;

    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = (cpu->A & 0x80) ? 1 : 0;

    delay = 3;

    printf("Value at A: 0x%02X\n", cpu->A);
}
void ORA_Zero_Page_X(Cpu* cpu) {
    printf("ORA Zero Page x called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t base_address = (uint16_t)zp_address;
    
    printf("Calculated baseaddress: 0x%02X\n", memory[cpu->PC]);

    uint8_t address = (base_address + cpu->X) & 0xFF;
    
    uint8_t value = memory[address];
    cpu->A = cpu->A | value;

    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = (cpu->A & 0x80) ? 1 : 0;

    delay = 4;

    printf("Value at A: 0x%02X\n", cpu->A);
}
void ORA_Absolute(Cpu* cpu) {
    cpu->PC ++;
    printf("ORA absolute called\n");
    uint8_t low = memory[cpu->PC];
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];
    uint16_t address = (high << 8) | low;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];

    cpu->A = cpu->A | value;
    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = (cpu->A & 0x80) ? 1 : 0;

    delay = 4;

    printf("Value at A: 0x%02X\n", cpu->A);
}
void ORA_Absolute_X(Cpu* cpu) {
    printf("ORA absolute x called\n");
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];   
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];  
    uint16_t base = (high << 8) | low;
    printf("base: 0x%02X\n", base);
    uint16_t address = base + cpu->X;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];
    cpu->A = cpu->A | value;
    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = (cpu->A & 0x80) ? 1 : 0;

    delay = 4;
    if ((base & 0xFF00) != (address & 0xFF00)) {
        printf("Page boundary crossed!\n");
        delay++;  
    }
    printf("Value at A: 0x%02X\n", cpu->A);
}
void ORA_Absolute_Y(Cpu* cpu) {
    printf("ORA absolute Y called\n");
    uint8_t low = memory[cpu->PC];   
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];  
    uint16_t base = (high << 8) | low;
    printf("base: 0x%02X\n", base);
    uint16_t address = base + cpu->Y;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];
    cpu->A = cpu->A | value;
    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = (cpu->A & 0x80) ? 1 : 0;

    delay = 4;
    if ((base & 0xFF00) != (address & 0xFF00)) {
        printf("Page boundary crossed!\n");
        delay++;  
    }
    printf("Value at A: 0x%02X\n", cpu->A);
}
void ORA_Indirect_X(Cpu* cpu) {
    printf("ORA indirect  xxxx called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    printf("zp: 0x%02X\n", zp_address);
    uint16_t base_address = (uint16_t)zp_address;
    printf("base addressss: 0x%02X\n", base_address);
    uint16_t addressAfterX = base_address + cpu->X;
    printf(" addressAfterX: 0x%02X\n", addressAfterX);

    uint8_t low = memory[addressAfterX];  
    printf(" low: 0x%02X\n", addressAfterX);
    addressAfterX++;
    uint8_t high = memory[addressAfterX];
    printf(" high: 0x%02X\n", addressAfterX);
    uint16_t base = (high << 8) | low;
    printf("Memory address at base in lda indirect X: 0x%02X\n", base);
    uint8_t value = memory[base];
    
    cpu->A = cpu->A | value;

    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = (cpu->A & 0x80) ? 1 : 0;

    delay = 6;

    printf("Value at A: 0x%02X\n", cpu->A);
}
void ORA_Indirect_Y(Cpu* cpu) {
    printf("ORA indirect  xxxx called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    printf("zp: 0x%02X\n", zp_address);
    uint16_t base_address = (uint16_t)zp_address;
    printf("base addressss: 0x%02X\n", base_address);
    uint16_t addressAfterX = base_address + cpu->Y;
    printf(" addressAfterX: 0x%02X\n", addressAfterX);
    uint8_t low = memory[addressAfterX];  
    printf(" low: 0x%02X\n", addressAfterX);
    addressAfterX++;
    uint8_t high = memory[addressAfterX];
    printf(" high: 0x%02X\n", addressAfterX);
    uint16_t base = (high << 8) | low;
    printf("Memory address at base in lda indirect X: 0x%02X\n", base);
    uint8_t value = memory[base];
    
    cpu->A = cpu->A | value;

    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = (cpu->A & 0x80) ? 1 : 0;

    delay = 6;

    printf("Value at A: 0x%02X\n", cpu->A);
}
//ASL
void ASL_Accumulator(Cpu* cpu){
    printf("ASL accumulator called\n");
    cpu->PC++;
    cpu->C = (cpu->A & 0x80) ? 1 : 0;
    cpu->A = cpu->A << 1;

    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = (cpu->A & 0x80) ? 1 : 0;
    printf("Value at A: 0x%02X\n", cpu->A);
    delay = 2;
}
void ASL_Zero_Page(Cpu* cpu){
    printf("ldx zero page called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t address = (uint16_t)zp_address;
    printf("Memory at right value???: 0x%02X\n", address);
    uint8_t value = memory[address];
    cpu->C = (value & 0x80) ? 1 : 0;
    value = value << 1;

    cpu->Z = (value == 0) ? 1 : 0;
    cpu->N = (value & 0x80) ? 1 : 0;

    memory[address] = value;

    delay = 5;
}
void ASL_Zero_Page_X(Cpu* cpu){
    printf("ASL Zero Page x called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t base_address = (uint16_t)zp_address;
    
    printf("Calculated baseaddress: 0x%02X\n", memory[cpu->PC]);
    
    uint8_t address = (base_address + cpu->X) & 0xFF;
    
    uint8_t value = memory[address];

    cpu->C = (value & 0x80) ? 1 : 0;
    value = value << 1;

    cpu->Z = (value == 0) ? 1 : 0;
    cpu->N = (value & 0x80) ? 1 : 0;

    memory[address] = value;

    delay = 6;
}
void ASL_Absolute(Cpu* cpu){
    printf("ASL absolute called\n");
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];
    uint16_t address = (high << 8) | low;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];

    cpu->C = (value & 0x80) ? 1 : 0;
    value = value << 1;

    cpu->Z = (value == 0) ? 1 : 0;
    cpu->N = (value & 0x80) ? 1 : 0;

    memory[address] = value;

    delay = 6;
}
void ASL_Absolute_X(Cpu* cpu){
    printf("ASL absolute x called\n");
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];   
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];  
    uint16_t base = (high << 8) | low;
    printf("base: 0x%02X\n", base);
    uint16_t address = base + cpu->X;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];

    cpu->C = (value & 0x80) ? 1 : 0;
    value = value << 1;

    cpu->Z = (value == 0) ? 1 : 0;
    cpu->N = (value & 0x80) ? 1 : 0; 

    memory[address] = value;

    delay = 7;
}
//LSR
void LSR_Accumulator(Cpu* cpu){
    printf("LSR accumulator called\n");
    cpu->PC++;
    cpu->C = (cpu->A & 0x01) ? 1 : 0;
    cpu->A = cpu->A >> 1;

    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = 0;
    printf("Value at A: 0x%02X\n", cpu->A);
    delay = 2;
}
void LSR_Zero_Page(Cpu* cpu){
    printf("LSR zero page called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t address = (uint16_t)zp_address;
    printf("Memory at right value???: 0x%02X\n", address);
    uint8_t value = memory[address];
    cpu->C = (cpu->A & 0x01) ? 1 : 0;
    value = value >> 1;

    cpu->Z = (value == 0) ? 1 : 0;
    cpu->N = 0;

    memory[address] = value;

    delay = 5;
}
void LSR_Zero_Page_X(Cpu* cpu){
    printf("LSR Zero Page x called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t base_address = (uint16_t)zp_address;
    
    printf("Calculated baseaddress: 0x%02X\n", memory[cpu->PC]);
    
    uint8_t address = (base_address + cpu->X) & 0xFF;
    
    uint8_t value = memory[address];

    cpu->C = (cpu->A & 0x01) ? 1 : 0;
    value = value >> 1;

    cpu->Z = (value == 0) ? 1 : 0;
    cpu->N = 0;

    memory[address] = value;

    delay = 6;
}
void LSR_Absolute(Cpu* cpu){
    printf("LSR absolute called\n");
    cpu->PC ++;
    uint8_t low = memory[cpu->PC]; 
    cpu->PC ++;
    uint8_t high = memory[cpu->PC]; 
    uint16_t address = (high << 8) | low;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];

    cpu->C = (cpu->A & 0x01) ? 1 : 0;
    value = value >> 1;

    cpu->Z = (value == 0) ? 1 : 0;
    cpu->N = 0;

    memory[address] = value;

    delay = 6;
}
void LSR_Absolute_X(Cpu* cpu){
    printf("LSR absolute x called\n");
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];   
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];  
    uint16_t base = (high << 8) | low;
    printf("base: 0x%02X\n", base);
    uint16_t address = base + cpu->X;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];

    cpu->C = (cpu->A & 0x01) ? 1 : 0;
    value = value >> 1;

    cpu->Z = (value == 0) ? 1 : 0;
    cpu->N = 0;

    memory[address] = value;

    delay = 7;
}
//ROL
void ROL_Accumulator(Cpu* cpu) {
    printf("ROL accumulator called\n");
    cpu->PC++;

    uint8_t oldCarry = cpu->C;
    cpu->C = (cpu->A & 0x80) ? 1 : 0; 
    cpu->A = (cpu->A << 1) | oldCarry;

    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = (cpu->A & 0x80) ? 1 : 0;

    printf("Value at A: 0x%02X\n", cpu->A);
    delay = 2;
}

void ROL_Zero_Page(Cpu* cpu){
    printf("ROL zero page called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t address = (uint16_t)zp_address;
    printf("Memory at right value???: 0x%02X\n", address);
    uint8_t value = memory[address];
    uint8_t oldCarry = cpu->C;
    cpu->C = (value & 0x80) ? 1 : 0; 
    value = (value << 1) | oldCarry;

    cpu->Z = (value == 0) ? 1 : 0;
    cpu->N = (value & 0x80) ? 1 : 0;

    memory[address] = value;

    delay = 5;
}
void ROL_Zero_Page_X(Cpu* cpu){
    printf("ROL Zero Page x called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t base_address = (uint16_t)zp_address;
    
    printf("Calculated baseaddress: 0x%02X\n", memory[cpu->PC]);
    
    uint8_t address = (base_address + cpu->X) & 0xFF;
    
    uint8_t value = memory[address];

    uint8_t oldCarry = cpu->C;
    cpu->C = (value & 0x80) ? 1 : 0; 
    value = (value << 1) | oldCarry;

    cpu->Z = (value == 0) ? 1 : 0;
    cpu->N = (value & 0x80) ? 1 : 0;

    memory[address] = value;

    delay = 6;
}
void ROL_Absolute(Cpu* cpu){
    printf("ROL absolute called\n");
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];
    uint16_t address = (high << 8) | low;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];

    uint8_t oldCarry = cpu->C;
    cpu->C = (value & 0x80) ? 1 : 0; 
    value = (value << 1) | oldCarry;

    cpu->Z = (value == 0) ? 1 : 0;
    cpu->N = (value & 0x80) ? 1 : 0;

    memory[address] = value;

    delay = 6;
}
void ROL_Absolute_X(Cpu* cpu){
    printf("ROL absolute x called\n");
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];   
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];  
    uint16_t base = (high << 8) | low;
    printf("base: 0x%02X\n", base);
    uint16_t address = base + cpu->X;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];

    uint8_t oldCarry = cpu->C;
    cpu->C = (value & 0x80) ? 1 : 0; 
    value = (value << 1) | oldCarry;

    cpu->Z = (value == 0) ? 1 : 0;
    cpu->N = (value & 0x80) ? 1 : 0;

    memory[address] = value;

    delay = 7;
}
//ROR
void ROR_Accumulator(Cpu* cpu) {
    printf("ROR accumulator called\n");
    cpu->PC++;

    uint8_t oldCarry = cpu->C;
    cpu->C = (cpu->A & 0x01) ? 1 : 0;
    cpu->A = (cpu->A >> 1) | (oldCarry << 7);  

    cpu->Z = (cpu->A == 0) ? 1 : 0;
    cpu->N = (cpu->A & 0x80) ? 1 : 0;

    printf("Value at A: 0x%02X\n", cpu->A);
    delay = 2;
}
void ROR_Zero_Page(Cpu* cpu){
    printf("ROR zero page called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t address = (uint16_t)zp_address;
    printf("Memory at right value???: 0x%02X\n", address);
    uint8_t value = memory[address];
    
    uint8_t oldCarry = cpu->C;
    cpu->C = (value & 0x01) ? 1 : 0;
    value = (value >> 1) | (oldCarry << 7);  

    cpu->Z = (value == 0) ? 1 : 0;
    cpu->N = (value & 0x80) ? 1 : 0;

    memory[address] = value;

    delay = 5;
}
void ROR_Zero_Page_X(Cpu* cpu){
    printf("ROR Zero Page x called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t base_address = (uint16_t)zp_address;
    
    printf("Calculated baseaddress: 0x%02X\n", memory[cpu->PC]);
    
    uint8_t address = (base_address + cpu->X) & 0xFF;
    
    uint8_t value = memory[address];

    uint8_t oldCarry = cpu->C;
    cpu->C = (value & 0x01) ? 1 : 0;
    value = (value >> 1) | (oldCarry << 7);  

    cpu->Z = (value == 0) ? 1 : 0;
    cpu->N = (value & 0x80) ? 1 : 0;

    memory[address] = value;

    delay = 6;
}
void ROR_Absolute(Cpu* cpu){
    printf("ROR absolute called\n");
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];
    uint16_t address = (high << 8) | low;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];

    uint8_t oldCarry = cpu->C;
    cpu->C = (value & 0x01) ? 1 : 0;
    value = (value >> 1) | (oldCarry << 7);  

    cpu->Z = (value == 0) ? 1 : 0;
    cpu->N = (value & 0x80) ? 1 : 0;

    memory[address] = value;

    delay = 6;
}
void ROR_Absolute_X(Cpu* cpu){
    printf("ROL absolute x called\n");
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];   
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];  
    uint16_t base = (high << 8) | low;
    printf("base: 0x%02X\n", base);
    uint16_t address = base + cpu->X;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];

    uint8_t oldCarry = cpu->C;
    cpu->C = (value & 0x01) ? 1 : 0;
    value = (value >> 1) | (oldCarry << 7);  

    cpu->Z = (value == 0) ? 1 : 0;
    cpu->N = (value & 0x80) ? 1 : 0;

    memory[address] = value;

    delay = 7;
}
//BIT
void BIT_Zero_Page(Cpu* cpu){
    printf("BIT zero page called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t address = (uint16_t)zp_address;
    printf("Memory at right value???: 0x%02X\n", address);
    uint8_t value = memory[address];
    
    uint8_t result = cpu->A & value; 
    cpu->Z = (result == 0) ? 1 : 0;        
    cpu->N = (value & 0x80) ? 1 : 0;       
    cpu->V = (value & 0x40) ? 1 : 0;

    delay = 3;
}
void BIT_Absolute(Cpu* cpu){
    printf("BIT absolute called\n");
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];
    uint16_t address = (high << 8) | low;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];

    uint8_t result = cpu->A & value; 
    cpu->Z = (result == 0) ? 1 : 0;        
    cpu->N = (value & 0x80) ? 1 : 0;       
    cpu->V = (value & 0x40) ? 1 : 0;

    delay = 4;
}
//BRK
void BRK_Implied(Cpu* cpu){

    cpu->PC++;
    uint16_t returnAddress = cpu->PC;
    memory[0x0100 + cpu->S--] = (uint8_t)((returnAddress >> 8) & 0xFF); 
    memory[0x0100 + cpu->S--] = (uint8_t)(returnAddress & 0xFF);        

    uint8_t status = 0;
    status |= (cpu->C & 1);  
    status |= (cpu->Z << 1); 
    status |= (cpu->I << 2);  
    status |= (cpu->D << 3); 
    status |= (cpu->B << 4); 
    status |= (cpu->V << 6);  
    status |= (cpu->N << 7); 
    memory[0x0100 + cpu->S--] = status; 

    cpu->B = 1;
    cpu->I = 1;

    cpu->PC = memory[0xFFFE] | (memory[0xFFFF] << 8);


    delay = 7;

}
//RTI
void RTI_Implied(Cpu* cpu) {
    cpu->S++;
    uint8_t status = memory[0x0100 + cpu->S];
    cpu->C = (status & 0x01);
    cpu->Z = (status >> 1) & 0x01;
    cpu->I = (status >> 2) & 0x01;
    cpu->D = (status >> 3) & 0x01;
    cpu->B = 0; 
    cpu->V = (status >> 6) & 0x01;
    cpu->N = (status >> 7) & 0x01;

    cpu->S++;
    uint8_t low = memory[0x0100 + cpu->S];
    cpu->S++;
    uint8_t high = memory[0x0100 + cpu->S];

    cpu->PC = ((uint16_t)high << 8) | low;

    delay = 6;
}
//DEC
void DEC_Zero_Page(Cpu* cpu){
    printf("DEC zero page called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t address = (uint16_t)zp_address;
    printf("Memory at right value???: 0x%02X\n", address);
    uint8_t value = memory[address];
    
    value = value - 1;

    cpu->Z = (value == 0);

    cpu->N = (value & 0x80) != 0;
    memory[address] = value;
    delay = 5;
}
void DEC_Zero_Page_X(Cpu* cpu) {
    printf("DEC zero page X called\n");
    
    
    cpu->PC ++;
    printf("Calculated pc: 0x%02X\n", cpu->PC);
    
    uint8_t zp_address = memory[cpu->PC];
    uint16_t base_address = (uint16_t)zp_address;
    
    printf("Calculated baseaddress: 0x%02X\n", memory[cpu->PC]);
    uint8_t address = (base_address + cpu->X) & 0xFF;
    

    printf("Calculated address: 0x%02X\n", address);

    
    uint8_t value = memory[address];
    
    value = value - 1;

    cpu->Z = (value == 0);

    cpu->N = (value & 0x80) != 0;
    memory[address] = value;
    delay = 6;
}
void DEC_Absolute(Cpu* cpu){
    printf("DEC absolute called\n");
    
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];
    cpu->PC ++;
    uint8_t high = memory[cpu->PC]; 
    uint16_t address = (high << 8) | low;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];

    
    value = value - 1;

    cpu->Z = (value == 0);

    cpu->N = (value & 0x80) != 0;
    memory[address] = value;
    delay = 6;
}
void DEC_Absolute_X(Cpu* cpu){
    
    printf("DEC absolute xxxxx called\n");
    
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];   
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];  
    uint16_t base = (high << 8) | low;
    printf("base: 0x%02X\n", base);
    uint16_t address = base + cpu->X;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];

    
    value = value - 1;

    cpu->Z = (value == 0);

    cpu->N = (value & 0x80) != 0;
    memory[address] = value;
    delay = 6;
}
//INC
void INC_Zero_Page(Cpu* cpu){
    printf("INC zero page called\n");
    cpu->PC++;
    uint8_t zp_address = memory[cpu->PC];
    uint16_t address = (uint16_t)zp_address;
    printf("Memory at right value???: 0x%02X\n", address);
    uint8_t value = memory[address];
    
    value = value + 1;

    cpu->Z = (value == 0);

    cpu->N = (value & 0x80) != 0;
    memory[address] = value;
    delay = 5;
}
void INC_Zero_Page_X(Cpu* cpu) {
    printf("INC zero page X called\n");
    
    
    cpu->PC ++;
    printf("Calculated pc: 0x%02X\n", cpu->PC);
    
    uint8_t zp_address = memory[cpu->PC];
    uint16_t base_address = (uint16_t)zp_address;
    
    printf("Calculated baseaddress: 0x%02X\n", memory[cpu->PC]);
    uint8_t address = (base_address + cpu->X) & 0xFF;
    

    printf("Calculated address: 0x%02X\n", address);

    
    uint8_t value = memory[address];
    
    value = value + 1;

    cpu->Z = (value == 0);

    cpu->N = (value & 0x80) != 0;
    memory[address] = value;
    delay = 6;
}
void INC_Absolute(Cpu* cpu){
    printf("INC absolute called\n");
    
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];
    cpu->PC ++;
    uint8_t high = memory[cpu->PC]; 
    uint16_t address = (high << 8) | low;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];

    
    value = value + 1;

    cpu->Z = (value == 0);

    cpu->N = (value & 0x80) != 0;
    memory[address] = value;
    delay = 6;
}
void INC_Absolute_X(Cpu* cpu){
    
    printf("INC absolute xxxxx called\n");
    
    cpu->PC ++;
    uint8_t low = memory[cpu->PC];   
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];  
    uint16_t base = (high << 8) | low;
    printf("base: 0x%02X\n", base);
    uint16_t address = base + cpu->X;
    printf("address: 0x%02X\n", address);
    uint8_t value = memory[address];

    
    value = value + 1;

    cpu->Z = (value == 0);

    cpu->N = (value & 0x80) != 0;
    memory[address] = value;
    delay = 7;
}
void clockTick(Cpu* cpu){
    
    uint8_t instruction = memory[cpu->PC];
    switch (instruction) {
        case 0xA9:  
            LDA_Immediate(cpu);
            break;
        case 0xA2:  
            LDX_Immediate(cpu);
            break;
        case 0xA0:  
            LDY_Immediate(cpu);
            break;
        case 0xA5:  
            LDA_Zero_Page(cpu);
            break;
        case 0xA6:  
            LDX_Zero_Page(cpu);
            break;
        case 0xA4:  
            LDY_Zero_Page(cpu);
            break;
        case 0xB5:  
            LDA_Zero_Page_X(cpu);
            break;
            case 0xB6:  
        LDX_Zero_Page_Y(cpu);
            break;
            case 0xB4:
        LDY_Zero_Page_X(cpu);
            break;
        case 0xAD:  
            LDA_Absolute(cpu);
            break;
        case 0xAE:  
            LDX_Absolute(cpu);
            break;
        case 0xAC:  
            LDY_Absolute(cpu);
            break;
        case 0xBD:  
            LDA_Absolute_X(cpu);
            break;
        case 0xBC:
            LDY_Absolute_X(cpu);
            break;
        case 0xB9:  
            LDA_Absolute_Y(cpu);
            break;
        case 0xBE:  
            LDX_Absolute_Y(cpu);
            break;
        case 0xA1:  
            LDA_Indirect_X(cpu);
            break;
        case 0xB1:  
            LDA_Indirect_Y(cpu);
            break;
        //reigsters done!!!
        case 0x69:  
            ADC_Immediate(cpu);
            break;
        case 0xE9:  
            SBC_Immediate(cpu);
            break;
        case 0x6D:  
            ADC_Absolute(cpu);
            break;
        case 0xED:  
            SBC_Absolute(cpu);
            break;
        case 0x65:  
            ADC_Zero_Page(cpu);
            break;
        case 0xE5:  
            SBC_Zero_Page(cpu);
            break;
        case 0x61:  
            ADC_Indirect_X(cpu);
            break;
        case 0xE1:  
            SBC_Indirect_X(cpu);
            break;
        case 0x71:  
            ADC_Indirect_Y(cpu);
            break;
        case 0xF1:  
            SBC_Indirect_Y(cpu);
            break;
        case 0x75:  
            ADC_Zero_Page_X(cpu);
            break;
        case 0xF5:  
            SBC_Zero_Page_X(cpu);
            break;
        case 0x7D:  
            ADC_Absolute_X(cpu);
            break;
        case 0xFD:  
            SBC_Absolute_X(cpu);
            break;
        case 0x79:  
            ADC_Absolute_Y(cpu);
            break;
        case 0xF9:
            SBC_Absolute_Y(cpu);
            break;
        //math done
        case 0x4C:
            JMP_Absolute(cpu);
            break;
        case 0x6C:
            JMP_Indirect(cpu);
            break;
        case 0x20:
            JSR_Absolute(cpu);
            break;
        case 0x60:
            RTS_Implied(cpu);
            break;
        //cmp start
        case 0xC9:
            CMP_Immediate(cpu);
            break;
        case 0xC5:
            CMP_Zero_Page(cpu);
            break;
        case 0xD5:
            CMP_Zero_Page_X(cpu);
            break;
        case 0xCD:
            CMP_Absolute(cpu);
            break;
        case 0xDD:
            CMP_Absolute_X(cpu);
            break;
        case 0xD9:
            CMP_Absolute_Y(cpu);
            break;
        case 0xC1:
            CMP_Indirect_X(cpu);
            break;
        case 0xD1:
            CMP_Indirect_Y(cpu);
            break;
        //CPY start
        case 0xC0:
            CPY_Immediate(cpu);
            break;
        case 0xC4:
            CPY_Zero_Page(cpu);
            break;
        case 0xCC:
            CPY_Absolute(cpu);
            break;
        //CPX start
        case 0xE0:
            CPX_Immediate(cpu);
            break;
        case 0xE4:
            CPX_Zero_Page(cpu);
            break;
        case 0xEC:
            CPX_Absolute(cpu);
            break;
        //STA start
        case 0x85:
            STA_Zero_Page(cpu);
            break;
        case 0x95:
            STA_Zero_Page_X(cpu);
            break;
        case 0x8D:
            STA_Absolute(cpu);
            break;
        case 0x9D:
            STA_Absolute_X(cpu);
            break;
        case 0x99:
            STA_Absolute_Y(cpu);
            break;
        case 0x81:
            STA_Indirect_X(cpu);
            break;
        case 0x91:
            STA_Indirect_Y(cpu);
            break;
        //STX start
        case 0x86:
            STX_Zero_Page(cpu);
            break;
        case 0x96:
            STX_Zero_Page_Y(cpu);
            break;
        case 0x8E:
            STX_Absolute(cpu);
            break;
        //STY start
        case 0x84:
            STY_Zero_Page(cpu);
            break;
        case 0x94:
            STY_Zero_Page_X(cpu);
            break;
        case 0x8C:
            STY_Absolute(cpu);
            break;
        case 0x9A:
            TXS(cpu);
            break;
        case 0xBA:
            TSX(cpu);
            break;
        //stack instructions
        case 0x48:
            PHA(cpu);
            break;
        case 0x68:
            PLA(cpu);
            break;
        case 0x08:
            PHP(cpu);
            break;
        case 0x28:
            PLP(cpu);
            break;
        //flag instructions
        case 0x18:
            CLC(cpu);
            break;
        case 0x38:
            SEC(cpu);
            break;
        case 0x58:
            CLI(cpu);
            break;
        case 0x78:
            SEI(cpu);
            break;
        case 0xB8:
            CLV(cpu);
            break;
        case 0xD8:
            CLD(cpu);
            break;
        case 0xF8:
            SED(cpu);
            break;
        //Register Instructions
        case 0xAA:
            TAX(cpu);
            break;
        case 0x8A:
            TXA(cpu);
            break;
        case 0xCA:
            DEX(cpu);
            break;
        case 0xE8:
            INX(cpu);
            break;
        case 0xA8:
            TAY(cpu);
            break;
        case 0x98:
            TYA(cpu);
            break;
        case 0x88:
            DEY(cpu);
            break;
        case 0xC8:
            INY(cpu);
            break;
        //DO NOTHINGGGG
        case 0xEA:
            NOP(cpu);
            break;
        //Branch Instructions
        case 0x10:
            BPL(cpu);
            break;
        case 0x30:
            BMI(cpu);
            break;
        case 0x50:
            BVC(cpu);
            break;
        case 0x70:
            BVS(cpu);
            break;
        case 0x90:
            BCC(cpu);
            break;
        case 0xB0:
            BCS(cpu);
            break;
        case 0xD0:
            BNE(cpu);
            break;
        case 0xF0:
            BEQ(cpu);
            break;
        //Bitwise and Shift Instructions:
        //AND
        case 0x29:
            AND_Immediate(cpu);
            break;
        case 0x25:
            AND_Zero_Page(cpu);
            break;
        case 0x35:
            AND_Zero_Page_X(cpu);
            break;
        case 0x2D:
            AND_Absolute(cpu);
            break;
        case 0x3D:
            AND_Absolute_X(cpu);
            break;
        case 0x39:
            AND_Absolute_Y(cpu);
            break;
        case 0x21:
            AND_Indirect_X(cpu);
            break;
        case 0x31:
            AND_Indirect_Y(cpu);
            break;
        //EOR
        case 0x49:
            EOR_Immediate(cpu);
            break;
        case 0x45:
            EOR_Zero_Page(cpu);
            break;
        case 0x55:
            EOR_Zero_Page_X(cpu);
            break;
        case 0x4D:
            EOR_Absolute(cpu);
            break;
        case 0x5D:
            EOR_Absolute_X(cpu);
            break;
        case 0x59:
            EOR_Absolute_Y(cpu);
            break;
        case 0x41:
            EOR_Indirect_X(cpu);
            break;
        case 0x51:
            EOR_Indirect_Y(cpu);
            break;
        //ORA
        case 0x09:
            ORA_Immediate(cpu);
            break;
        case 0x05:
            ORA_Zero_Page(cpu);
            break;
        case 0x15:
            ORA_Zero_Page_X(cpu);
            break;
        case 0x0D:
            ORA_Absolute(cpu);
            break;
        case 0x1D:
            ORA_Absolute_X(cpu);
            break;
        case 0x19:
            ORA_Absolute_Y(cpu);
            break;
        case 0x01:
            ORA_Indirect_X(cpu);
            break;
        case 0x11:
            ORA_Indirect_Y(cpu);
            break;
        //ASL
        case 0x0A:
            ASL_Accumulator(cpu);
            break;
        case 0x06:
            ASL_Zero_Page(cpu);
            break;
        case 0x16:
            ASL_Zero_Page_X(cpu);
            break;
        case 0x0E:
            ASL_Absolute(cpu);
            break;
        case 0x1E:
            ASL_Absolute_X(cpu);
            break;
        //LSR
        case 0x4A:
            LSR_Accumulator(cpu);
            break;
        case 0x46:
            LSR_Zero_Page(cpu);
            break;
        case 0x56:
            LSR_Zero_Page_X(cpu);
            break;
        case 0x4E:
            LSR_Absolute(cpu);
            break;
        case 0x5E:
            LSR_Absolute_X(cpu);
            break;
        //ROL
        case 0x2A:
            ROL_Accumulator(cpu);
            break;
        case 0x26:
            ROL_Zero_Page(cpu);
            break;
        case 0x36:
            ROL_Zero_Page_X(cpu);
            break;
        case 0x2E:
            ROL_Absolute(cpu);
            break;
        case 0x3E:
            ROL_Absolute_X(cpu);
            break;
        //ROR
        case 0x6A:
            ROR_Accumulator(cpu);
            break;
        case 0x66:
            ROR_Zero_Page(cpu);
            break;
        case 0x76:
            ROR_Zero_Page_X(cpu);
            break;
        case 0x6E:
            ROR_Absolute(cpu);
            break;
        case 0x7E:
            ROR_Absolute_X(cpu);
            break;
        //BIT
        case 0x24:
            BIT_Zero_Page(cpu);
            break;
        case 0x2C:
            BIT_Absolute(cpu);
            break;
        //BRK
        case 0x00:
            BRK_Implied(cpu);
            break;
        //RTI
        case 0x40:
            RTI_Implied(cpu);
            break;
        //DEC start
        case 0xC6:
            DEC_Zero_Page(cpu);
            break;
        case 0xD6:
            DEC_Zero_Page_X(cpu);
            break;
        case 0xCE:
            DEC_Absolute(cpu);
            break;
        case 0xDE:
            DEC_Absolute_X(cpu);
            break;
        //INC start
        case 0xE6:
            INC_Zero_Page(cpu);
            break;
        case 0xF6:
            INC_Zero_Page_X(cpu);
            break;
        case 0xEE:
            INC_Absolute(cpu);
            break;
        case 0xFE:
            INC_Absolute_X(cpu);
            break;
        default:
            printf("instruction called that was not in the swich stetement: 0x%02X\n", instruction);
            return;
    }
    
    cpu->PC++; 
}
void run(Cpu* cpu){
    while (1)
    {
        if(time >= timer){
            delay = 0;
            clockTick(cpu);
            time = 0;
            timer = delay;
        }
        
        time++;
    }
    
}
void start(Cpu* cpu){
    printf("start called\n");
    cpu->A = 0x00;
    cpu->X = 0x00;
    cpu->Y = 0x00;
    cpu->PC = 0xFFFC;
    cpu->S = 0xFD;

    cpu->C = 1;
    cpu->Z = 0;
    cpu->I = 1;
    cpu->D = 0;
    cpu->B = 0;
    cpu->V = 0;
    cpu->N = 0;

    loadROM("testixd.txt");

    //get the starting location off reset vektor

    uint8_t low = memory[cpu->PC]; 
    cpu->PC ++;
    uint8_t high = memory[cpu->PC];
    uint16_t address = (high << 8) | low;

    cpu->PC = address;

}
void reset(Cpu* cpu){
    printf("reset called\n");
    cpu->PC = 0xFFFC;
    cpu->S = 0xFD;
    
    cpu->I = 1;
    
}