#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirTabela(double resultados[][4], char unidades[][2], int NUM_SEMENTES) {
  printf("\033[1;35m      Número de Pontos\033[0m  \033[1;33m  Distância    "
         "\033[0m\033[1;31mBrutal Force\033[0m    \033[1;32mDivide And "
         "Conquer\033[0m\n");
  for (int i = 0; i < NUM_SEMENTES; i++) {
    printf("         %-9.0f           %-5.2f       %-7.6f%c          %-7.6f%c\n",
           resultados[i][0], resultados[i][1], resultados[i][2], unidades[i][0],
           resultados[i][3], unidades[i][1]);
  }
}

int main() {
  srand(time(NULL));
  int sementes[] = {10000, 100000, 1000000, 10000000};
  int NUM_SEMENTES = sizeof(sementes) / sizeof(int);
  double resultados[NUM_SEMENTES]
                   [4]; // Cada linha: [semente, dist, bf_time, dc_time]
  char unidades[NUM_SEMENTES][2];

  for (int i = 0; i < NUM_SEMENTES; i++) {
    int semente = sementes[i], medida_bf = 0, medida_dc = 0;

    Ponto *pontos = gerarPontos(semente);
    Ponto *pontos_y = copiar_pontos(pontos, semente);

    clock_t start_bf = clock();
    double bf_dist = forca_bruta(pontos, semente);
    clock_t end_bf = clock();
    
    double bf_time = ((double)(end_bf - start_bf)) / CLOCKS_PER_SEC;

    while (bf_time > 60 && medida_bf < 2) {
      bf_time /= 60;
      medida_bf++;
    }
    unidades[i][0] = gerar_unidade(medida_bf);
    
    clock_t start_dc = clock();
    double dist = divide_and_conquer(pontos, pontos_y, semente);
    clock_t end_dc = clock();
    
    double dc_time = ((double)(end_dc - start_dc)) / CLOCKS_PER_SEC;

    while (dc_time > 60 && medida_dc < 2) {
      dc_time /= 60;
      medida_dc++;
    }
    unidades[i][1] = gerar_unidade(medida_dc);

    resultados[i][0] = semente;
    resultados[i][1] = bf_dist;
    resultados[i][2] = bf_time;
    resultados[i][3] = dc_time;
    

    free(pontos);
    free(pontos_y);
  }

  imprimirTabela(resultados, unidades, NUM_SEMENTES);

  return 0;
}
