#ifndef PIC_H
#define PIC_H

#include <stdint.h>

void outb(uint16_t port, uint8_t val);
void pic_init();

#endif
