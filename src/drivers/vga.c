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



char *vga  = (char*)0xB8000;
int coluna = 0;
int linha  = 0;

void vga_print(char *str) {

    int i = 0;

    while(str[i] != '\0') {

        if(str[i] == '\n') {
            coluna = 0;
            linha++;
        }
        else {
            int pos = (linha * 80 + coluna) * 2;
            vga[pos]   = str[i];
            vga[pos+1] = 0x03;
            coluna++;
        }

        if(coluna >= 80) {
            coluna = 0;
            linha++;
        }

        i++;
    }
}
