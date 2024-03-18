#macro.asm

.include "utils.asm"

.data
	buff: 	.space 128
	str1: 	.asciiz "Estamos testando macros!!!"
	strcr:	.asciiz "\n"
	
.text
	#addi	$t0, $zero, 42
	#printInt($t0)
	printStr(str1)
	readStr(buff, 10)
	#printStr(strcr)
	printStr(buff)
	readInt($t7)
	printInt($t7)
	
	#li $v0, 10
	#syscall
	return0