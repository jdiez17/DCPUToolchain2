#include "dcpu.hpp"

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
    vm* vm_create() {
        DCPU::Core* core = new DCPU::Core();
        vm* result = (vm*) malloc(sizeof(vm));

        result->core = static_cast<void*>(core);
        result->registers = &(core->registers[0]);
        return result;
    }
}
