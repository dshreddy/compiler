	.file	1 "sample3.sil"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module fp=xx
	.module nooddspreg
	.abicalls
	.text
	.globl	a
	.section	.bss,"aw",@nobits
	.align	2
	.type	a, @object
	.size	a, 40
a:
	.space	40
	.globl	b
	.align	2
	.type	b, @object
	.size	b, 40
b:
	.space	40
	.globl	index
	.align	2
	.type	index, @object
	.size	index, 4
index:
	.space	4
	.rdata
	.align	2
$LC0:
	.ascii	"%d\000"
	.text
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp,32,$31		# vars= 0, regs= 1/0, args= 0, gp= 0
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-32
	sw	$31,28($sp)
	sw	$fp,24($sp)
	move	$fp,$sp
	lui	$28,%hi(__gnu_local_gp)
	addiu	$28,$28,%lo(__gnu_local_gp)
	.cprestore	16
	li	$20,0
	lui	$2,%hi(index)
	sw	$20,%lo(index)($2)
	.option	pic0  # Assemble for position-independent code
	b	$L2  # Branch to (loop check)
	nop

	.option	pic2  # Assemble for absolute code
$L3:   # Loop start
	lui	$2,%hi(index)
	lw	$20,%lo(index)($2)
	lui	$2,%hi(index)
	lw	$18,%lo(index)($2)
	li	$17,10
	add	$19,$18,$17
	lui	$2,%hi(a)
	addiu	$2,$2,%lo(a)            # $2 contains address(a)
	sll	$20,$20,2
	addu	$2,$2,$20
	sw	$19,0($2)
	lui	$2,%hi(index)
	lw	$20,%lo(index)($2)
	lui	$2,%hi(index)
	lw	$18,%lo(index)($2)
	li	$17,2
	mul	$19,$18,$17
	lui	$2,%hi(b)
	addiu	$2,$2,%lo(b)            # $2 contains address(a)
	sll	$20,$20,2
	addu	$2,$2,$20
	sw	$19,0($2)
	lui	$2,%hi(index)
	lw	$20,%lo(index)($2)
	move	$5,$20
	lui	$2,%hi($LC0)
	addiu	$4,$2,%lo($LC0)
	lw	$2,%call16(printf)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,printf
1:	jalr	$25
	nop

	lw	$28,16($fp)
	li	$4,10			# 0xa
	lw	$2,%call16(putchar)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,putchar
1:	jalr	$25
	nop

	lw	$28,16($fp)
	lui	$2,%hi(index)
	lw	$18,%lo(index)($2)
	lui	$2,%hi(a)
	addiu	$2,$2,%lo(a)
	sll	$18,$18,2
	addu	$2,$2,$18
	lw	$19,0($2)
	lui	$2,%hi(index)
	lw	$17,%lo(index)($2)
	lui	$2,%hi(b)
	addiu	$2,$2,%lo(b)
	sll	$17,$17,2
	addu	$2,$2,$17
	lw	$18,0($2)
	add	$20,$19,$18
	move	$5,$20
	lui	$2,%hi($LC0)
	addiu	$4,$2,%lo($LC0)
	lw	$2,%call16(printf)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,printf
1:	jalr	$25
	nop

	lw	$28,16($fp)
	li	$4,10			# 0xa
	lw	$2,%call16(putchar)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,putchar
1:	jalr	$25
	nop

	lw	$28,16($fp)
	lui	$2,%hi(index)
	lw	$19,%lo(index)($2)
	li	$18,1
	add	$20,$19,$18
	lui	$2,%hi(index)
	sw	$20,%lo(index)($2)
$L2: # Loop check
	lui	$2,%hi(index)
	lw	$19,%lo(index)($2)
	li	$18,10
	slt	$20,$19,$18
	bne	$20,$0,$L3
	nop

$L4:
	move	$2,$0
	move	$sp,$fp
	lw	$31,28($sp)
	lw	$fp,24($sp)
	addiu	$sp,$sp,32
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (Ubuntu 10.3.0-1ubuntu1) 10.3.0"
	.section	.note.GNU-stack,"",@progbits
