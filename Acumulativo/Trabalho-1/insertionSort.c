#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionSort (int vet[], int n) {
  int i, j, tmp; 
  for (i = 1; i < n; i++) {
    tmp = vet[i]; 
    for (j = i-1; j >= 0 && vet[j] > tmp; j--) 
      vet[j+1] = vet[j]; 
    vet[j+1] = tmp; 
  }
}

void insertionSortInteiro (Produto vet[], int n) {
  int i, j, tmp; 
  for (i = 1; i < n; i++) {
    tmp = vet[i].codigo; 
    for (j = i-1; j >= 0 && vet[j].codigo > tmp; j--) 
      vet[j+1].codigo = vet[j].codigo; 
    vet[j+1].codigo = tmp; 
  }
}

void insertionSortReal (Produto vet[], int n) {
  int i, j;
  float tmp; 
  for (i = 1; i < n; i++) {
    tmp = vet[i].preco; 
    for (j = i-1; j >= 0 && vet[j].preco > tmp; j--) 
      vet[j+1].preco = vet[j].preco; 
    vet[j+1].preco = tmp; 
  }
}

void insertionSortChar (Produto vet[], int n) {
  int i, j;
  char tmp[MAX]; 
  for (i = 1; i < n; i++) {
    strcpy(tmp,vet[i].descricao);
    for (j = i-1; j >= 0 && strcmp(vet[j].descricao,tmp) > 0; j--) 
      strcpy(vet[j+1].descricao, vet[j].descricao);
    strcpy(vet[j+1].descricao, tmp);
  }
}