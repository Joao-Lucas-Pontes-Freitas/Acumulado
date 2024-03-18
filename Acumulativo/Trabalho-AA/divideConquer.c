#include "header.h"
#include "qSort.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ponto {
  long long x;
  long long y;
} Ponto;

double verificarFaixa(Ponto *div_menores, long long tam, double dist) {
  double min_dist = dist;
  for (long long i = 0; i < tam; i++) {
    for (long long j = i + 1; j < tam && (div_menores[j].y - div_menores[i].y) < min_dist; j++) {
      double dist_ij = distancia(div_menores[i], div_menores[j]);
      if (dist_ij < min_dist)
        min_dist = dist_ij;
    }
  }
  free(div_menores);
  return min_dist;
}

double menorDist(Ponto *x_ordenado, Ponto *y_ordenado, long long tam) {
  if (tam <= 3)
    return forca_bruta(x_ordenado, tam);

  long long metade = tam / 2;
  Ponto midPoint = x_ordenado[metade];

  Ponto *Y_esq = NULL, *Y_dir = NULL;
  if ((Y_esq = (Ponto *) malloc(metade * sizeof(Ponto))) == NULL || (Y_dir = (Ponto *) malloc((tam - metade) * sizeof(Ponto))) == NULL) {
    fprintf(stderr, "Erro de alocação de memória.\n");
    exit(EXIT_FAILURE);
  }
  long long esq_i = 0, dir_i = 0;
  for (long long i = 0; i < tam; i++) {
    if (y_ordenado[i].x <= midPoint.x && esq_i < metade)
      Y_esq[esq_i++] = y_ordenado[i];
    else
      Y_dir[dir_i++] = y_ordenado[i];
  }

  double dist_esq = menorDist(x_ordenado, Y_esq, metade);
  double dist_dir = menorDist(x_ordenado + metade, Y_dir, tam - metade);
  double dist = fmin(dist_esq, dist_dir);

  Ponto *faixa = NULL;
  if ((faixa = (Ponto *) malloc(tam * sizeof(Ponto))) == NULL) {
    fprintf(stderr, "Erro de alocação de memória.\n");
    exit(EXIT_FAILURE);
  }

  long long j = 0;
  for (long long i = 0; i < tam; i++) {
    if (abs(y_ordenado[i].x - midPoint.x) < dist)
      faixa[j++] = y_ordenado[i];
  }

  free(Y_esq);
  free(Y_dir);
  return fmin(dist, verificarFaixa(faixa, j, dist));
}

double divide_and_conquer(Ponto *matriz_x, Ponto *matriz_y, long long tam) {
  quicksort(matriz_x, 0, tam - 1, ordX);
  quicksort(matriz_y, 0, tam - 1, ordY);
  return menorDist(matriz_x, matriz_y, tam);
}