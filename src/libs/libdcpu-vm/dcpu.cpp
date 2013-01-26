#include "dcpu.hpp"
#include <iostream>

namespace DCPU {
    Core::Core()
    {
        Reset(true);
    }

    void Core::Flash(std::vector<uint16_t> words)
    {
        memory = words;
    }

    void Core::Reset(bool reset_memory) 
    {
        pc = 0;
        sp = 0;
        ex = 0;
        ia = 0;
        
        registers = std::vector<uint16_t>(8);
        if(reset_memory)
        {
            memory = std::vector<uint16_t>(0x10000);
        }
    }

    void Core::Cycle() 
    {
        // TODO
    }
}

extern "C" {
    #include "dcpu.h"
    #define GET_CORE(vm) DCPU::Core* core = static_cast<DCPU::Core*>(vm->core);

    vm* vm_create()
    {
        DCPU::Core* core = new DCPU::Core();
        vm* result = (vm*) malloc(sizeof(vm));

        result->core = static_cast<void*>(core);
        result->registers = &(core->registers[0]);
        result->memory = &(core->memory[0]);

        return result;
    }

    void vm_cycle(vm* l_vm)
    {
        GET_CORE(l_vm);
        core->Cycle();
    }

    void vm_flash(vm* l_vm, uint16_t* words)
    {
       GET_CORE(l_vm); 
       std::vector<uint16_t> memory(0x10000);
       memory.assign(words, words + 0x10000);

       core->Flash(memory);
    }
}
