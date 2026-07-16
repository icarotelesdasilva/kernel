#include "pic.h"
extern void vga_print(const char* srt);
static const char kbd_us[128] = {

	0,  27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b', /* Backspace */
  '\t', /* Tab */ 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', /* Enter */
    0, /* Control */ 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 
    0, /* Left Shift */ '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 
    0, /* Right Shift */ '*', 0, /* Alt */ ' ', /* Space */
};

volatile char utima_tecla = 0;
void keyboard_handler_c(void) {
unsigned char scancode = inb(0x60);
pic_send_eoi(1);
if (scancode < 0x80) {
char key = kbd_us[scancode];
if (key != 0) {
	char srt[2] = {key, '\0'};
	    utima_tecla = key;
}	
}	
}



char kgetc(void) {
while (utima_tecla == 0) {
asm volatile("hlt");
}

char tecla = utima_tecla;
utima_tecla = 0;
return tecla;

}
