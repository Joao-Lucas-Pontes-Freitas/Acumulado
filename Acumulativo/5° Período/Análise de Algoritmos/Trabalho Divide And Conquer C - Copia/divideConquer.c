#include "header.h"
#include "qSort.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ponto {
  long long x;
  long long y;
} Ponto;

double stripClosest(Ponto *strip, long long size, double d) {
  double min_dist = d;
  for (long long i = 0; i < size; i++) {
    for (long long j = i + 1; j < size && (strip[j].y - strip[i].y) < min_dist; j++) {
      double dist_ij = distancia(strip[i], strip[j]);
      if (dist_ij < min_dist)
        min_dist = dist_ij;
    }
  }
  free(strip);
  return min_dist;
}

double closestUtil(Ponto *X, Ponto *Y, long long n) {
  if (n <= 3) {
    double min_dist = INFINITY;
    for (long long i = 0; i < n; i++) {
      for (long long j = i + 1; j < n; j++) {
        double dist_ij = distancia(X[i], X[j]);
        if (dist_ij < min_dist)
          min_dist = dist_ij;
      }
    }
    return min_dist;
  }

  long long mid = n / 2;
  Ponto midPoint = X[mid];


  Ponto *Y_esq = NULL;
  Ponto *Y_dir = NULL;
  if ((Y_esq = (Ponto *) malloc(mid * sizeof(Ponto))) == NULL || (Y_dir = (Ponto *) malloc((n - mid) * sizeof(Ponto))) == NULL) {
    fprintf(stderr, "Erro de alocação de memória.\n");
    exit(EXIT_FAILURE);
  }
  long long li = 0, ri = 0;
  for (long long i = 0; i < n; i++) {
    if (Y[i].x <= midPoint.x && li < mid)
      Y_esq[li++] = Y[i];
    else
      Y_dir[ri++] = Y[i];
  }

  double dl = closestUtil(X, Y_esq, mid);
  double dr = closestUtil(X + mid, Y_dir, n - mid);
  double d = fmin(dl, dr);

  Ponto *strip = NULL;
  if ((strip = (Ponto *) malloc(n * sizeof(Ponto))) == NULL) {
    fprintf(stderr, "Erro de alocação de memória.\n");
    exit(EXIT_FAILURE);
  }

  long long j = 0;
  for (long long i = 0; i < n; i++) {
    if (abs(Y[i].x - midPoint.x) < d)
      strip[j++] = Y[i];
  }

  free(Y_esq);
  free(Y_dir);
  return fmin(d, stripClosest(strip, j, d));
}

double divide_and_conquer(Ponto *matriz_x, Ponto *matriz_y, long long n) {
  quicksort(matriz_x, 0, n - 1, ordX);
  quicksort(matriz_y, 0, n - 1, ordY);
  return closestUtil(matriz_x, matriz_y, n);
}