	.file	1 "b.sil"
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
	.size	a, 16
a:
	.space	16
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
	li	$19,0
	lui	$20,%hi(a)
	addiu	$20,$20,%lo(a)
	sll	$19,$19,2
	addu	$20,$20,$19
	move	$5,$20
	lui	$2,%hi($LC0)
	addiu	$4,$2,%lo($LC0)
	lw	$2,%call16(__isoc99_scanf)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,__isoc99_scanf
1:	jalr	$25
	nop

	lw	$28,16($fp)
	li	$19,1
	lui	$20,%hi(a)
	addiu	$20,$20,%lo(a)
	sll	$19,$19,2
	addu	$20,$20,$19
	move	$5,$20
	lui	$2,%hi($LC0)
	addiu	$4,$2,%lo($LC0)
	lw	$2,%call16(__isoc99_scanf)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,__isoc99_scanf
1:	jalr	$25
	nop

	lw	$28,16($fp)
	li	$19,2
	lui	$20,%hi(a)
	addiu	$20,$20,%lo(a)
	sll	$19,$19,2
	addu	$20,$20,$19
	move	$5,$20
	lui	$2,%hi($LC0)
	addiu	$4,$2,%lo($LC0)
	lw	$2,%call16(__isoc99_scanf)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,__isoc99_scanf
1:	jalr	$25
	nop

	lw	$28,16($fp)
	li	$20,3
	li	$16,0
	lui	$2,%hi(a)
	addiu	$2,$2,%lo(a)
	sll	$16,$16,2
	addu	$2,$2,$16
	lw	$17,0($2)
	li	$3,1
	lui	$2,%hi(a)
	addiu	$2,$2,%lo(a)
	sll	$3,$3,2
	addu	$2,$2,$3
	lw	$16,0($2)
	add	$18,$17,$16
	li	$16,2
	lui	$2,%hi(a)
	addiu	$2,$2,%lo(a)
	sll	$16,$16,2
	addu	$2,$2,$16
	lw	$17,0($2)
	add	$19,$18,$17
	lui	$2,%hi(a)
	addiu	$2,$2,%lo(a)            # $2 contains address(a)
	sll	$20,$20,2
	addu	$2,$2,$20
	sw	$19,0($2)
	li	$19,3
	lui	$2,%hi(a)
	addiu	$2,$2,%lo(a)
	sll	$19,$19,2
	addu	$2,$2,$19
	lw	$20,0($2)
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
