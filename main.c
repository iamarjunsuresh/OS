// main.c -- Defines the C-code kernel entry point, calls initialisation routines.
//           Made for JamesM's tutorials <www.jamesmolloy.co.uk>

#include "monitor.h"
#include "descriptor_tables.h"
#include "timer.h"
#include "mouse.h"
#include "key.h"
#include "paging.h"
//#include "kheap.h"

int main(struct multiboot *mboot_ptr)
{
    // Initialise all the ISRs and segmentation
    init_descriptor_tables();
    // Initialise the screen (by clearing it)
    monitor_clear();
    // Write out a sample string
    monitor_write("Hello, world!\n");

    asm volatile("int $0x3");
    asm volatile("int $0x4");

    asm volatile("sti");
    //init_timer(50);
    //mouse_install();
installkb();

initialise_paging();

   u32int *ptr = (u32int*)0xA0000000;
   u32int do_page_fault = *ptr;


    return 0;
}
