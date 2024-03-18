#prog3.asm

#DESC: z = a + 2b^2 + 3c^3 + 4d^4 e a,b,c,d são numeros do teclado

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

	#z = a + 2b^2 + 3c^3 + 4d^4
	
	#2b^2
	mult 	$s1, $s1
	mflo 	$t1
	sll 	$t1, $t1, 1
	
	#3c^3
	mult 	$s2, $s2
	mflo 	$t2
	mult 	$s2, $t2
	mflo 	$t2
	addi	$t7, $0, 3
	mult	$t7, $t2
	mflo	$t2
	
	#4d^4
	mult 	$s3, $s3
	mflo 	$t3
	mult 	$s3, $t3
	mflo 	$t3
	mult 	$s3, $t3
	mflo	$t3
	sll	$t3, $t3, 2
	
	#soma
	add 	$t4, $s0, $t1
	add 	$t4, $t4, $t2
	add 	$t4, $t4, $t3
	
	#######
	
	li   	$v0, 1
	move 	$a0, $t4
	syscall
	
	#return 0
	li 	$v0, 10 # equiv. addi $v0,$0,10
	syscall
	
#sugestoes para casa
#a) (a + (a*b) + (a*b*c) + (a*b*c*d))/a+b+c+d
#b) s = a*a - b*b - c*c
#c) USO DO BEQ:
#	se (a < b) | (b > c) -> imprime "yupi"!
#
#