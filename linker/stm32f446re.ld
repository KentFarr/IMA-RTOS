

ENTRY(Reset_Handler)





MEMORY
{
        FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 512K
        RAM(rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}
_estack = ORIGIN(RAM) + LENGTH(RAM);



SECTIONS
{

.isr_vector :
  {
    KEEP(*(.isr_vector));
    . = ALIGN(4);
  }> FLASH
    .text :
  {
    *(.text*)
    . = ALIGN(4);
  } > FLASH

  .rodata :
  {
    *(.rodata*)
    . = ALIGN(4);
  } > FLASH

  .data :
  {
    _sdata = .;
    *(.data*)
    . = ALIGN(4);
    _edata = .;
  } > RAM AT > FLASH
  _sidata = LOADADDR(.data);

  .bss :
  {
    _sbss = .;
    *(.bss*)
    *(COMMON)
    . = ALIGN(4);
    _ebss = .;
  } > RAM

}