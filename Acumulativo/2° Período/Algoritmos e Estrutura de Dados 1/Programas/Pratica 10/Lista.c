#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

typedef struct no {
  int valor;
  struct no *prox;
} No;

Lista *criar() 
{
  Lista *l = (Lista*)malloc(sizeof(Lista));
  (*l) = NULL;
  return l;
}

int tamanho(Lista *l)
{
  int t = 0;
  if(l == NULL) return -1;
  if (listaVazia(l) == 0) return 0;
  No *noLista = (*l);
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
  if ((*l) == NULL) return 0;
  return 1;
}
int listaCheia(Lista *l)
{
  if (listaVazia(l) == 0) return 0;
  if (l == NULL) return 2;
  return 7;
}

int inserirInicio(Lista *l, int it)
{
  if (l == NULL) return 2;
  No *no = (No*)malloc(sizeof(No));
  no->valor = it;
  no->prox = (*l);
  (*l) = no;
  return 0;
}

int inserirFim(Lista *l, int it) 
{
  if (l == NULL) return 2;
  if (listaVazia(l) == 0)
    return inserirInicio(l,it);
  No *noLista = (*l);
  while (noLista->prox != NULL)
    noLista = noLista->prox;
  No *no = (No*)malloc(sizeof(No));
  no->valor = it;
  no->prox = noLista->prox;
  noLista->prox = no;/*no->ant=noLista*/
  return 0;
}

int inserirPosicao(Lista *l, int it, int pos) 
{
  if (l == NULL) return 2;
  if (pos < 0) return 3;
  if ((listaVazia(l) == 0) || (pos ==0)) return inserirInicio(l,it);
  No *noLista = (*l);
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
  No *noLista = (*l);
  (*l) = noLista->prox;
  free(noLista);
  return 0;
}

int removerFim(Lista *l) 
{
  if (l == NULL) return 2;
  if (listaVazia(l) == 0) return 1;
  No *noAuxiliar = NULL;
  No *noLista = (*l);
  while (noLista->prox != NULL) {
    noAuxiliar = noLista;
    noLista = noLista->prox;
  }
  if (noAuxiliar == NULL) (*l)=NULL;
  else noAuxiliar->prox = NULL;
  free(noLista);
  return 0;
}

int removerPosicao(Lista *l, int pos)
{
  int p = 1;
  No *noLista = (*l);
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

int buscarPosicao(Lista *l,int pos, int *retorno) 
{
  int p = 0;
  No *noLista = (*l);
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

int buscarItemChave(Lista *l,int chave, int *retorno) 
{
  /*if (l == NULL) return 2;
  No *noLista = (*l);
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
  No *noLista = (*l);
  while ((noLista != NULL)) {
    if (noLista->valor== chave) {
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
  free(l);
  l = NULL;
}

void mostrar(Lista *l) 
{
  if (l != NULL) {
    if (listaVazia(l) != 0) {
      No *no = (*l);
      printf(" {%d",no->valor);
      printf("} ");
      mostrar(&(no->prox));
    }
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
  int r;
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
  No *noLista = (*l);
  int maior = -1;
  while (noLista != NULL)
  {
    if(noLista->valor> maior)
      maior = noLista->valor;
    noLista = noLista->prox;
  }
  printf("\n");
  printf(" {%d", maior);
  printf("} ");
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

int Comparar(Lista *l1, Lista *l2)
{
  if (l1 == NULL || l2 == NULL) return 2;
  if (listaVazia(l1) == 0 && listaVazia(l2) == 0) return 0;
  if(tamanho(l1) != tamanho(l2)) return 1;
  /*No *noLista1 = (*l1);
  No *noLista2 = (*l2);
  while (noLista1 != NULL) {
    if(noLista1->valor != noLista2->valor)
      return 1;
    noLista1 = noLista1->prox;
    noLista2 = noLista2->prox;
  }*/
  No *no1 = (*l1);
  No *no2 = (*l2);
  if(no1->valor != no2->valor)
    return 1;
  return Comparar(&(no1->prox), &(no2->prox));
}

int Somar(Lista *l)
{
  if (l != NULL) {
    if (listaVazia(l) != 0) {
      No *no = (*l);
      return no->valor + Somar(&(no->prox));
    }
  }
  return 0;
}

int Reverso(Lista *l)
{
  if (l != NULL) {
    if (listaVazia(l) != 0) {
      No *no = (*l);
      Reverso(&(no->prox));
      printf(" {%d",no->valor);
      printf("} ");
    }
  }
  
  return 0;
}

int RemoverTodos(Lista *l, int it)
{
  if (l == NULL) return -1;
    if (listaVazia(l) != 0) {
      No *no = (*l);
      if(no->valor == it){
        removerInicio(l);
        return RemoverTodos(l, it);
      }
      else
        return RemoverTodos(&(no->prox), it);
    }
  
  return 0;
}