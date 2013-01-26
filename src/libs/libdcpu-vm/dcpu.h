#ifndef DCPU_H
#define DCPU_H

#include <stdint.h>

typedef struct {
    uint16_t registers[8];
    uint16_t memory[0x10000];
    uint16_t pc;
    uint16_t sp;
    uint16_t ex;
    uint16_t ia; 
} vm;

vm* vm_create();
void vm_cycle(vm* l_vm);
void vm_flash(vm* l_vm, uint16_t words[0x10000]);


#endif
