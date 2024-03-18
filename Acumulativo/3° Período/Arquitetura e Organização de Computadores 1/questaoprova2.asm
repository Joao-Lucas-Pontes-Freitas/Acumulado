.data 
arr:	.space	84
	
.text	
	not	$s3, $s1
	addi	$s0, $0, 42
	addi	$s2, $0, 22
	#la	$s7, arr
	lui	$at, 0x00001001
	ori	$s7, $at, 0x00000000
	
	addi	$s1, $0, 1
FOR:
	slt	$t0, $s1, $s2
	beq	$t0, $0, SAI
	
	mult	$s0, $s1
	mflo	$t1
	sw	$t1, 0($s7)
	
	addi	$s7, $s7, 4
	addi	$s1, $s1, 1
	j FOR
	
SAI: 
	addi $v0, $0, 10
	syscall	
