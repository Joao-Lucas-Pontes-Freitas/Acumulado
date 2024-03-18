#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirTabela(double resultados[][4], char unidades[][2], int NUM_SEMENTES) {
  printf("      Numero de Pontos      Distancia    "
         "  Brutal Force      Divide And "
         "Conquer\n");
  for (int i = 0; i < NUM_SEMENTES; i++) {
    printf("            %-9.0f        %-9.4f      %-10.4fs           %-4.4fs\n",
           resultados[i][0], resultados[i][1], resultados[i][2],
           resultados[i][3]);
  }
}


int main() {
  srand(time(NULL));
  long long sementes[] = {100000};
  int NUM_SEMENTES = sizeof(sementes) / sizeof(long long);
  double resultados[NUM_SEMENTES]
                   [4]; // Cada linha: [semente, dist, bf_time, dc_time]
  char unidades[NUM_SEMENTES][2];

  Ponto *maior = gerarPontos(sementes[NUM_SEMENTES-1]);
  printf("Maior finalizado!! \n");

  for (int i = 0; i < NUM_SEMENTES; i++) {
    long long semente = sementes[i], medida_bf = 0, medida_dc = 0;

    Ponto *pontos = copiar_pontos(maior, semente);
    Ponto *pontos_y = copiar_pontos(pontos, semente);

    // clock_t start_bf = clock();
    // double bf_dist = forca_bruta(pontos, semente);
    // clock_t end_bf = clock();

    // double bf_time = ((double)(end_bf - start_bf)) / CLOCKS_PER_SEC;

    // while (bf_time > 60 && medida_bf < 2) {
    //   bf_time /= 60;
    //   medida_bf++;
    // }
    //unidades[i][0] = gerar_unidade(medida_bf);

    clock_t start_dc = clock();
    double dist = divide_and_conquer(pontos, pontos_y, semente);
    clock_t end_dc = clock();

    double dc_time = ((double)(end_dc - start_dc)) / CLOCKS_PER_SEC;

    // while (dc_time > 60 && medida_dc < 2) {
    //   dc_time /= 60;
    //   medida_dc++;
    // }
    // unidades[i][1] = gerar_unidade(medida_dc);

    resultados[i][0] = semente;
    resultados[i][1] = dist;
    resultados[i][2] = 0;
    resultados[i][3] = dc_time;

    printf("Resultado com semente %lld finalizado!\n", semente);

    free(pontos);
    free(pontos_y);
  }

  imprimirTabela(resultados, unidades, NUM_SEMENTES);

  return 0;
}



