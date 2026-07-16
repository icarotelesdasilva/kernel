#include "pic.h"

extern void vga_print(const char* srt);

int timer_ticks = 0;

void pic_remap(int offset1, int offset2) {
unsigned char m1, m2;

m1= inb (PIC1_DATA);
m2 = inb(PIC2_DATA);

outb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);
outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);

outb(PIC1_DATA, ICW4_8086);
outb(PIC2_DATA, m1);
outb(PIC1_DATA, m2);

}


void pic_send_eoi(unsigned char irq) {
if (irq >= 8) {

outb(PIC2_COMMAND, PIC_EOI);

}
outb(PIC1_COMMAND, PIC_EOI);
}

void pit_handler_c(void) {
timer_ticks++;
if (timer_ticks % 100 == 0) {

vga_print("PING ");
}

pic_send_eoi(0);

}	
