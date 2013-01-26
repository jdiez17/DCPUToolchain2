#include <dcpu.h>
#include <stdio.h>
#include <assert.h>

int main(int argc, char** argv)
{
    vm* core = vm_create();

    core->registers[1] = 0xdead;
    assert(core->registers[1] == 0xdead);

    return 0;
}
