#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

typedef struct no {
  Aluno valor;
  struct no *prox;
} No;

typedef struct lista {
  No *fim;
} Lista;

Lista *criar()
{
  Lista *l = (Lista*)malloc(sizeof(Lista));
  l -> fim = NULL;
  return l;
}

int tamanho(Lista *l)
{
  if (l == NULL) return -1;
  if (listaVazia(l) == 0) return 0;
  No *noLista = l->fim;
  int cont = 0;
  do {
      cont++;
      noLista = noLista->prox;
    } while (noLista != l->fim);
  return cont;
}

int listaVazia(Lista *l)
{
  if (l == NULL) return 2;
  if (l->fim == NULL) return 0;
  else return 1;
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
  No *no = (No *)malloc(sizeof(No));
  no->valor = it;
  if (listaVazia(l) == 0) {
    l->fim = no;
    no->prox = no;
  }
  else {
    no->prox = l->fim->prox;
    l->fim->prox = no;
  }
  return 0;
}

int inserirFim(Lista *l, Aluno it)
{
  if (l == NULL) return 2;
  No *no = (No *)malloc(sizeof(No));
  no->valor = it;
  if (listaVazia(l) == 0) {
    l->fim = no;
    no->prox = no;
  }
  else {
    no->prox = l->fim->prox;
    l->fim->prox = no;
    l->fim = no;
  }
  return 0;
}

int inserirPosicao(Lista *l, struct aluno it, int pos)
{
  if (l == NULL) return 2;
  if (pos < 0) return 3;
  if ((listaVazia(l) == 0) || (pos == 0)) return inserirInicio(l,it);
  if(pos > (tamanho(l))-1) return inserirFim(l, it);
  No *noLista = l->fim;
  int p = 0;
  while (p != pos) {
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
  if(l->fim->prox == l-> fim){
    free(l->fim);
    l->fim = NULL;
  }
  else{
    No *noLista = l->fim->prox;
    l->fim->prox = noLista->prox;
    free(noLista);
  }
  return 0;
}

int removerFim(Lista *l)
{
  if (l == NULL) return 2;
  if (listaVazia(l) == 0) return 1;
  if(l->fim->prox == l->fim){
    free(l->fim);
    l->fim = NULL;
  }
  No *noLista = l->fim;
  while (noLista->prox != l->fim)
    noLista = noLista->prox;
  No *temp = l->fim;
  noLista->prox = temp->prox;
  l->fim = noLista;
  free(temp);
  return 0;
}

int removerPosicao(Lista *l, int pos)
{
  if (l == NULL) return 2;
  if (pos < 0) return 3;
  if (listaVazia(l) == 0) return 1;
  if (pos == 0) return removerInicio(l);
  if(pos >= (tamanho(l))-1) return removerFim(l);
  int p = 0;
  No *no = l->fim;
  No *aux = l->fim;
  while(p != pos){
    no = no->prox;
    p++;
  }
  aux = no->prox;
  no->prox = no->prox->prox;
  free(aux);
  aux = NULL;
  return 0;
}

int removerItem(Lista *l, int it)
{
  /*if (l == NULL) return 2;
  if (listaVazia(l) == 0) return 1;
  No *noLista = l -> inicio;
  int p = 0;
  while(noLista != NULL &&(noLista->valor.mat != it))
    noLista = noLista -> prox;
  if((noLista -> valor).mat == it)
  {
    if(noLista-> ant == NULL) return removerInicio(l)
    if(noLista-> prox == NULL) return removerFim(l);
    noLista->ant->prox = noLista->prox;
    noLista->prox->ant = noLista->ant;
    return 0;
  }
  return 0;*/
  int r = RemoverAparicao(l, it);
  while (r >= 0){
    r = RemoverAparicao(l, it);
  }
  return 0;
}

int buscarPosicao(Lista *l,int pos, Aluno *retorno)
{
  if (l == NULL) return 2;
  if (pos < 0 || pos > (tamanho(l))-1) return 3;
  if (listaVazia(l) == 0) return 1;
  int p = -1;
  No *noLista = l->fim;
  while(p != pos){
    noLista = noLista->prox;
    p++;
  }
  // if(retorno != NULL)
  *retorno = noLista->valor;

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


  if (listaVazia(l) == 0) return -3;
  if (l == NULL) return -1;
  int p = 0;

  No *noLista = l->fim->prox;
  do {
    if ((noLista->valor).mat == chave) {
      if(retorno != NULL) *retorno = noLista->valor;
      return p;
    }
    p++;
    noLista = noLista->prox;
  } while (noLista != l->fim->prox);

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
    if (listaVazia(l) != 0) {
      No *noLista = l->fim->prox;
      do {
        printf(" {%d, ",noLista->valor.mat);
        printf("%s, ",noLista->valor.nome);
        printf("%.2f} ",noLista->valor.n1);
        noLista = noLista->prox;
        } while (noLista != l->fim->prox);
    }
    printf("]\n");
  }
}

