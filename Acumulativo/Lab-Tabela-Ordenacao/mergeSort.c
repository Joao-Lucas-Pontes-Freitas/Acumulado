#include "ordenacao.h"

void mergeSort(int vetor[], int n) { 
  int aux[n];
  m_sort(vetor, aux , 0, n-1);
}
void m_sort(int vetor[], int aux[], int esq, int dir) { 
  int meio; 
  if (dir > esq) { 
    meio = (dir + esq)/ 2;
    m_sort(vetor, aux, esq, meio);       
    m_sort(vetor, aux, meio+1, dir);     
    merge(vetor, aux, esq, meio+1, dir); 
  } 
}
void merge(int vetor[], int aux[], int esq, int meio, int dir) {
  int i, esq_fim, n;
  esq_fim = meio-1;   
  i = esq;           
  n = dir - esq + 1;  
  while (esq <= esq_fim && meio <= dir) { 
    if (vetor[esq] <= vetor[meio]) 
      aux[i++] = vetor[esq++];
    else aux[i++] = vetor[meio++]; 
  } 
  while (esq <= esq_fim) 
    aux[i++] = vetor[esq++];
  while (meio <= dir) 
    aux[i++] = vetor[meio++];
  for (i = 0; i < n; i++) { 
    vetor[dir] = aux[dir]; dir--; 
  }
}