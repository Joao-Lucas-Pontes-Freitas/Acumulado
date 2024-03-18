#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirTabela(double resultados[][4], int NUM_SEMENTES) {
  printf("\033[1;35m      Número de Pontos\033[0m  \033[1;33m    Distância    "
         "\033[0m\033[1;31m  Brutal Force\033[0m    \033[1;32m  Divide And "
         "Conquer\033[0m\n");
  for (int i = 0; i < NUM_SEMENTES; i++) {
    printf("            %-9.0f        %-9.4f      %-10.4fs           %-4.4fs\n",
           resultados[i][0], resultados[i][1], resultados[i][2],
           resultados[i][3]);
  }
}


int main() {
  srand(time(NULL));
  
  int sementes[] = {100, 1000, 10000}, NUM_SEMENTES = sizeof(sementes) / sizeof(sementes[0]);
  double resultados[NUM_SEMENTES][4];

  Ponto *maior = gerarPontos(sementes[NUM_SEMENTES-1]);

  for (int i = 0; i < NUM_SEMENTES; i++) {
    int semente = sementes[i], medida_bf = 0, medida_dc = 0;

    Ponto *pontos = copiar_pontos(maior, semente);
    Ponto *pontos_y = copiar_pontos(pontos, semente);

    clock_t start_bf = clock();
    double bf_dist = forca_bruta(pontos, semente);
    clock_t end_bf = clock();

    double bf_time = ((double)(end_bf - start_bf)) / CLOCKS_PER_SEC;

    clock_t start_dc = clock();
    double dist = divide_and_conquer(pontos, pontos_y, semente);
    clock_t end_dc = clock();

    double dc_time = ((double)(end_dc - start_dc)) / CLOCKS_PER_SEC;

    resultados[i][0] = semente;
    resultados[i][1] = bf_dist;
    resultados[i][2] = bf_time;
    resultados[i][3] = dc_time;

    free(pontos);
    free(pontos_y);
  }

  imprimirTabela(resultados, NUM_SEMENTES);

  return 0;
}



