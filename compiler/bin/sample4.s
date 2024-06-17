	.file	1 "sample4.sil"
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
	.globl	key
	.align	2
	.type	key, @object
	.size	key, 4
key:
	.space	4
	.globl	found
	.align	2
	.type	found, @object
	.size	found, 4
found:
	.space	4
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
	lui	$20,%hi(key)
	addiu	$20,$20,%lo(key)
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
	lui	$2,%hi(found)
	sw	$20,%lo(found)($2)
	li	$20,0
	lui	$2,%hi(index)
	sw	$20,%lo(index)($2)
	.option	pic0  # Assemble for position-independent code
	b	$L2  # Branch to (loop check)
	nop

	.option	pic2  # Assemble for absolute code
$L3:   # Loop start
	lui	$2,%hi(index)
	lw	$18,%lo(index)($2)
	lui	$2,%hi(array)
	addiu	$2,$2,%lo(array)
	sll	$18,$18,2
	addu	$2,$2,$18
	lw	$19,0($2)
	lui	$2,%hi(key)
	lw	$18,%lo(key)($2)
	seq	$20,$19,$18
	beq	$20,$0,$LL2
	nop

	li	$20,1
	lui	$2,%hi(found)
	sw	$20,%lo(found)($2)
	.option	pic0
	b	$LL3
	nop

	.option	pic2
$LL2:
$LL3:
	lui	$20,%hi(index)
	lw	$20,%lo(index)($20)
	addiu	$2,$20,1
	lui	$20,%hi(index)
	sw	$2,%lo(index)($20)
	addiu	$20,$2,-1
$L2: # Loop check
	lui	$2,%hi(index)
	lw	$19,%lo(index)($2)
	li	$18,4
	slt	$20,$19,$18
	bne	$20,$0,$L3
	nop

$L4:
	lui	$2,%hi(found)
	lw	$19,%lo(found)($2)
	li	$18,1
	seq	$20,$19,$18
	beq	$20,$0,$LL4
	nop

	li	$20,1
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
	.option	pic0
	b	$LL5
	nop

	.option	pic2
$LL4:
	li	$20,0
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
$LL5:
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
