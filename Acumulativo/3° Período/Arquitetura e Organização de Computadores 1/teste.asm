.include "utils.asm"

.data

.text

	beq 	$s0, 42, SAI
	#addi $s1, $0, 42
	#beq $s0, $s1, PULA

       	la 	$s0, 0x00400054 
       	lui	$1, 0x00000040
       	ori	$s0, $1, 0x00000054

       	not 	$s0, $s1 
       	nor	$s0, $s1, $0

SAI: 
	addi	$v0, $0, 10
	syscall
