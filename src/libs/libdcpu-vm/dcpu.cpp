#include "dcpu.hpp"
#include <iostream>

namespace DCPU {
    Core::Core()
    {
        Reset(true);
    }

    void Core::Flash(uint16_t words[0x10000])
    {
        for(int i = 0; i < 0x10000; i++)
            memory[i] = words[i];
    }

    void Core::Reset(bool reset_memory) 
    {
        pc = 0;
        sp = 0;
        ex = 0;
        ia = 0;
       
        for(int i = 0; i < 8; i++)
            registers[i] = 0;
             
        if(reset_memory)
        {
            for(int i = 0; i < 0x10000; i++)
                memory[i] = 0;
        }
    }

    void Core::Cycle() 
    {
        // TODO
    }
}

extern "C" {
    #include "dcpu.h"
    #define GET_CORE(vm) DCPU::Core* core = reinterpret_cast<DCPU::Core*>(vm);

    vm* vm_create()
    {
        return (vm*) new DCPU::Core();
    }

    void vm_cycle(vm* l_vm)
    {
        GET_CORE(l_vm);
        core->Cycle();
    }

    void vm_flash(vm* l_vm, uint16_t words[0x10000])
    {
       GET_CORE(l_vm); 
       core->Flash(words);
    }
}
