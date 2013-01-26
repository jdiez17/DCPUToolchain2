#ifndef DCPU_HPP
#define DCPU_HPP

#include <vector>
#include <stdint.h>

namespace DCPU 
{
    class Core 
    {
    public:
        uint16_t registers[8];
        uint16_t memory[0x10000];
        uint16_t pc;
        uint16_t sp;
        uint16_t ex;
        uint16_t ia; 

        Core();
        void Flash(uint16_t words[0x10000]);
        void Reset(bool reset_memory);
        void Cycle();

    };
}


#endif
