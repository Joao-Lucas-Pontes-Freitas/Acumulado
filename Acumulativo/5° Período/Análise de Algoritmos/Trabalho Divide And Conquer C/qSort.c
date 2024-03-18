#include "qSort.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

typedef struct ponto {
  int x;
  int y;
} Ponto;

void trocar(Ponto *a, Ponto *b) {
  Ponto temp = *a;
  *a = *b;
  *b = temp;
}

int particao(Ponto *matriz, int esq, int dir, int ordenacao_x) {
  int q = ordenacao_x == ordX ? matriz[dir].x : matriz[dir].y;
  int i = esq;

  for (int j = esq; j < dir; j++)
    if ((ordenacao_x == ordX ? matriz[j].x <= q : matriz[j].y <= q)) {
      trocar(&matriz[i++], &matriz[j]);
    }
  trocar(&matriz[i], &matriz[dir]);
  return i;
}

int particao_aleat(Ponto *matriz, int esq, int dir, int ordenacao_x) {
  int aleat = rand();
  int i = esq + rand() % (dir - esq + 1);
  
  trocar(&matriz[i], &matriz[dir]);
  return particao(matriz, esq, dir, ordenacao_x);
}

void quicksort(Ponto *matriz, int esq, int dir, int ordenacao_x) {
  if (esq >= dir) return;

  int q = particao_aleat(matriz, esq, dir, ordenacao_x);

  quicksort(matriz, esq, q - 1, ordenacao_x);
  quicksort(matriz, q + 1, dir, ordenacao_x);
}
