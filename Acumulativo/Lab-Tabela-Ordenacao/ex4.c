#include "ordenacao.h"
#include <stdio.h>

void troca2(int *a, int *b) {
  int k = *a;
  *a = *b;
  *b = k;
}
// recebe o vetor e as variáveis apra acumular 
void abcSort2(int v[], int i, int f, int *comp, int *trocas) {
  int t;
  int c[2];
  // aumenta o numnero de comparações
  (*comp)++;
  if (v[f] < v[i]) {
    troca2(&v[i], &v[f]);
    (*trocas)++; // aumenta numeros de trocas
  }
  if (f - i > 1) {
    t = (f - i + 1) / 3;
    abcSort2(v, i, f - t, comp, trocas);
    abcSort2(v, i + t, f, comp, trocas);
    abcSort2(v, i, f - t, comp, trocas);
  }
}
