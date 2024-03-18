#include "ordenacao.h"

void insertionSort (int vet[], int n) {
  int i, j, tmp; 
  for (i = 1; i < n; i++) {
    tmp = vet[i]; 
    for (j = i-1; j >= 0 && vet[j] > tmp; j--) 
      vet[j+1] = vet[j]; 
    vet[j+1] = tmp; 
  }
}