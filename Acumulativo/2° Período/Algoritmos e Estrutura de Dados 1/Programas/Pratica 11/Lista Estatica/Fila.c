#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

typedef struct fila {
  int inicio, fim, quantidade;
  int valores[MAX];
} Fila;

Fila *criar() 
{
  Fila *f = (Fila*) malloc(sizeof(Fila));
  f->inicio = 0;
  f->fim = 0;
  f->quantidade = 0;
  return f;
}

void limpar(Fila *f) 
{
  free(f);
  f = NULL;
}

int inserir(Fila *f, int it) 
{
  if (f == NULL) return 2;
  if (filaCheia(f) == 0) return 1;
  f->valores[f->fim] = it;
  f->fim = (f->fim+1) % MAX;
  f->quantidade++;
  return 0;
}

int remover(Fila *f, int *it) 
{
  if (f == NULL) return 2;
  if (filaVazia(f) == 0) return 1;
  if (it != NULL) 
    *it = f->valores[f->inicio];
  f->quantidade--;
  f->inicio = (f->inicio+1) % MAX;
  return 0;
}

int consultar(Fila *f, int *it) 
{
  if (f == NULL) return 2;
  if (filaVazia(f) == 0) return 1;
  *it = f->valores[f->inicio];
  return 0;
}

int tamanho(Fila *f) 
{
  if (f == NULL) return -1;
  return f->quantidade;
}

int filaVazia(Fila *f) 
{
  if (f == NULL) return 2;
  if (f->quantidade == 0) return 0;
  return 1;
}

int filaCheia(Fila *f) 
{
  if (f == NULL) return 2;
  if (f->quantidade == MAX) return 0;
  return 1;
}

void mostrar(Fila *f) 
{
  if (f != NULL) {
    printf("[");
    int i = f->inicio;
    int q = f->quantidade;
    while (q > 0) {
      printf(" { %d } ", f->valores[i]);
      i = (i+1) % MAX;
      q--;
    }
    printf("]\n");
  }
}

Fila *intercalar(Fila *f1, Fila *f2)
{
  if (f1 == NULL || f2 == NULL) return NULL;
  int i = 0, t1 = f1->quantidade, t2 = f2->quantidade;
  if (t1 + t2 > MAX) return NULL;
  Fila *f3;
  f3 = criar();
  if(t1 > t2){
    while(i < t2){
      inserir(f3, f1->valores[f1->inicio+i]);
      inserir(f3, f2->valores[f2->inicio+i]);
      i++;
    }
    while(i < t1){
      inserir(f3, f1->valores[f1->inicio+i]);
      i++;
    }
  }
  else{
    while(i < t1){
      inserir(f3, f1->valores[f1->inicio+i]);
      inserir(f3, f2->valores[f2->inicio+i]);
      i++;
    }
    while(i < t2){
      inserir(f3, f2->valores[f2->inicio+i]);
      i++;
    }
  }
  return f3;
}

int RetiraNegativo(Fila *f)
{
  if (f == NULL) return 2;
  Fila *aux = criar();
  int it;
  while(remover(f, &it) != 1)
    if(it > 0) 
      inserir(aux, it);
  while(remover(aux, &it) != 1)
    inserir(f, it);
  return 0;
}