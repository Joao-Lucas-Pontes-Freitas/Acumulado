#include "header.h"
#include "qSort.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ponto {
  int x;
  int y;
} Ponto;

int compareX(const void *a, const void *b) {
  Ponto *p1 = (Ponto *)a;
  Ponto *p2 = (Ponto *)b;
  return (p1->x - p2->x);
}

int compareY(const void *a, const void *b) {
  Ponto *p1 = (Ponto *)a;
  Ponto *p2 = (Ponto *)b;
  return (p1->y - p2->y);
}

double stripClosest(Ponto strip[], int size, double d) {
  double min_dist = d;
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min_dist; j++) {
      double dist_ij = distancia(strip[i], strip[j]);
      if (dist_ij < min_dist)
        min_dist = dist_ij;
    }
  }
  return min_dist;
}

double closestUtil(Ponto X[], Ponto Y[], int n) {
  if (n <= 3) {
    double min_dist = INFINITY;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        double dist_ij = distancia(X[i], X[j]);
        if (dist_ij < min_dist)
          min_dist = dist_ij;
      }
    }
    return min_dist;
  }

  int mid = n / 2;
  Ponto midPoint = X[mid];

  Ponto Yl[mid];
  Ponto Yr[n - mid];
  int li = 0, ri = 0;
  for (int i = 0; i < n; i++) {
    if (Y[i].x <= midPoint.x && li < mid)
      Yl[li++] = Y[i];
    else
      Yr[ri++] = Y[i];
  }

  double dl = closestUtil(X, Yl, mid);
  double dr = closestUtil(X + mid, Yr, n - mid);
  double d = fmin(dl, dr);

  Ponto strip[n];
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (abs(Y[i].x - midPoint.x) < d)
      strip[j++] = Y[i];
  }

  return fmin(d, stripClosest(strip, j, d));
}

double divide_and_conquer(Ponto *matriz_x, Ponto *matriz_y, int n) {
  quicksort(matriz_x, 0, n - 1, ordX);
  quicksort(matriz_y, 0, n - 1, ordY);
  return closestUtil(matriz_x, matriz_y, n);
}