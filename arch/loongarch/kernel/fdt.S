.section .fdt, "aw", @progbits
.globl _dtb_start
_dtb_start:
	.incbin "./arch/loongarch/boot/loongson3_ls7a.dtb"
.globl _dtb_end
