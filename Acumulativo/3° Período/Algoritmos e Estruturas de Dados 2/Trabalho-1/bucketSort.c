#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM 50000

typedef struct {
  float preco;   
  int qtd;    
  int valores[TAM]; 
} balde;

void bucketSortInteiro (Produto V[], int N){
  
  int i, j, maior, menor, nroBaldes, pos; 
  balde *bd;
  maior = menor = V[0].codigo;
  for (i = 1; i < N; i++) {
    if (V[i].codigo > maior) maior = V[i].codigo;
    if (V[i].codigo < menor) menor = V[i].codigo;
  }

  nroBaldes = (maior - menor) / TAM + 1;
  bd = (balde *) malloc (nroBaldes * sizeof (balde)) ;
  for (i = 0; i < nroBaldes; i++)
    bd[i].qtd = 0;

  for (i = 0; i < N; i++){
    pos = (V[i].codigo - menor) / TAM;
    bd[pos].valores[bd[pos].qtd] = V[i].codigo;
    bd[pos].qtd++;
  }
  
  pos = 0;
  for (i = 0; i < nroBaldes; i++){
    insertionSort(bd[i].valores, bd[i].qtd);
    for (j = 0; j < bd[i].qtd; j++) {
      V[pos].codigo = bd[i].valores[j];
      pos++;
    }
  }
  free (bd) ;
}

