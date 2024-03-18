#include "header.h"
#include <float.h>

typedef struct ponto {
  int x;
  int y;
} Ponto;

double forca_bruta(Ponto *pontos, int n) {
  double min_dist = DBL_MAX;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      double dist = distancia(pontos[i], pontos[j]);
      if (dist < min_dist) {
        min_dist = dist;
      }
    }
  }
  return min_dist;
}
