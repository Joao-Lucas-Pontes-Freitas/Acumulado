#include "ordenacao.h"

void selectionSort(int vetor[], int n) {
  int temp;
  int menor, i, j;
  for (i = 0; i < n - 1; i++) { 
    menor = i;
    for (j = i + 1; j < n; j++) {
      if (vetor[j] < vetor[menor]) { 
        menor = j; 
      } 
    }   
    temp = vetor[i]; 
    vetor[i] = vetor[menor];
    vetor[menor] = temp; 
  } 
} 