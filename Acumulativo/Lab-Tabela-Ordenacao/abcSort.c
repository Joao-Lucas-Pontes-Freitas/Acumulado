#include "ordenacao.h"
//TROCA
void troca(int *a, int *b) {
  int k = *a;
  *a = *b;
  *b = k;
}
//ABSORT
void abcSort(int v[], int i, int f) {
  int t;

  if (v[f] < v[i])
    troca(&v[i], &v[f]);
  if (f - i > 1) {
    t = (f - i + 1) / 3;
    abcSort(v, i, f - t);
    abcSort(v, i + t, f);
    abcSort(v, i, f - t);
  }
}