int TiraMeio(Lista *l){
  if (listaVazia(l) == 0) return -3;
  if (l == NULL) return -1;
  int p = tamanho(l)/2;
  removerPosicao(l, p);
  mostrar(l);
  return 0;
}

int ContaElementos(Lista *l, Aluno it)
{
  if (listaVazia(l) == 0) return -3;
  if (l == NULL) return -1;
  Aluno retorno;
  int t = tamanho(l);
  int p = 0, c = 0;
  while(p != t){
    buscarPosicao(l, p, &retorno);
    if(it.mat == retorno.mat)
      c++;
    p++;
  }
  return c;
}

int MaisAparece(Lista *l)
{
  if (listaVazia(l) == 0) return -3;
  if (l == NULL) return -1;
  No *noLista = l->fim->prox;
  Aluno retorno;
  Aluno maior;
  int c1 = 0, c2 = 0;
  do {
    retorno = noLista->valor;
    c2 = ContaElementos(l, retorno);
    if(c2 > c1){
      c1 = c2;
      maior = retorno;
    }
    c2 = 0;
    noLista = noLista->prox;
  } while (noLista != l->fim->prox);
  printf("\nO aluno que mais aparece eh: [{%d, %s, %.2f}]\n", maior.mat, retorno.nome, retorno.n1);
  return 0;
}

int SepararListas(Lista *l1, Lista *l2, Lista *l3, float nota)
{
  if (listaVazia(l1) == 0) return -3;
  if (l1 == NULL) return -1;
  No *noLista = l1->fim->prox;
  Aluno retorno;
  do {
    retorno = noLista->valor;
    if(retorno.mat < nota){
      inserirFim(l2, retorno);
    }
    else if(retorno.mat > nota){
      inserirFim(l3, retorno);
    }
    noLista = noLista->prox;
  } while (noLista != l1->fim->prox);
  mostrar(l2);
  mostrar(l3);
  return 0;
}

int RemoverAparicao(Lista *l, int it)
{
  if (listaVazia(l) == 0) return -3;
  if (l == NULL) return -1;
  int i = buscarItemChave(l, it, NULL);
  if(i >= 0)
    removerPosicao(l, i);
  else
    return -2;
  return 0;
}

int Interseccao(Lista *l1, Lista *l2, Lista *l3)
{
  if (listaVazia(l1) == 0 || listaVazia(l2) == 0) return -3;
  if (l1 == NULL) return -1;
  limpar(l3);
  No *noLista = l1->fim->prox;
  Aluno retorno = noLista->valor;
  int it = retorno.mat;
  int c;
  do{
    if(buscarItemChave(l2, it, NULL) >= 0)
      inserirFim(l3, retorno);
    noLista = noLista->prox;
    retorno = noLista->valor;
    it = retorno.mat;
  } while (noLista != l1->fim->prox);
  noLista = l3->fim->prox;
  retorno = noLista->valor;
  it = retorno.mat;
  do{
    c = ContaElementos(l3, retorno);
    if(c > 1)
      while(c > 1){
        RemoverAparicao(l3, it);
        c--;
      }
    noLista = noLista->prox;
    retorno = noLista->valor;
    it = retorno.mat;
  } while (noLista != l3->fim->prox);
  mostrar(l3);
  return 0;
}

int Produto(Lista *l1, Lista *l2, Lista *l3)
{
  if (listaVazia(l1) == 0 || listaVazia(l2) == 0) return -3;
  if (l1 == NULL) return -1;
  limpar(l3);
  int t = tamanho(l1);
  int p = 0;
  Aluno retorno;
  Aluno retorno2;
  Aluno retorno3;
  while(p != t){
    buscarPosicao(l1, p, &retorno);
    buscarPosicao(l2, p, &retorno2);
    retorno3.mat = retorno.mat * retorno2.mat;
    retorno3.n1 = retorno.n1 * retorno2.n1;
    inserirFim(l3, retorno3);
    p++;
  }
  mostrar(l3);
  return 0;
}
