#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void flip(int arr[], int i) {
  int temp, start = 0;
  while (start < i) {
    temp = arr[start];
    arr[start] = arr[i];
    arr[i] = temp;
    start++;
    i--;
  }
}

int findMax(int arr[], int n) {
  int mi, i;
  for (mi = 0, i = 0; i < n; ++i)
    if (arr[i] > arr[mi])
      mi = i;
  return mi;
}

void pancakeSort(int arr[], int n) {
  for (int curr_size = n; curr_size > 1; --curr_size) {
    int mi = findMax(arr, curr_size);
    if (mi != curr_size - 1) {
      flip(arr, mi);
      flip(arr, curr_size - 1);
    }
  }
}

/*
  INTEIRO (STRUCT)
*/

void flipInteiro(Produto arr[], int i) {
  int temp, start = 0;
  while (start < i) {
    temp = arr[start].codigo;
    arr[start].codigo = arr[i].codigo;
    arr[i].codigo = temp;
    start++;
    i--;
  }
}

int findMaxInteiro(Produto arr[], int n) {
  int mi, i;
  for (mi = 0, i = 0; i < n; ++i)
    if (arr[i].codigo > arr[mi].codigo)
      mi = i;
  return mi;
}

void pancakeSortInteiro(Produto arr[], int n) {
  for (int curr_size = n; curr_size > 1; --curr_size) {
    int mi = findMaxInteiro(arr, curr_size);
    if (mi != curr_size - 1) {
      flipInteiro(arr, mi);
      flipInteiro(arr, curr_size - 1);
    }
  }
}

/*
  REAL
*/
void flipReal(Produto arr[], int i) {
  int start = 0;
  float temp;
  while (start < i) {
    temp = arr[start].preco;
    arr[start].preco = arr[i].preco;
    arr[i].preco = temp;
    start++;
    i--;
  }
}

int findMaxReal(Produto arr[], int n) {
  int mi, i;
  for (mi = 0, i = 0; i < n; ++i)
    if (arr[i].preco > arr[mi].preco)
      mi = i;
  return mi;
}

void pancakeSortReal(Produto arr[], int n) {
  for (int curr_size = n; curr_size > 1; --curr_size) {
    int mi = findMaxReal(arr, curr_size);
    if (mi != curr_size - 1) {
      flipReal(arr, mi);
      flipReal(arr, curr_size - 1);
    }
  }
}

void flipChar(Produto arr[], int i) {
  int start = 0;
  char temp[MAX];
  while (start < i) {
    strcpy(temp, arr[start].descricao);
    //temp = arr[start].codigo;
    strcpy(arr[start].descricao, arr[i].descricao);
    //arr[start].codigo = arr[i].codigo;
    strcpy(arr[i].descricao, temp);
    //arr[i].codigo = temp;
    start++;
    i--;
  }
}

int findMaxChar(Produto arr[], int n) {
  int mi, i;
  for (mi = 0, i = 0; i < n; ++i)
    if (strcmp(arr[i].descricao, arr[mi].descricao) > 0/*arr[i].codigo > arr[mi].codigo*/)
      mi = i;
  return mi;
}

void pancakeSortChar(Produto arr[], int n) {
  for (int curr_size = n; curr_size > 1; --curr_size) {
    int mi = findMaxChar(arr, curr_size);
    if (mi != curr_size - 1) {
      flipChar(arr, mi);
      flipChar(arr, curr_size - 1);
    }
  }
}