ENTRY(_start)

MEMORY
{
  iram0_1_seg (RX) : ORIGIN = 0x40080000, LENGTH = 0x20000
}

SECTIONS
{
  .iram0.text :
  {
    . = ALIGN(4);
    KEEP(*(.iram0.literal))
    KEEP(*(.literal))
    KEEP(*(.iram0.text))
    KEEP(*(.text))
    . = ALIGN(4);
  } > iram0_1_seg
}
