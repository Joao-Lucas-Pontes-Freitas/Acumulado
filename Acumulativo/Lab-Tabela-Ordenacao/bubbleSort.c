#include <stdio.h>
#include "ordenacao.h"

void bubbleSort(int vetor[], int tam) {
  int temp, i, j;
  for (i = 0; i < tam ; i++) {
    for (j = 0; j< tam - 1 - i; j++) { 
      if (vetor[j+1] < vetor[j]) { 
        temp = vetor[j]; 
        vetor[j] = vetor[j+1]; 
        vetor[j+1] = temp; 
      } 
    } 
  }
}