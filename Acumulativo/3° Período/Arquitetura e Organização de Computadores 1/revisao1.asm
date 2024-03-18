.include "utils.asm"

.data

arr1: .space 40
str1: .asciiz "\n"
.text
	la	$s7, arr1
	add	$s0, $zero, $zero
	addi	$s4, $0, 2
	sll	$s5, $s4, 2
	
FOR:	slti	$t0, $s0, 10
	beq	$t0, $0, SAI
	#corpo do for
	addi	$t1, $s0, 1
	sw	$t1, 0($s7)
	addi	$s7, $s7, 4
	#/corpo do for
	addi	$s0, $s0, 1
	j FOR

#para cada valor no array calcule arr[i] = arr[i]^3 + arr[i]^2 + 42*arr + 42
SAI:	
	add	$s0, $zero, $zero
	la	$s7, arr1
	
FOR2:	
	slti	$t0, $s0, 10
	beq	$t0, $0, SAI2
	#corpo do for
	lw	$s1, 0($s7)
	
	mult	$s1, $s1
	mflo	$t1
	mult	$t1, $s1
	mflo	$t2
	addi	$t3, $zero, 42
	mult	$s1, $t3
	mflo	$t3
	add	$t4, $0, $t1
	add 	$t4, $t4, $t2
	add	$t4, $t4, $t3
	addi	$t4, $t4, 42
	
	sw	$t4, 0($s7)
	addi	$s7, $s7, 4
	#/corpo do for
	addi	$s0, $s0, 1
	j FOR2

SAI2:
	return0
