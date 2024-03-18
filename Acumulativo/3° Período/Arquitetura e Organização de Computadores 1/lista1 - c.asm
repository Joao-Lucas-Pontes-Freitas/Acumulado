#sugestoes para casa
#a) (a + (a*b) + (a*b*c) + (a*b*c*d))/a+b+c+d
#b) s = a*a - b*b - c*c
#c) USO DO BEQ:
#	se (a < b) | (b > c) -> imprime "yupi"!

.data

	str1: .asciiz "Yupiiiiiiiiiiiiii!"

.text
	#le a
	li  	$v0, 5
	syscall
	add 	$s0, $0, $v0
	
	#le b
	li 	$v0, 5
	syscall
	add 	$s1, $0, $v0
	
	#le c
	li 	$v0, 5
	syscall
	add 	$s2, $0, $v0
	
	#atrubuir -1 a um registrador para comparações futuras
	addi 	$s3, $0, -1
	
	#atrubuir -1 a um registrador para comparações futuras
	addi 	$s5, $0, 1
	
	#analisar sinal de a
	div 	$s0, $s0
	mflo 	$t0
	#analisar sinal de b
	div 	$s1, $s1
	mflo 	$t1
	#analisar sinal de c
	div 	$s2, $s2
	mflo 	$t2
	
	#compara sinal a e b
	beq	$t0, $t1, Mesmo_Sinal
	#ve se a é negativo e b positivo
	beq	$t0, $s3, Verdadeiro
	j Comparacao2
	
Comparacao2:
	#compara sinal c e b
	beq	$t2, $t1, Mesmo_Sinal2
	#ve se c é negativo e b positivo
	beq	$t2, $s3, Verdadeiro
	j SAI
		
Mesmo_Sinal: 
	#subtrai e compara sinal
	sub	$s4, $s0, $s1
	blez 	$s4, Verdadeiro
	j Comparacao2
	
Mesmo_Sinal2: 
	#subtrai e compara sinal
	sub	$s4, $s2, $s1
	blez 	$s4, Verdadeiro
	j SAI

Verdadeiro: 
	#mostra na tela verdadeiro
	addi 	$v0, $0,4
	la 	$a0,str1
	syscall
	j SAI

	
SAI:	
	#return 0
	addi $v0, $0, 10
	syscall


