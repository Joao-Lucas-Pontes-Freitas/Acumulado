#include "ordenacao.h"

void shellSort(int vet[], int n){
  int i , j , valor; 
  int intervalo = 1; 
  do { intervalo = 3*intervalo+1; } while (intervalo < n);
  do { 
    intervalo /= 3; 
    for (i = intervalo; i < n; i++){ 
      valor = vet[i]; 
      j = i - intervalo; 
      while (j >= 0 && valor < vet[j]){
        vet[j+intervalo] = vet[j]; 
        j -= intervalo; 
      } 
      vet[j+intervalo] = valor;
    } 
  } while (intervalo > 1);
}