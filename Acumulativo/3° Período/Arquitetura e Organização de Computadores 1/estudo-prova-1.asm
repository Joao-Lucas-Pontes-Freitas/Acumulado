.data
arr:	.space 4000
str:	.asciiz "Número Inválido\n"
str1: 	.asciiz "\n"
str2:	.asciiz	"Novo Array: \n"
.text


	beq $s0, 42, PULA 

       	la  $s0, 0x00400054 

       	not $s0, $s1 


	#Lê e testa o número
	addi 	$v0, $0, 5
	syscall
	add 	$s0, $0, $v0
	slti	$t0, $s0, 1000
	beq	$t0, $0, Inválido
	slti	$t0, $s0, 0
	bne	$t0, $0, Inválido

	addi	$s1, $0, 0
	la	$s7, arr
FOR1:
	slt	$t0, $s1, $s0
	beq	$t0, $0, SAI1
	
	addi	$v0, $0, 5
	syscall
	add	$t1, $0, $v0
	sw	$t1, 0($s7)
	
	addi	$s1, $s1, 1
	addi	$s7, $s7, 4
	j FOR1
	
SAI1:
	addi	$v0, $0, 4
	la	$a0, str2
	syscall

	addi	$s1, $0, 0
	la	$s7, arr
FOR2:
	slt	$t0, $s1, $s0
	beq	$t0, $0, SAI2
	
	lw	$t1, 0($s7)
	addi	$t2, $0, 1
	and	$t2, $t1, $t2
	
	bne	$t2, $0, Ímpar
Volta: 
	lw	$t4, 0($s7)
	addi	$v0, $0, 1
	add 	$a0, $0, $t4
	syscall
	addi	$v0, $0, 4
	la	$a0, str1
	syscall
	
	addi 	$s1, $s1, 1
	addi 	$s7, $s7, 4
	j FOR2
	
	
SAI2:
	
FIM:
	addi	$v0, $0, 10
	syscall
	
Inválido:
	la	$a0, str
	addi	$v0, $0, 4
	syscall
	j FIM
	
Ímpar: 
	mult	$t1, $t1
	mflo	$t3
	mult	$t1, $t3
	mflo 	$t3
	sw	$t3, 0($s7)
	j Volta
	