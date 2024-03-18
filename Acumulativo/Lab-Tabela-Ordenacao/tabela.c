#include "ordenacao.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tabela(int tam) {

  int v[tam], cpV[tam];
  int i, j;
  time_t inicio, fim;
  double tempo;
  srand(time(NULL));
  // CRIANDO VETORES ALEATORIOS
  for (i = 0; i < 1; i++)
    criarVetor(v, tam, i + 1);

  if (tam < 100000) {
    printf("|-------------------------------------------------|\n");
    printf("| \033[92mMétodo\033[0m         \t| \033[92mTempo\033[0m         | "
           "\033[92mTamanho\033[0m     |\n");
    printf("|-------------------------------------------------|\n");

    copiaVetor(cpV, v, tam);
    inicio = clock();
    bubbleSort(cpV, tam);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("| BubbleSort     \t| %fs     | %d       |\n", tempo, tam);

    copiaVetor(cpV, v, tam);
    inicio = clock();
    insertionSort(cpV, tam);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("| InsertionSort  \t| %fs     | %d       |\n", tempo, tam);

    copiaVetor(cpV, v, tam);
    inicio = clock();
    selectionSort(cpV, tam);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("| SelectionSort  \t| %fs     | %d       |\n", tempo, tam);

    copiaVetor(cpV, v, tam);
    inicio = clock();
    shellSort(cpV, tam);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("| ShellSort      \t| %fs     | %d       |\n", tempo, tam);

    copiaVetor(cpV, v, tam);
    inicio = clock();
    mergeSort(cpV, tam);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("| MergeSort      \t| %fs     | %d       |\n", tempo, tam);

    copiaVetor(cpV, v, tam);
    inicio = clock();
    abcSort(cpV, 0, tam - 1);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("| ABC-Sort      \t| %fs     | %d       |\n", tempo, tam);
    printf("|-------------------------------------------------|\n");
  } else {
    printf("|---------------------------------------------------|\n");
    printf("| \033[92mMétodo\033[0m         \t| \033[92mTempo\033[0m          "
           "| \033[92mTamanho\033[0m      |\n");
    printf("|---------------------------------------------------|\n");

    copiaVetor(cpV, v, tam);
    inicio = clock();
    bubbleSort(cpV, tam);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("| BubbleSort     \t| %fs     | %d       |\n", tempo, tam);

    copiaVetor(cpV, v, tam);
    inicio = clock();
    insertionSort(cpV, tam);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("| InsertionSort  \t| %fs      | %d       |\n", tempo, tam);

    copiaVetor(cpV, v, tam);
    inicio = clock();
    selectionSort(cpV, tam);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("| SelectionSort  \t| %fs      | %d       |\n", tempo, tam);

    copiaVetor(cpV, v, tam);
    inicio = clock();
    shellSort(cpV, tam);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("| ShellSort      \t| %fs      | %d       |\n", tempo, tam);

    copiaVetor(cpV, v, tam);
    inicio = clock();
    mergeSort(cpV, tam);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("| MergeSort      \t| %fs      | %d       |\n", tempo, tam);

    copiaVetor(cpV, v, tam);
    inicio = clock();
    abcSort(cpV, 0, tam - 1);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("| ABC-Sort      \t| %fs      | %d       |\n", tempo, tam);
    printf("|---------------------------------------------------|\n");
  }
}
