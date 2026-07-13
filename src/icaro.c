
/*
 * Kernel-Ícaro (vmicaro)
 * Copyright (c) 2026 Ícaro Teles da Silva (@icarotelesdasilva)
 * 
 * This code is part of the Kernel-Ícaro project.
 * Licensed under the GPL v3 License.
 * 
 * Copying, modification, or redistribution is prohibited without
 * maintaining this copyright and authorship notice.
 */


#include "drivers/vga.c"
#include "../system/gdt.h" 

unsigned char bitmap[5] = {0, 0, 0, 0, 0};
void  alocar_memoria() {
for (int i =  0; i < 5;  i++) {

if (bitmap[i] == 0) {

bitmap[i] = 1;

break;

}
}
}

void limpar_memoria() {

for (int i = 0; i < 5; i++) {

if (bitmap[i] == 1) {

bitmap[i] = 0;

break;

}
}
}

void criar_filtro();
void inicializar_filtro();



void kmain(void)  {
gdt_init();
inicializar_filtro();
vga_print("Hello, Kernel!");




while(1) {

}
}
