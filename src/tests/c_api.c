#include <dcpu.h>
#include <stdio.h>
#include <assert.h>

int main(int argc, char** argv)
{
    vm* core = vm_create();

    core->registers[1] = 0xdead;
    assert(core->registers[1] == 0xdead);

    uint16_t memory[0x10000];
    memory[0] = 0xdead;
    memory[0x5000] = 0xbeef;
    memory[0xffff] = 0xface;
    vm_flash(core, memory);
    assert(core->memory[0] == 0xdead);
    assert(core->memory[0x5000] == 0xbeef);
    assert(core->memory[0xffff] == 0xface);

    return 0;
}
