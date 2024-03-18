.data 

str1:       .asciiz "digite a string\n" 

size_str2:  .word 30	 

str2:       .space 30 

 

.text 
	#pede a strin para o usuario
      li    $v0,4 
      la    $a0,str1 
      syscall 
      
      #le a string
      li    $v0,8 
      la    $a0,str2 
      li    $a1,30 
      syscall 
      
      
      #contador
      addi  $s7, $zero, 0x0a #codigo \n
      #endereço primeira posição da string
      la    $t0, str2 
      
      #pega o caractere na posição do endereço $t0 e comapara com \n
L:    lb    $s0, 0($t0) 
      beq   $s0,$s7, END 
      
      #converte a letra em maiuscula
      addi  $s0, $s0, -32 
      sb    $s0, 0($t0) 
      
      addi  $t0, $t0,1 
      j     L 
      
      #printa nova string 
END:  li    $v0,4 
      la    $a0,str2 
      syscall 
      #fim
      li    $v0, 10 
      syscall 