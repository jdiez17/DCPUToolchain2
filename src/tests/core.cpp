#include <iostream>
#include <dcpu.hpp>
#include <assert.h>

int main(int argc, char** argv)
{
    DCPU::Core core;

    core.pc = 0xdead;
    assert(core.pc == 0xdead);
}
