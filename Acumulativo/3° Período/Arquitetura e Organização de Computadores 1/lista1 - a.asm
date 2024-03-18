#sugestoes para casa
#a) (a + (a*b) + (a*b*c) + (a*b*c*d))/a+b+c+d
#b) s = a*a - b*b - c*c
#c) USO DO BEQ:
#	se (a < b) | (b > c) -> imprime "yupi"!

.data


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
	
	#le d
	li 	$v0, 5
	syscall
	add 	$s3, $0, $v0
	
	#dividendo
	#a*b
	mult $s0, $s1
	mflo $t0
	#a*b*c
	mult $t0, $s2
	mflo $t1
	#a*b*c*d
	mult $t1, $s3
	mflo $t2
	#soma
	add $t6, $s0, $t0
	add $t6, $t6, $t1
	add $t6, $t6, $t2
	
	#divisor
	add $t7, $s0, $s1
	add $t7, $t7, $s2
	add $t7, $t7, $s3

	#divisão
	div $t6, $t7
	mflo $t5
	
	#mostrar na tela
	li   	$v0, 1
	move 	$a0, $t5
	syscall
	
	
	#return 0
	li 	$v0, 10 
	syscall
	


