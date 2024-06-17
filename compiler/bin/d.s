	.file	1 "d.sil"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module fp=xx
	.module nooddspreg
	.abicalls
	.text
	.globl	arr
	.section	.bss,"aw",@nobits
	.align	2
	.type	arr, @object
	.size	arr, 64
arr:
	.space	64
	.globl	len
	.align	2
	.type	len, @object
	.size	len, 4
len:
	.space	4
	.globl	i
	.align	2
	.type	i, @object
	.size	i, 4
i:
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
	lui	$20,%hi(len)
	addiu	$20,$20,%lo(len)
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
	lui	$2,%hi(i)
	sw	$20,%lo(i)($2)
	.option	pic0  # Assemble for position-independent code
	b	$L2  # Branch to (loop check)
	nop

	.option	pic2  # Assemble for absolute code
$L3:   # Loop start
	lui	$2,%hi(i)
	lw	$19,%lo(i)($2)
	lui	$20,%hi(arr)
	addiu	$20,$20,%lo(arr)
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
	lui	$20,%hi(i)
	lw	$20,%lo(i)($20)
	addiu	$2,$20,1
	lui	$20,%hi(i)
	sw	$2,%lo(i)($20)
	addiu	$20,$2,-1
$L2: # Loop check
	lui	$2,%hi(i)
	lw	$19,%lo(i)($2)
	lui	$2,%hi(len)
	lw	$18,%lo(len)($2)
	slt	$20,$19,$18
	bne	$20,$0,$L3
	nop

$L4:
	li	$20,0
	lui	$2,%hi(i)
	sw	$20,%lo(i)($2)
	.option	pic0  # Assemble for position-independent code
	b	$L5  # Branch to (loop check)
	nop

	.option	pic2  # Assemble for absolute code
$L6:   # Loop start
	lui	$2,%hi(i)
	lw	$18,%lo(i)($2)
	lui	$2,%hi(arr)
	addiu	$2,$2,%lo(arr)
	sll	$18,$18,2
	addu	$2,$2,$18
	lw	$19,0($2)
	lui	$2,%hi(i)
	lw	$18,%lo(i)($2)
	sne	$20,$19,$18
	beq	$20,$0,$LL2
	nop

	beq	$0,$0,$L7
	nop

	.option	pic0
	b	$LL3
	nop

	.option	pic2
$LL2:
$LL3:
	lui	$20,%hi(i)
	lw	$20,%lo(i)($20)
	addiu	$2,$20,1
	lui	$20,%hi(i)
	sw	$2,%lo(i)($20)
	addiu	$20,$2,-1
$L5: # Loop check
	lui	$2,%hi(i)
	lw	$19,%lo(i)($2)
	lui	$2,%hi(len)
	lw	$18,%lo(len)($2)
	slt	$20,$19,$18
	bne	$20,$0,$L6
	nop

$L7:
	lui	$2,%hi(i)
	lw	$20,%lo(i)($2)
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
