#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Algoritmo do QuickSort Básico

void quickSortBasico (int vetor[], int n) {
  qbSort(vetor, 0, n-1);
}

void qbSort (int vetor[], int esq, int dir) {
  int meio;
  if (esq < dir) {
    meio = particao (vetor, esq, dir);
    qbSort (vetor, esq, meio);
    qbSort (vetor, meio + 1, dir);
  }
}

/*
  INTEIRO (STRUCT)
*/

void quickSortBasicoInteiro (Produto vetor[], int n) {
  qbSortInteiro(vetor, 0, n-1);
}

void qbSortInteiro (Produto vetor[], int esq, int dir) {
  int meio;
  if (esq < dir) {
    meio = particaoInteiro (vetor, esq, dir);
    qbSortInteiro (vetor, esq, meio);
    qbSortInteiro (vetor, meio + 1, dir);
  }
}

/*
  REAL
*/
void quickSortBasicoReal (Produto vetor[], int n) {
  qbSortReal(vetor, 0, n-1);
}

void qbSortReal (Produto vetor[], int esq, int dir) {
  int meio;
  if (esq < dir) {
    meio = particaoReal (vetor, esq, dir);
    qbSortReal (vetor, esq, meio);
    qbSortReal (vetor, meio + 1, dir);
  }
}

/*
  STRING
*/
void quickSortBasicoChar (Produto vetor[], int n) {
  qbSortChar(vetor, 0, n-1);
}

void qbSortChar (Produto vetor[], int esq, int dir) {
  int meio;
  if (esq < dir) {
    meio = particaoChar (vetor, esq, dir);
    qbSortChar (vetor, esq, meio);
    qbSortChar (vetor, meio + 1, dir);
  }
}
