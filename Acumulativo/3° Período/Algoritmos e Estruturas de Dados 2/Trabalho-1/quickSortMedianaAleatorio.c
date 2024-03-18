#include <stdlib.h>
#include <time.h>
#include "funcoes.h"
#include <string.h>

int particaoAleatoria1(int vet[], int esq, int dir) {
  int pivot = vet[esq];
  int i = esq - 1, j = dir + 1;

  if ((dir - esq) < 5)
    insertionSort(vet, dir - esq);
  while (1) {
    do {
      i++;
    } while (vet[i] < pivot);

    do {
      j--;
    } while (vet[j] > pivot);

    if (i >= j)
      return j;

    troca(vet, i, j);
  }
}

int particaoAleatoria2(int vet[], int esq, int dir) {
  srand(time(0));
  int random = esq + rand() % (dir - esq);

  troca(vet,random,esq);

  return particaoAleatoria1(vet, esq, dir);
}

void quickSortMedianaAleatorio(int vet[], int esq, int dir) {
  if (esq < dir) {
    int pi = particaoAleatoria2(vet, esq, dir);

    quickSortMedianaAleatorio(vet, esq, pi);
    quickSortMedianaAleatorio(vet, pi + 1, dir);
  }
}


/*
  INTEIRO (STRUCT)
*/

int particaoAleatoria1Inteiro(Produto vet[], int esq, int dir) {
  int pivot = vet[esq].codigo;
  int i = esq - 1, j = dir + 1;

  if ((dir - esq) < 5)
    insertionSortInteiro(vet, dir - esq);
  while (1) {
    do {
      i++;
    } while (vet[i].codigo < pivot);

    do {
      j--;
    } while (vet[j].codigo > pivot);

    if (i >= j)
      return j;

    trocaInteiro(vet, i, j);
  }
}

int particaoAleatoria2Inteiro(Produto vet[], int esq, int dir) {
  srand(time(0));
  int random = esq + rand() % (dir - esq);

  trocaInteiro(vet,random,esq);

  return particaoAleatoria1Inteiro(vet, esq, dir);
}

void quickSortMedianaAleatorioInteiro(Produto vet[], int esq, int dir) {
  if (esq < dir) {
    int pi = particaoAleatoria2Inteiro(vet, esq, dir);

    quickSortMedianaAleatorioInteiro(vet, esq, pi);
    quickSortMedianaAleatorioInteiro(vet, pi + 1, dir);
  }
}

/*
  REAL
*/


int particaoAleatoria1Real(Produto vet[], int esq, int dir) {
  float pivot = vet[esq].preco;
  int i = esq - 1, j = dir + 1;

  if ((dir - esq) < 5)
    insertionSortReal(vet, dir - esq);
  while (1) {
    do {
      i++;
    } while (vet[i].preco < pivot);

    do {
      j--;
    } while (vet[j].preco > pivot);

    if (i >= j)
      return j;

    trocaReal(vet, i, j);
  }
}

int particaoAleatoria2Real(Produto vet[], int esq, int dir) {
  srand(time(0));
  int random = esq + rand() % (dir - esq);

  trocaReal(vet,random,esq);

  return particaoAleatoria1Real(vet, esq, dir);
}

void quickSortMedianaAleatorioReal(Produto vet[], int esq, int dir) {
  if (esq < dir) {
    int pi = particaoAleatoria2Real(vet, esq, dir);

    quickSortMedianaAleatorioReal(vet, esq, pi);
    quickSortMedianaAleatorioReal(vet, pi + 1, dir);
  }
}


/*
  STRING
*/


int particaoAleatoria1Char(Produto vet[], int esq, int dir) {
  char pivot[MAX];
  strcpy(pivot, vet[esq].descricao);
  int i = esq - 1, j = dir + 1;

  if ((dir - esq) < 5)
    insertionSortChar(vet, dir - esq);
  while (1) {
    do {
      i++;
    } while (strcmp(vet[i].descricao, pivot) < 0);

    do {
      j--;
    } while (strcmp(vet[j].descricao, pivot) > 0);

    if (i >= j)
      return j;

    trocaChar(vet, i, j);
  }
}

int particaoAleatoria2Char(Produto vet[], int esq, int dir) {
  srand(time(0));
  int random = esq + rand() % (dir - esq);

  trocaChar(vet,random,esq);
  
  return particaoAleatoria1Char(vet, esq, dir);
}

void quickSortMedianaAleatorioChar(Produto vet[], int esq, int dir) {
  if (esq < dir) {
    int pi = particaoAleatoria2Char(vet, esq, dir);

    quickSortMedianaAleatorioChar(vet, esq, pi);
    quickSortMedianaAleatorioChar(vet, pi + 1, dir);
  }
}