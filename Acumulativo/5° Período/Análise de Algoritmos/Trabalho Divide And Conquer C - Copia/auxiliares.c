#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct ponto {
  long long x;
  long long y;
} Ponto;

double distancia(Ponto a, Ponto b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

Ponto *gerarPontos(long long n) {
  srand(time(NULL));

  Ponto *pontos = NULL;
  if ((pontos = (Ponto *)malloc(n * sizeof(Ponto))) == NULL)
    return NULL;

  long long limite_inf = -1 * n * 2, limite_sup = n * 2;
  long long *used_x = (long long *)calloc(
      (limite_sup - limite_inf + 1),
      sizeof(long long)); // Array para rastrear os valores x usados

  if (used_x == NULL) {
    free(pontos);
    return NULL;
  }

  for (long long i = 0; i < n; i++) {
    long long x;
    do {
      x = rand() % (limite_sup - limite_inf + 1) + limite_inf;
    } while (used_x[x - limite_inf]); // Verifica se o valor x já foi usado
    used_x[x - limite_inf] = 1;       // Marca o valor x como usado

    pontos[i].x = x;
    pontos[i].y = rand() % (limite_sup - limite_inf + 1) + limite_inf;
  }

  free(used_x);
  return pontos;
}

Ponto *copiar_pontos(Ponto *pontos, long long n) {
  Ponto *pontos_y = NULL;
  if ((pontos_y = (Ponto *)malloc(n * sizeof(Ponto))) == NULL)
    return NULL;

  for (long long i = 0; i < n; i++) {
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

void coordenada(Ponto *p, long long n) {
  long long i = 0;
  long long k = 0;
  while (i < n) {
    printf("Coordenada %lld: (%lld, %lld)\n", i + 1, p[i].x, p[i].y);
    i++;
    for (long long j = 0; j < i; j++) {
      if (p[i].x == p[j].x) {
        k++;
        continue;
      }
    }
  }
  printf("Quantidade de coordenadas x repetidas: %d\n", k);
}