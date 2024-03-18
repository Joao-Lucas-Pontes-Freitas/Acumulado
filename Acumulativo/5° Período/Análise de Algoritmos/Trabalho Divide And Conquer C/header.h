#include <math.h>

typedef struct ponto Ponto;

double distancia(Ponto a, Ponto b);
double forca_bruta(Ponto *pontos, int n);
double divide_and_conquer(Ponto *matriz_x, Ponto *matriz_y, int n);

Ponto *gerarPontos(int n);
Ponto *copiar_pontos(Ponto *original, int n);
char gerar_unidade(int n);