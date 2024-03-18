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
	
	#a*a
	mult $s0, $s0
	mflo $t0
	
	#b*b
	mult $s1, $s1
	mflo $t1
	
	#c*c
	mult $s2, $s2
	mflo $t2
	
	#subtração + atriubuição
	sub $t7, $t0, $t1
	sub $t7, $t7, $t2
	
	#mostrar na tela
	li   	$v0, 1
	move 	$a0, $t7
	syscall
	
	
	#return 0
	li 	$v0, 10 
	syscall
	


