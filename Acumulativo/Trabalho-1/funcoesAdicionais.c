#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <string.h>

void criarVetor(int v[], int t, int qtd) {
  srand(time(NULL) * qtd);
  for (int i = 0; i < t; i++)
    v[i] = rand() % t + 1;
}

void vetorInteiro(Produto p[], int tam, int qtd) {
  srand(time(NULL) * qtd);
  for (int i = 0; i < tam; i++)
    p[i].codigo = rand() % tam + 1;
}

void vetorReal(Produto p[], int tam, int qtd) {
  srand(time(NULL) * qtd);
  for (int i = 0; i < tam; i++)
    p[i].preco = ((float)rand() / (float)(RAND_MAX)) * (tam - 1) + 1;
}

void vetorChar(Produto p[], int tam, int qtd) {
  srand(time(NULL) * qtd);
  int i, j, tamSR, posicao_char;
  char caracteres[] =
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  for (j = 0; j < tam; j++) {
    tamSR = (rand() % 25) + 5;

    for (i = 0; i < tamSR; i++) {
      posicao_char = rand() % 62;
      p[j].descricao[i] = caracteres[posicao_char];
    }
    p[j].descricao[i] = '\0';
  }

}
void mostraVetorInteiro(Produto v[], int t) {
  for (int i = 0; i < t; i++)
    printf("%d ", v[i].codigo);
  printf("\n");
}

void mostraVetorInt(int v[], int t) {
  for (int i = 0; i < t; i++)
    printf("%d ", v[i]);
  printf("\n");
}

void mostraVetorReal(Produto v[], int t) {
  for (int i = 0; i < t; i++)
    printf("%.2f ", v[i].preco);
  printf("\n");
}

void copiaVetor(Produto copia[], Produto vet[], int tam) {
  for (int i = 0; i < tam; i++)
    copia[i].codigo = vet[i].codigo;
}

int particao(int vet[], int esq, int dir) {
  int i, fim = esq;

  for (i = esq + 1; i <= dir; i++)
    if (vet[i] < vet[esq]) {
      fim++;
      troca(vet, fim, i);
    }
  troca(vet, esq, fim);
  return fim;
}

int particaoInteiro(Produto vet[], int esq, int dir) {
  int i, fim = esq;

  for (i = esq + 1; i <= dir; i++)
    if (vet[i].codigo < vet[esq].codigo) {
      fim++;
      trocaInteiro(vet, fim, i);
    }
  trocaInteiro(vet, esq, fim);
  return fim;
}

int particaoReal(Produto vet[], int esq, int dir) {
  int i, fim = esq;

  for (i = esq + 1; i <= dir; i++)
    if (vet[i].preco < vet[esq].preco) {
      fim++;
      trocaReal(vet, fim, i);
    }
  trocaReal(vet, esq, fim);
  return fim;
}

int particaoChar(Produto vet[], int esq, int dir) {
  int i, fim = esq;

  for (i = esq + 1; i <= dir; i++)
    if (strcmp(vet[i].descricao, vet[esq].descricao) < 0) {
      fim++;
      trocaChar(vet, fim, i);
    }
  trocaChar(vet, esq, fim);
  return fim;
}

void trocaInteiro(Produto vet[], int i, int j) {
  int k = vet[i].codigo;
  vet[i].codigo = vet[j].codigo;
  vet[j].codigo = k;
}

void trocaReal(Produto vet[], int i, int j) {
  float k = vet[i].preco;
  vet[i].preco = vet[j].preco;
  vet[j].preco = k;
}

void troca(int vet[], int i, int j) {
  int k = vet[i];
  vet[i] = vet[j];
  vet[j] = k;
}

void trocaChar(Produto vet[], int i, int j) {
  char k[MAX];
  strcpy(k, vet[i].descricao);
  strcpy(vet[i].descricao, vet[j].descricao);
  strcpy(vet[j].descricao, k);
}

void transformar(int vet[], Produto p[]){
  int i, j;
  for(i = 0; i < 10; i++)
    for(j = 0; p[i].descricao[j] != '\0'; j++)
      vet[i] = p[i].descricao[j];
  vet[i] = p[i].descricao[j];
}
