#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"


void criarVetor(int v[], int t, int qtd) {
  srand(time(NULL) * qtd);
    for (int i = 0; i < t; i++)
      v[i] = rand() % t + 1;
}

void mostraVetor(int v[], int t) {
  for (int i = 0; i < t; i++)
      printf("%d ", v[i]);
  printf("\n");
}

void copiaVetor(int copia[], int vet[], int tam) {
  for (int i = 0; i < tam; i++)
    copia[i] = vet[i];
}