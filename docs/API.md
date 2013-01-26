C API
======
VM struct
---------
The VM struct is defined as follows:

	typedef struct {
    	uint16_t registers[8];
    	uint16_t memory[0x10000];
    	uint16_t pc;
    	uint16_t sp;
    	uint16_t ex;
    	uint16_t ia; 
	} vm;

Registers are A-J are stored in the order that the [DCPU spec](http://dcpu.com/dcpu-16/) describes.

Methods
-------

libdcpu-vm provides a C API. Its methods are described here.

<table>
    <tr>
        <th>
            Method signature
        </th>
        <th>
            Description
        </th>
    </tr>
    <tr>
        <td>
            vm* vm_create();
        </td>
        <td>
            Creates a DCPU object.
        </td>
    </tr>
    <tr>
        <td>
            void vm_cycle(vm* l_vm);
        </td>
        <td>
            Executes a single instruction.
        </td>
    </tr>
    <tr>
        <td>
           void vm_flash(vm* l_vm, uint16_t words[0x10000]);

        </td>
        <td>
            Flashes the DCPU memory with the data in the `words` array.
        </td>
   </tr>
</table> 



