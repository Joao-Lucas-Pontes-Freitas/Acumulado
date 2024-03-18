#include "header.h"
#include <float.h>

typedef struct ponto {
  long long x;
  long long y;
} Ponto;

double forca_bruta(Ponto *pontos, long long n) {
  double min_dist = DBL_MAX;
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      double dist = distancia(pontos[i], pontos[j]);
      if (dist < min_dist) {
        min_dist = dist;
      }
    }
  }
  return min_dist;
}
