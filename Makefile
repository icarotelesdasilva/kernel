# Kernel-Ícaro (vmicaro)
# Copyright (c) 2026 Ícaro Teles da Silva (@icarotelesdasilva)
# 
# This code is part of the Kernel-Ícaro project.
# Licensed under the GPL v3 License.
# 
# Copying, modification, or redistribution is prohibited without
# maintaining this copyright and authorship notice.


ASM     = nasm
CC      = gcc
LD      = ld -m elf_i386
CONVERT = convert

CFLAGS = -m32 -ffreestanding -nostdlib -fno-pic

boot.o: boot/boot.asm
	$(ASM) -f elf32 boot/boot.asm -o boot.o

kernel.o: src/kernel.c
	$(CC) $(CFLAGS) -c src/kernel.c -o kernel.o

vmicaro: boot.o kernel.o gdt.o gdt_asm.o idt.o idt_asm.o mem.o pmm.o pic_asm.o pic.o     
	$(LD) -T linker.ld boot.o kernel.o gdt.o gdt_asm.o idt.o idt_asm.o mem.o pmm.o pic_asm.o pic.o -o vmicaro

gdt.o: GDT/gdt.c
	$(CC) $(CFLAGS) -c GDT/gdt.c -o gdt.o

gdt_asm.o: GDT/gdt.asm
	$(ASM) -f elf32 GDT/gdt.asm -o gdt_asm.o

idt.o: IDT/idt.c
	$(CC) $(CFLAGS) -c IDT/idt.c -o idt.o

idt_asm.o: IDT/idt.asm
	$(ASM) -f elf32 IDT/idt.asm -o idt_asm.o

mem.o: memory/mem.c
	$(CC) $(CFLAGS) -c memory/mem.c -o mem.o

pmm.o: memory/pmm.c
	$(CC) $(CFLAGS) -c memory/pmm.c -o pmm.o

pic.o: PIC/pic.c
	$(CC) $(CFLAGS) -c PIC/pic.c -o pic.o 

pic_asm.o: PIC/pic.asm 
	$(ASM) -f elf32 PIC/pic.asm -o pic_asm.o

all: vmicaro
	mkdir -p isodir/boot/grub
	cp vmicaro isodir/boot/vmicaro
	cp boot/grub/grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o vmicaro.iso isodir/


clean:
	rm -f *.o vmicaro vmicaro.iso
	rm -rf isodir/
