#ifndef DCPU_H
#define DCPU_H

#include <stdint.h>

typedef struct {
    void* core;
    uint16_t* memory;
    uint16_t* registers;
} vm;

vm* vm_create();

#endif DCPU_H
