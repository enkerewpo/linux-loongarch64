.section .fdt, "aw", @progbits
.globl _dtb_start
_dtb_start:
	.incbin "/home/wheatfox/Documents/Code/loongvisor/dts/loongson3_ls7a.dtb"
.globl _dtb_end
