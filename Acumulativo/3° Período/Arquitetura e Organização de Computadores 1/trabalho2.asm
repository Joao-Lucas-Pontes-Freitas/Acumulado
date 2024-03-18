.data
	buff: .space 128
	str1: .asciiz "Digite o tamanho da String até 10: "
	str2: .asciiz "Digite a String: "
	str3: .asciiz "\n "
.text
	#escreve str1
	li	$v0, 4
	la	$a0, str1
	syscall
	
	# le tamanho
	li	$v0, 5
	syscall
	move	$s1, $v0
	addi	$s1, $s1, 1
	
	#escreve str2
	li	$v0, 4
	la	$a0, str2
	syscall

	#pega o endereco pra string
	li	$v0, 8
	la	$a0, buff
	add	$a1, $zero, $s1
	syscall
	
	#for
	add	$s0, $zero, $zero
	addi	$s1, $s1, -1
	
FOR:
	slt	$t0, $s0, $s1
	beq	$t0, $zero, SAI
	#corpo do for
	lb	$s7, 0($a0)
	addi	$s7, $s7, -32 	#soma codigo ascii
	sb      $s7, 0($a0)
	#\corpo do for
	addi	$s0, $s0, 1 #soma 1 no contador
	addi	$a0, $a0, 1 #soma 1 no endreço armazenado em a0
	j	FOR
	
	#printa e encerra
SAI:	
	li	$v0, 4
	la	$a0, str3
	syscall
	
	li	$v0, 4
	la	$a0, buff
	syscall
	
	li $v0, 10
	syscall
