#include <vector>
#include <stdint.h>

namespace DCPU 
{
    class Core 
    {
    public:
        Core();
        void Flash(std::vector<uint16_t> words);
        void Reset(bool reset_memory);
        void Cycle();

        std::vector<uint16_t> registers;
        std::vector<uint16_t> memory;
        uint16_t pc;
        uint16_t sp;
        uint16_t ex;
        uint16_t ia; 
    };
}
