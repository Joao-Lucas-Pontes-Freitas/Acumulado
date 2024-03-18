#include "qSort.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

typedef struct ponto {
  long long x;
  long long y;
} Ponto;

void trocar(Ponto *a, Ponto *b) {
  Ponto temp = *a;
  *a = *b;
  *b = temp;
}

long long particao(Ponto *matriz, long long esq, long long dir, int ordenacao_x) {
  long long q = ordenacao_x == ordX ? matriz[dir].x : matriz[dir].y;
  long long i = esq;

  for (long long j = esq; j < dir; j++)
    if ((ordenacao_x == ordX ? matriz[j].x <= q : matriz[j].y <= q)) {
      trocar(&matriz[i++], &matriz[j]);
    }
  trocar(&matriz[i], &matriz[dir]);
  return i;
}

long long particao_aleat(Ponto *matriz, long long esq, long long dir, int ordenacao_x) {
  long long aleat = rand();
  long long i = esq + rand() % (dir - esq + 1);

  trocar(&matriz[i], &matriz[dir]);
  return particao(matriz, esq, dir, ordenacao_x);
}

void quicksort(Ponto *matriz, long long esq, long long dir, int ordenacao_x) {
  if (esq >= dir) return;

  long long q = particao_aleat(matriz, esq, dir, ordenacao_x);

  quicksort(matriz, esq, q - 1, ordenacao_x);
  quicksort(matriz, q + 1, dir, ordenacao_x);
}
