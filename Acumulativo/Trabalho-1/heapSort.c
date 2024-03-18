#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void criaHeap(int vet[], int i, int f) {
  int aux = vet[i];
  int j = i * 2 + 1;
  while (j <= f) {
    if (j < f) {
      if (vet[j] < vet[j + 1]) {
        j = j + 1;
      }
    }
    if (aux < vet[j]) {
      vet[i] = vet[j];
      i = j;
      j = 2 * i + 1;
    } else {
      j = f + 1;
    }
  }
  vet[i] = aux;
}

void heapSort(int vet[], int N) {
  int i, aux;
  for (i = (N - 1) / 2; i >= 0; i--) {
    criaHeap(vet, i, N - 1);
  }
  for (i = N - 1; i >= 1; i--) {
    aux = vet[0];
    vet[0] = vet[i];
    vet[i] = aux;
    criaHeap(vet, 0, i - 1);
  }
}

/*
  INTEIRO (STRUCT)
*/

void criaHeapInteiro(Produto vet[], int i, int f) {
  int aux = vet[i].codigo;
  int j = i * 2 + 1;
  while (j <= f) {
    if (j < f) {
      if (vet[j].codigo < vet[j + 1].codigo) {
        j = j + 1;
      }
    }
    if (aux < vet[j].codigo) {
      vet[i].codigo = vet[j].codigo;
      i = j;
      j = 2 * i + 1;
    } else {
      j = f + 1;
    }
  }
  vet[i].codigo = aux;
}

void heapSortInteiro(Produto vet[], int N) {
  int i, aux;
  for (i = (N - 1) / 2; i >= 0; i--) {
    criaHeapInteiro(vet, i, N - 1);
  }
  for (i = N - 1; i >= 1; i--) {
    aux = vet[0].codigo;
    vet[0].codigo = vet[i].codigo;
    vet[i].codigo = aux;
    criaHeapInteiro(vet, 0, i - 1);
  }
}

/*
  REAL
*/
void criaHeapReal(Produto vet[], int i, int f) {
  float aux = vet[i].preco;
  int j = i * 2 + 1;
  while (j <= f) {
    if (j < f) {
      if (vet[j].preco < vet[j + 1].preco) {
        j = j + 1;
      }
    }
    if (aux < vet[j].preco) {
      vet[i].preco = vet[j].preco;
      i = j;
      j = 2 * i + 1;
    } else {
      j = f + 1;
    }
  }
  vet[i].preco = aux;
}

void heapSortReal(Produto vet[], int N) {
  int i;
  float aux;
  for (i = (N - 1) / 2; i >= 0; i--) {
    criaHeapReal(vet, i, N - 1);
  }
  for (i = N - 1; i >= 1; i--) {
    aux = vet[0].preco;
    vet[0].preco = vet[i].preco;
    vet[i].preco = aux;
    criaHeapReal(vet, 0, i - 1);
  }
}

/*
  STRING
*/
void criaHeapChar(Produto vet[], int i, int f) {
  char aux[MAX];
  strcpy(aux, vet[i].descricao);
  int j = i * 2 + 1;
  while (j <= f) {
    if (j < f) {
      if (strcmp(vet[j].descricao, vet[j+1].descricao) < 0) {
        j = j + 1;
      }
    }
    if (strcmp(aux, vet[j].descricao) < 0) {
      strcpy(vet[i].descricao, vet[j].descricao);
      i = j;
      j = 2 * i + 1;
    } else {
      j = f + 1;
    }
  }
  strcpy(vet[i].descricao, aux);
}

void heapSortChar(Produto vet[], int N) {
  int i;
  char aux[MAX];
  for (i = (N - 1) / 2; i >= 0; i--) {
    criaHeapChar(vet, i, N - 1);
  }
  for (i = N - 1; i >= 1; i--) {
    strcpy(aux, vet[0].descricao);
    strcpy(vet[0].descricao, vet[i].descricao);
    strcpy(vet[i].descricao, aux);
    criaHeapChar(vet, 0, i - 1);
  }
}