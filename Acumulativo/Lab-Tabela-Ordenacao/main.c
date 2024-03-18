/*
   * Enzo Lazzarini Amorim (12121BCC049) 
   * João Lucas Pontes Freitas (12121BCC006)
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "ordenacao.h"

#define MAX 10000

int main(void) {
  srand(time(NULL));
  //ex 1,2,3
  tabela(MAX);
  printf("\n\n");
  tabela(MAX*5);
  printf("\n\n");
  tabela(MAX*10);
  
  // ex 4

  // criar vetor
  int v[10][MAX], i;
  for (i = 0; i < 10; i++)
    criarVetor(v[i], MAX, i+1);

  //10 vetores para média, primria posição é comparações, segunda é troca
  int dados[10][2];
  for (i = 0; i < 10; i++)
    for(int j = 0; j < 2; j++)
      dados[i][j] = 0;
  
  //varaivies de media
  float media1 = 0, media2 = 0;

  //chama o abcsort pra cada um dos 10 vetores diferentes criados
  for (i = 0; i < 10; i++)
    abcSort2(v[i], 0, MAX -1, &dados[i][0], &dados[i][1]);

  //soma
  for(i = 0; i < 10; i++)
    media1 += (float)dados[i][0];
  
  for(i = 0; i < 10; i++)
    media2 += (float)dados[i][1];
  
  //media
  media1 /= 10.0;
  media2 /= 10.0;
  //mostra
  printf("Media de comparações \t Media de trocas\n");
  printf("%f \t         %f\n", media1, media2);
  return 0;
}
