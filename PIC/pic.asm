global irq0_handler
extern pit_handler_c

section .text


irq0_handler:
pusha
call pit_handler_c
popa
iret
