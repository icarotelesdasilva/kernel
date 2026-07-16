#ifndef PIC_H
#define PIC_H

#define PIC1_COMMAND 0x20
#define PIC1_DATA    0x21
#define PIC2_COMMAND 0xA0
#define PIC2_DATA    0xA1

#define ICW1_INIT    0x10
#define ICW1_ICW4    0x01
#define ICW4_8086    0x01

#define PIC_EOI      0x20

     static inline void outb(unsigned short port, unsigned char val) {
 __asm__ volatile ("outb %b0, %w1" : : "a"(val), "Nd"(port));
}

static inline unsigned char inb(unsigned short port) {
    unsigned char ret;
 __asm__ volatile ("inb %w1, %b0" : "=a"(ret) : "Nd"(port));
 return ret;
}

 void pic_remap(int offset1, int offset2);
void pic_send_eoi(unsigned char irq);

#endif
