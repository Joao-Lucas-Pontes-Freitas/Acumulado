.data
	str1: .asciiz "Digite um inteiro: "
	str2: .asciiz "O numero eh par!"
	str3: .asciiz "O numero eh impar!"
.text

		#le o primeiro inteiro
		addi 	$v0, $0,4
		la 	$a0,str1
		syscall
		
		addi 	$v0,$0,5
		syscall		
		add 	$s0,$0,$v0

		addi 	$s7,$0,1
		and 	$s7,$s7,$s0		
		
		beq	$s7,$0,PAR
		#imprime q eh impar
		addi 	$v0, $0,4
		la 	$a0,str3
		syscall
		
		j SAI
PAR:		#imprime q eh par
		addi 	$v0, $0,4
		la 	$a0,str2
		syscall
		
SAI:
		#return 0
		addi $v0, $0, 10
		syscall