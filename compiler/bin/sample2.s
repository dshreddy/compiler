	.file	1 "sample2.sil"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module fp=xx
	.module nooddspreg
	.abicalls
	.text
	.globl	array
	.section	.bss,"aw",@nobits
	.align	2
	.type	array, @object
	.size	array, 20
array:
	.space	20
	.globl	filter
	.align	2
	.type	filter, @object
	.size	filter, 12
filter:
	.space	12
	.globl	convolution
	.align	2
	.type	convolution, @object
	.size	convolution, 12
convolution:
	.space	12
	.globl	sum
	.align	2
	.type	sum, @object
	.size	sum, 4
sum:
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
	li	$19,-1
	lui	$2,%hi(filter)
	addiu	$2,$2,%lo(filter)            # $2 contains address(a)
	sll	$20,$20,2
	addu	$2,$2,$20
	sw	$19,0($2)
	li	$20,1
	li	$19,0
	lui	$2,%hi(filter)
	addiu	$2,$2,%lo(filter)            # $2 contains address(a)
	sll	$20,$20,2
	addu	$2,$2,$20
	sw	$19,0($2)
	li	$20,1
	li	$19,1
	lui	$2,%hi(filter)
	addiu	$2,$2,%lo(filter)            # $2 contains address(a)
	sll	$20,$20,2
	addu	$2,$2,$20
	sw	$19,0($2)
	li	$19,0
	lui	$20,%hi(array)
	addiu	$20,$20,%lo(array)
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
	lui	$20,%hi(array)
	addiu	$20,$20,%lo(array)
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
	lui	$20,%hi(array)
	addiu	$20,$20,%lo(array)
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
	li	$19,3
	lui	$20,%hi(array)
	addiu	$20,$20,%lo(array)
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
	li	$19,4
	lui	$20,%hi(array)
	addiu	$20,$20,%lo(array)
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
	li	$20,0
	li	$3,0
	lui	$2,%hi(array)
	addiu	$2,$2,%lo(array)
	sll	$3,$3,2
	addu	$2,$2,$3
	lw	$16,0($2)
	li	$4,0
	lui	$2,%hi(filter)
	addiu	$2,$2,%lo(filter)
	sll	$4,$4,2
	addu	$2,$2,$4
	lw	$3,0($2)
	mul	$17,$16,$3
	li	$4,1
	lui	$2,%hi(array)
	addiu	$2,$2,%lo(array)
	sll	$4,$4,2
	addu	$2,$2,$4
	lw	$3,0($2)
	li	$5,1
	lui	$2,%hi(filter)
	addiu	$2,$2,%lo(filter)
	sll	$5,$5,2
	addu	$2,$2,$5
	lw	$4,0($2)
	mul	$16,$3,$4
	add	$18,$17,$16
	li	$3,2
	lui	$2,%hi(array)
	addiu	$2,$2,%lo(array)
	sll	$3,$3,2
	addu	$2,$2,$3
	lw	$16,0($2)
	li	$4,2
	lui	$2,%hi(filter)
	addiu	$2,$2,%lo(filter)
	sll	$4,$4,2
	addu	$2,$2,$4
	lw	$3,0($2)
	mul	$17,$16,$3
	add	$19,$18,$17
	lui	$2,%hi(convolution)
	addiu	$2,$2,%lo(convolution)            # $2 contains address(a)
	sll	$20,$20,2
	addu	$2,$2,$20
	sw	$19,0($2)
	li	$20,1
	li	$3,1
	lui	$2,%hi(array)
	addiu	$2,$2,%lo(array)
	sll	$3,$3,2
	addu	$2,$2,$3
	lw	$16,0($2)
	li	$4,0
	lui	$2,%hi(filter)
	addiu	$2,$2,%lo(filter)
	sll	$4,$4,2
	addu	$2,$2,$4
	lw	$3,0($2)
	mul	$17,$16,$3
	li	$4,2
	lui	$2,%hi(array)
	addiu	$2,$2,%lo(array)
	sll	$4,$4,2
	addu	$2,$2,$4
	lw	$3,0($2)
	li	$5,1
	lui	$2,%hi(filter)
	addiu	$2,$2,%lo(filter)
	sll	$5,$5,2
	addu	$2,$2,$5
	lw	$4,0($2)
	mul	$16,$3,$4
	add	$18,$17,$16
	li	$3,3
	lui	$2,%hi(array)
	addiu	$2,$2,%lo(array)
	sll	$3,$3,2
	addu	$2,$2,$3
	lw	$16,0($2)
	li	$4,2
	lui	$2,%hi(filter)
	addiu	$2,$2,%lo(filter)
	sll	$4,$4,2
	addu	$2,$2,$4
	lw	$3,0($2)
	mul	$17,$16,$3
	add	$19,$18,$17
	lui	$2,%hi(convolution)
	addiu	$2,$2,%lo(convolution)            # $2 contains address(a)
	sll	$20,$20,2
	addu	$2,$2,$20
	sw	$19,0($2)
	li	$20,2
	li	$3,2
	lui	$2,%hi(array)
	addiu	$2,$2,%lo(array)
	sll	$3,$3,2
	addu	$2,$2,$3
	lw	$16,0($2)
	li	$4,0
	lui	$2,%hi(filter)
	addiu	$2,$2,%lo(filter)
	sll	$4,$4,2
	addu	$2,$2,$4
	lw	$3,0($2)
	mul	$17,$16,$3
	li	$4,3
	lui	$2,%hi(array)
	addiu	$2,$2,%lo(array)
	sll	$4,$4,2
	addu	$2,$2,$4
	lw	$3,0($2)
	li	$5,1
	lui	$2,%hi(filter)
	addiu	$2,$2,%lo(filter)
	sll	$5,$5,2
	addu	$2,$2,$5
	lw	$4,0($2)
	mul	$16,$3,$4
	add	$18,$17,$16
	li	$3,4
	lui	$2,%hi(array)
	addiu	$2,$2,%lo(array)
	sll	$3,$3,2
	addu	$2,$2,$3
	lw	$16,0($2)
	li	$4,2
	lui	$2,%hi(filter)
	addiu	$2,$2,%lo(filter)
	sll	$4,$4,2
	addu	$2,$2,$4
	lw	$3,0($2)
	mul	$17,$16,$3
	add	$19,$18,$17
	lui	$2,%hi(convolution)
	addiu	$2,$2,%lo(convolution)            # $2 contains address(a)
	sll	$20,$20,2
	addu	$2,$2,$20
	sw	$19,0($2)
	li	$17,0
	lui	$2,%hi(convolution)
	addiu	$2,$2,%lo(convolution)
	sll	$17,$17,2
	addu	$2,$2,$17
	lw	$18,0($2)
	li	$16,1
	lui	$2,%hi(convolution)
	addiu	$2,$2,%lo(convolution)
	sll	$16,$16,2
	addu	$2,$2,$16
	lw	$17,0($2)
	add	$19,$18,$17
	li	$17,2
	lui	$2,%hi(convolution)
	addiu	$2,$2,%lo(convolution)
	sll	$17,$17,2
	addu	$2,$2,$17
	lw	$18,0($2)
	add	$20,$19,$18
	lui	$2,%hi(sum)
	sw	$20,%lo(sum)($2)
	li	$18,0
	lui	$2,%hi(convolution)
	addiu	$2,$2,%lo(convolution)
	sll	$18,$18,2
	addu	$2,$2,$18
	lw	$19,0($2)
	lui	$2,%hi(sum)
	lw	$18,%lo(sum)($2)
	div	$20,$19,$18
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
	li	$18,1
	lui	$2,%hi(convolution)
	addiu	$2,$2,%lo(convolution)
	sll	$18,$18,2
	addu	$2,$2,$18
	lw	$19,0($2)
	lui	$2,%hi(sum)
	lw	$18,%lo(sum)($2)
	div	$20,$19,$18
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
	li	$18,2
	lui	$2,%hi(convolution)
	addiu	$2,$2,%lo(convolution)
	sll	$18,$18,2
	addu	$2,$2,$18
	lw	$19,0($2)
	lui	$2,%hi(sum)
	lw	$18,%lo(sum)($2)
	div	$20,$19,$18
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
