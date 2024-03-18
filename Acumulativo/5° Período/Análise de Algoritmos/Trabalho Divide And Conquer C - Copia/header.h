#include <math.h>

typedef struct ponto Ponto;

double distancia(Ponto a, Ponto b);
double forca_bruta(Ponto *pontos, long long n);
double divide_and_conquer(Ponto *matriz_x, Ponto *matriz_y, long long n);

Ponto *gerarPontos(long long n);
Ponto *copiar_pontos(Ponto *original, long long n);
char gerar_unidade(int n);
void coordenada(Ponto *p, long long n);