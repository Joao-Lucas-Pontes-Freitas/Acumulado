#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cocktailSort(int list[], int n) {
  int length, bottom, top, swapped, i, aux;
  length = n;
  bottom = 0;
  top = length - 1;
  swapped = 0;
  while (swapped == 0 && bottom < top) {
    swapped = 1;

    for (i = bottom; i < top; i = i + 1) {
      if (list[i] > list[i + 1]) {
        aux = list[i];
        list[i] = list[i + 1];
        list[i + 1] = aux;
        swapped = 0;
      }
    }
    top = top - 1;

    for (i = top; i > bottom; i = i - 1) {
      if (list[i] < list[i - 1]) {
        aux = list[i];
        list[i] = list[i - 1];
        list[i - 1] = aux;
        swapped = 0;
      }
    }

    bottom = bottom + 1;
  }
}
/*
  INTEIRO (STRUCT)
*/
void cocktailSortInteiro(Produto list[], int n) {
  int length, bottom, top, swapped, i, aux;
  length = n;
  bottom = 0;
  top = length - 1;
  swapped = 0;
  while (swapped == 0 && bottom < top) {
    swapped = 1;

    for (i = bottom; i < top; i = i + 1) {
      if (list[i].codigo > list[i + 1].codigo) {
        aux = list[i].codigo;
        list[i].codigo = list[i + 1].codigo;
        list[i + 1].codigo = aux;
        swapped = 0;
      }
    }
    top = top - 1;

    for (i = top; i > bottom; i = i - 1) {
      if (list[i].codigo < list[i - 1].codigo) {
        aux = list[i].codigo;
        list[i].codigo = list[i - 1].codigo;
        list[i - 1].codigo = aux;
        swapped = 0;
      }
    }

    bottom = bottom + 1;
  }
}

/*
  REAL
*/

void cocktailSortReal(Produto list[], int n) {
  int length, bottom, top, swapped, i;
  float aux;
  length = n;
  bottom = 0;
  top = length - 1;
  swapped = 0;
  while (swapped == 0 && bottom < top) {
    swapped = 1;

    for (i = bottom; i < top; i = i + 1) {
      if (list[i].preco > list[i + 1].preco) {
        aux = list[i].preco;
        list[i].preco = list[i + 1].preco;
        list[i + 1].preco = aux;
        swapped = 0;
      }
    }
    top = top - 1;

    for (i = top; i > bottom; i = i - 1) {
      if (list[i].preco < list[i - 1].preco) {
        aux = list[i].preco;
        list[i].preco = list[i - 1].preco;
        list[i - 1].preco = aux;
        swapped = 0;
      }
    }

    bottom = bottom + 1;
  }
}

/*
  STRING
*/

void cocktailSortChar(Produto list[], int n) {
  int length, bottom, top, swapped, i;
  char aux[MAX];
  length = n;
  bottom = 0;
  top = length - 1;
  swapped = 0;
  while (swapped == 0 && bottom < top) {
    swapped = 1;

    for (i = bottom; i < top; i = i + 1) {
      if (strcmp(list[i].descricao, list[i+1].descricao) > 0){
        strcpy(aux, list[i].descricao);
        strcpy(list[i].descricao, list[i+1].descricao); 
        strcpy(list[i+1].descricao, aux);
        swapped = 0;
      }
    }
    top = top - 1;

    for (i = top; i > bottom; i = i - 1) {
      if (strcmp(list[i].descricao, list[i-1].descricao) < 0) {
        strcpy(aux, list[i].descricao); 
        strcpy(list[i].descricao, list[i-1].descricao);
        strcpy(list[i-1].descricao, aux);
        swapped = 0;
      }
    }

    bottom = bottom + 1;
  }
}