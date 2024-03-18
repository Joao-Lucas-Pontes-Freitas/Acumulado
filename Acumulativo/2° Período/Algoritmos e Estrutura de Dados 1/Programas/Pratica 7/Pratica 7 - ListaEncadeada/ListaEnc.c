#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

typedef struct no {
  Aluno valor;
  struct no *prox;
} No;

typedef struct lista {
  No *inicio;
} Lista;

Lista *criar() 
{
  Lista *l = (Lista*)malloc(sizeof(Lista));
  l -> inicio = NULL;
  return l;
}

int tamanho(Lista *l)
{
  int t = 0;
  if (listaVazia(l) == 0) return 0;
  No *noLista = l->inicio;
  while (noLista != NULL)
  {
    noLista = noLista->prox;
    t++;
  }
  return t;
}

int listaVazia(Lista *l) 
{
  if (l == NULL) return 2;
  if (l->inicio == NULL) return 0;
  return 1;
}
int listaCheia(Lista *l)
{
  if (listaVazia(l) == 0) return 0;
  if (l == NULL) return 2;
  return 7;
}

int inserirInicio(Lista *l, Aluno it)
{
  if (l == NULL) return 2;
  No *no = (No*)malloc(sizeof(No));
  no->valor = it;
  no->prox = l->inicio;
  l->inicio = no;
  return 0;
}

int inserirFim(Lista *l, Aluno it) 
{
  if (l == NULL) return 2;
  if (listaVazia(l) == 0)
    return inserirInicio(l,it);
  No *noLista = l->inicio;
  while (noLista->prox != NULL)
    noLista = noLista->prox;
  No *no = (No*)malloc(sizeof(No));
  no->valor = it;
  no->prox = noLista->prox;
  noLista->prox = no;
  return 0;
}

int inserirPosicao(Lista *l, struct aluno it, int pos) 
{
  if (l == NULL) return 2;
  if (pos < 0) return 3;
  if ((listaVazia(l) == 0) || (pos ==0)) return inserirInicio(l,it);
  No *noLista = l->inicio;
  int p = 1;
  while ((noLista->prox != NULL) && (p!=pos)) {
    p++;
    noLista = noLista->prox;
  }
  No *no = (No*)malloc(sizeof(No));
  no->valor = it;
  no->prox = noLista->prox;
  noLista->prox = no;
  return 0;
}

int removerInicio(Lista *l) 
{
  if (l == NULL) return 2;
  if (listaVazia(l) == 0) return 1;
  No *noLista = l->inicio;
  l->inicio = noLista->prox;
  free(noLista);
  return 0;
}

int removerFim(Lista *l) 
{
  if (l == NULL) return 2;
  if (listaVazia(l) == 0) return 1;
  No *noAuxiliar = NULL;
  No *noLista = l->inicio;
  while (noLista->prox != NULL) {
    noAuxiliar = noLista;
    noLista = noLista->prox;
  }
  if (noAuxiliar == NULL) l->inicio=NULL;
  else noAuxiliar->prox = NULL;
  free(noLista);
  return 0;
}

int removerPosicao(Lista *l, int pos)
{
  int p = 1;
  No *noLista = l->inicio;
  No *noAuxiliar = NULL;
  if (l == NULL) return 2;
  if (pos < 0) return 3;
  if (listaVazia(l) == 0) return 1;
  if (pos == 0) return removerInicio(l);
  if(pos > (tamanho(l))-1) return removerFim(l);
  while(p != pos){
    noLista = noLista->prox;
    p++;
  }
  noAuxiliar = (noLista->prox)->prox;
  free(noLista->prox);
  noLista->prox = noAuxiliar; 
  return 0;
}

int removerItem(Lista *l, int it)
{
  /*if (l == NULL) return 2;
  if (listaVazia(l) == 0) return 1;
  No *noLista = l -> inicio;
  int p = 0;
  while(noLista != NULL){
    if((noLista -> valor).mat == it)
      removerPosicao(l, p);
    else
      p++;
    noLista = noLista -> prox;
  }
  return 0;*/
  int i = buscarItemChave(l, it, NULL);
  while (i != -1){
    removerPosicao(l, i);
    i = buscarItemChave(l, it, NULL);
  }
  return 0;
}

int buscarPosicao(Lista *l,int pos, Aluno *retorno) 
{
  int p = 0;
  No *noLista = l->inicio;
  if (l == NULL) return 2;
  if (pos < 0) return 3;
  if (listaVazia(l) == 0) return 1;
  if(pos > (tamanho(l))-1) return 3;
  while(p != pos){
    noLista = noLista->prox;
    p++;
  }
  if(retorno != NULL) *retorno = noLista->valor;

  return 0;
    
}

int buscarItemChave(Lista *l,int chave, Aluno *retorno) 
{
  /*if (l == NULL) return 2;
  No *noLista = l->inicio;
  while ((noLista != NULL)) {
    if ((noLista->valor).mat == chave) {
      *retorno = noLista->valor;
      return 0;
    }
    noLista = noLista->prox;
  }
  return 1;*/
  if (l == NULL) return -1;
  int p = 0;
  No *noLista = l->inicio;
  while ((noLista != NULL)) {
    if ((noLista->valor).mat == chave) {
      if(retorno != NULL) *retorno = noLista->valor;
      return p;
    }
    p++;
    noLista = noLista->prox;
  }
  return -1;
}

void limpar(Lista *l) 
{
  while (listaVazia(l) != 0)
    removerInicio(l);
}

void mostrar(Lista *l) 
{
  if (l != NULL) {
    printf("[");
    No *noLista = l->inicio;
    while (noLista != NULL) {
      printf(" {%d, ", noLista->valor.mat);
      printf("%s, ",noLista->valor.nome);
      printf("%.2f} ",noLista->valor.n1);
      noLista = noLista->prox;
    }
    printf("]\n");
  }
}

int ContemItem(Lista *l, int it)
{
  if (l == NULL) return -2;
  if (listaVazia(l) == 0) return -3;
  if(buscarItemChave(l, it, NULL) > -1)
    return 0;
  return 1;
}

Lista *Concatena(Lista *l1, Lista *l2)
{
  if (l1 == NULL || l2 == NULL) return NULL;
  if (listaVazia(l1) == 0 || listaVazia(l2) == 0) return NULL;
  Lista *c = criar();
  int i = 0;
  Aluno r;
  int t1 = tamanho(l1);
  int t2 = tamanho(l2);
  while (i != t1){
    buscarPosicao(l1, i, &r);
    inserirFim(c, r);
    i++;
  }
  i = 0;
  while (i != t2){
    buscarPosicao(l2, i, &r);
    inserirFim(c, r);
    i++;
  }
  return c;
}
int MaiorNota(Lista *l)
{
  if (l == NULL) return 2;
  if (listaVazia(l) == 0) return 1;
  No *noLista = l->inicio;
  Aluno maior;
  maior.n1 = -1;
  while (noLista != NULL)
  {
    if((noLista->valor).n1 > maior.n1)
      maior = noLista->valor;
    noLista = noLista->prox;
  }
  printf("\n");
  printf(" {%d, ", maior.mat);
  printf("%s, ", maior.nome);
  printf("%.2f} ", maior.n1);
  printf("\n");
  return 0;
}
int RemoverNos(Lista *l, int n)
{
  int i = n;
  if (l == NULL) return 2;
  if (listaVazia(l) == 0) return 1;
  if(n > tamanho(l)){
    limpar(l);
    mostrar(l);
  }
  while (i != 0){
    removerInicio(l);
    i--;
  }
  return 0;
}