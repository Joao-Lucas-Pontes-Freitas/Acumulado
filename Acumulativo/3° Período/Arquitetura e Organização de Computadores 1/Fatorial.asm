.include "utils.asm"

.data
	str:	.asciiz "Digite um numero inteiro: "
	str1:	.asciiz	"O fatorial de "
	str2:	.asciiz	" = "
.text
MAIN:
	printStr(str)
	readInt($s0)
	
	#setar os argumentos
	add	$a0, $0, $s0
	
	#chamar fucao
	jal Fat
	
	#peagr o restorno
	add	$s2, $0, $v0
	printStr(str1)
	printInt($s0)
	printStr(str2)
	printInt($s2)
	
	return0
	
Fat:
	#salvar contexto
	PUSH
	
	#corpo da funcao
	addi	$s0, $0, 1
	
	#condição de parada
	addi	$t0, $0, 1
	beq	$a0, $t0, Parada
	
	#copia
	add	$s7, $0, $a0
	
	addi	$a0, $a0, -1
	jal	Fat
	
	mult	$s7, $v0
	mflo	$s0
	#\corpo da funcao

	#retorno 
Parada:	add	$v0, $s0, $0

	#restaurar contexto
	POP
	
	#retornar controle ao fluxo chamador original
	jr $ra
	
	
	
	
	
	
	
	