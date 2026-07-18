/*
 * Kernel-Ícaro (vmicaro)
 * Copyright (c) 2026 Ícaro Teles da Silva (@icarotelesdasilva)
 *
 * Licensed under the MIT License.
 */

#include "gdt.h"   
#include "idt.h"   
extern void pmm_init(void);
extern void* pmm_alloc_page(void);
extern void kernel_panic(char *str);
extern void vga_print(const char* str);  
void kmain(void) {
    if (gdt_init() != 0) {
        kernel_panic("Kernel Panic!\nUnable to load GDT.");
        while(1);
    }

    if (inicializar_idt() != 0) {
        kernel_panic("Kernel Panic!\nUnable to load IDT.");
        while(1);
    }
pmm_init();
void* pagina_teste = pmm_alloc_page();

    vga_print("Hello, Kernel!");

    while (1);
}
