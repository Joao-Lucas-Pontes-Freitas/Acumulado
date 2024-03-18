#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include <string.h>

typedef struct fila {
  int inicio, fim, quantidade;
  Paciente valores[MAX];
} Fila;

Fila *criar() 
{
  Fila *f = (Fila*) malloc(sizeof(Fila));
  f->inicio = 0;
  f->fim = 0;
  f->quantidade = 0;
  for(int i = 0; i < MAX; i++)
    f->valores[i].nome = (char *)malloc(100*sizeof(char));
  return f;
}

void limpar(Fila *f) 
{
  free(f);
  f = NULL;
}

int inserir(Fila *f, Paciente it)
{
  if (f == NULL) return 2;
  if (filaCheia(f) == 0) return 1;
  strcpy(f->valores[f->fim].nome,it.nome);
  f->fim = (f->fim+1) % MAX;
  f->quantidade++;
  return 0;
}

int remover(Fila *f)
{
  if (f == NULL) return 2;
  if (filaVazia(f) == 0) return 1;
  f->valores[f->fim].nome = NULL;
  f->quantidade--;
  f->inicio = (f->inicio+1) % MAX;
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
    printf("\n[");
    int i = f->inicio;
    int q = f->quantidade;
    while (q > 0) {
      printf(" { %s } ", f->valores[i].nome);
      i = (i+1) % MAX;
      q--;
    }
    printf("]\n");
  }
}

