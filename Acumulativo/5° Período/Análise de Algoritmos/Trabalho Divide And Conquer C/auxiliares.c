#include "header.h"
#include <stdlib.h>
#include <time.h>

typedef struct ponto {
  int x;
  int y;
} Ponto;

double distancia(Ponto a, Ponto b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

Ponto *gerarPontos(int n) {
  srand(time(NULL));
  
  Ponto *pontos = NULL;
  if ((pontos = (Ponto *) malloc(n * sizeof(Ponto))) == NULL) return NULL;
  
  int limite_inf = -1 * n * 2, limite_sup = n * 2;

  for (int i = 0; i < n; i++) {
    pontos[i].x = rand() % (limite_sup - limite_inf + 1) + limite_inf;
    pontos[i].y = rand() % (limite_sup - limite_inf + 1) + limite_inf;
  }

  return pontos;
}

Ponto *copiar_pontos(Ponto *pontos, int n) {
  Ponto *pontos_y = NULL;
  if ((pontos_y = (Ponto *) malloc(n * sizeof(Ponto))) == NULL) return NULL;

  for (int i = 0; i < n; i++) {
    pontos_y[i].x = pontos[i].x;
    pontos_y[i].y = pontos[i].y;
  }

  return pontos_y;
}

char gerar_unidade(int n) {
  char unidade;
  switch (n) {
    case 0:
      unidade = 's';
    case 1:
      unidade = 'm';
    case 2:
      unidade = 'h';
    default:
      unidade = 's';
  }

  return unidade;
}