#ifndef DCPU_H
#define DCPU_H

#include <stdint.h>

typedef struct {
    void* core;
    uint16_t* memory;
    uint16_t* registers;
} vm;

vm* vm_create();
void vm_cycle(vm* l_vm);
void vm_flash(vm* l_vm, uint16_t* words);


#endif
