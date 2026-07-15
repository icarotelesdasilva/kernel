; Kernel-Ícaro (vmicaro)
; Copyright (c) 2026 Ícaro Teles da Silva (@icarotelesdasilva)
; 
; This code is part of the Kernel-Ícaro project.
; Licensed under the GPL v3 License.
; 
; Copying, modification, or redistribution is prohibited without
; maintaining this copyright and authorship notice.


BITS 32

global gdt_flush

gdt_flush:
 MOV  eax, [esp+4]
lgdt [eax]

MOV ax, 0x10
MOV ds, ax
 MOV  es, ax
MOV fs, ax
MOV    gs, ax
MOV  ss, ax


jmp 0x08:.flush

.flush:
    ret
