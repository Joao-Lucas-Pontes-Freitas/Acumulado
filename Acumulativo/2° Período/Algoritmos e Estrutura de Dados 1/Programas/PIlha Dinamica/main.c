#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

int main(void) {
  Pilha *p = criar();
  /* LETRA A

  int it;
  push(p, 11);

  push(p, 34);

  pop(p, &it);

  pop(p, &it);

  push(p, 23);

  push(p, 45);

  pop(p, &it);

  push(p, 121);

  push(p, 22);

  pop(p, &it);

  pop(p, &it);
  mostrar(p);*/

  /*LETRA B

  char it[30];
  printf("Digite a palavra:\n");
  fgets(it, 30, stdin);

  if (palindromo(it) == 0)
    printf("Palindromo\n");
  else
    printf("Nao Palindromo\n");



  */
  /*
  LETRA C*/
  char it[30];
  printf("Digite a sequencia:\n");
  fgets(it, 30, stdin);

  if (validar(it) == 0)
    printf("correto\n");
  else
    printf("errado\n");

  limpar(p);
  return 0;
}
