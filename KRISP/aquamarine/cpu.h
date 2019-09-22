#ifndef CPU_H
#define CPU_H

#define INST_ROM_SIZE 512
#define DATA_RAM_SIZE 512
struct cpu {
    uint16_t reg[16];
    uint16_t pc;
    uint8_t inst_rom[INST_ROM_SIZE];
    uint8_t data_ram[DATA_RAM_SIZE];
    uint8_t flag_sign;
    uint8_t flag_overflow;
    uint8_t flag_zero;
    uint8_t flag_carry;
};

#endif