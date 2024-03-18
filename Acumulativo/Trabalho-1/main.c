#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define tam 1000
#define fatias 5

int main() {
  Produto produto[tam * 5];
  int i, j, k;
  time_t inicio, fim;
  double tempo[5];
  srand(time(NULL));

    printf("|----------------------------- Tabela do Código "
    "----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("| \033[92m      \033[0m        | \033[92m10000    \033[0m | "
    "\033[92m20000\033[0m     | \033[92m30000\033[0m     | "
    "\033[92m40000\033[0m     | \033[92m50000    \033[0m |\n");
    printf("|---------------------------------------------------------------------------|\n");

    for(j = 0; j < fatias; j++) {
      tempo[j] = 0;
      for(i = 0; i < 10; i++) {
        vetorInteiro(produto, tam*(j+1), i + 1);
        inicio = clock();
        bucketSortInteiro(produto, tam*(j+1));
        fim = clock();
        tempo[j] += (double)(fim - inicio)/CLOCKS_PER_SEC;
      }
    }
    printf("| BucketSort\t| ");
    for (i = 0; i < fatias; i++)
      printf("%fs | ", tempo[i]/10);
    printf("\n");

    for(j = 0; j < fatias; j++) {
      tempo[j] = 0;
      for(i = 0; i < 10; i++) {
        vetorInteiro(produto, tam*(j+1), i + 1);
        inicio = clock();
        cocktailSortInteiro(produto, tam*(j+1));
        fim = clock();
        tempo[j] += (double)(fim - inicio)/CLOCKS_PER_SEC;
      }
    }
    printf("| CocktailSort\t| ");
    for (i = 0; i < fatias; i++)
      printf("%fs | ", tempo[i]/10);
    printf("\n");

    for(j = 0; j < fatias; j++) {
      tempo[j] = 0;
      for(i = 0; i < 10; i++) {
        vetorInteiro(produto, tam*(j+1), i + 1);
        inicio = clock();
        heapSortInteiro(produto, tam*(j+1));
        fim = clock();
        tempo[j] += (double)(fim - inicio)/CLOCKS_PER_SEC;
      }
    }
    printf("| HeapSort \t    | ");
    for (i = 0; i < fatias; i++)
      printf("%fs | ", tempo[i]/10);
    printf("\n");

    for(j = 0; j < fatias; j++) {
      tempo[j] = 0;
      for(i = 0; i < 10; i++) {
        vetorInteiro(produto, tam*(j+1), i + 1);
        inicio = clock();
        insertionSortInteiro(produto, tam*(j+1));
        fim = clock();
        tempo[j] += (double)(fim - inicio)/CLOCKS_PER_SEC;
      }
    }
    printf("| InsertionSort\t| ");
    for (i = 0; i < fatias; i++)
      printf("%fs | ", tempo[i]/10);
    printf("\n");

    for(j = 0; j < fatias; j++) {
      tempo[j] = 0;
      for(i = 0; i < 10; i++) {
        vetorInteiro(produto, tam*(j+1), i + 1);
        inicio = clock();
        pancakeSortInteiro(produto, tam*(j+1));
        fim = clock();
        tempo[j] += (double)(fim - inicio)/CLOCKS_PER_SEC;
      }
    }
    printf("| PancakeSort \t| ");
    for (i = 0; i < fatias; i++)
      printf("%fs | ", tempo[i]/10);
    printf("\n");

    for(j = 0; j < fatias; j++) {
      tempo[j] = 0;
      for(i = 0; i < 10; i++) {
        vetorInteiro(produto, tam*(j+1), i + 1);
        inicio = clock();
        quickSortBasicoInteiro(produto, tam*(j+1));
        fim = clock();
        tempo[j] += (double)(fim - inicio)/CLOCKS_PER_SEC;
      }
    }
    printf("| QuickSort-B \t| ");
    for (i = 0; i < fatias; i++)
      printf("%fs | ", tempo[i]/10);
    printf("\n");

    for(j = 0; j < fatias; j++) {
      tempo[j] = 0;
      for(i = 0; i < 10; i++) {
        vetorInteiro(produto, tam*(j+1), i + 1);
        inicio = clock();
        quickSortMedianaAleatorioInteiro(produto, 0, tam*(j+1)-1);
        fim = clock();
        tempo[j] += (double)(fim - inicio)/CLOCKS_PER_SEC;
      }
    }
    printf("| QuickSort-M \t| ");
    for (i = 0; i < fatias; i++)
      printf("%fs | ", tempo[i]/10);
    printf("\n");
  printf("|---------------------------------------------------------------------------|\n\n");

    printf("|----------------------------- Tabela de Preços "
    "----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("| \033[92m      \033[0m        | \033[92m10000    \033[0m | "
    "\033[92m20000\033[0m     | \033[92m30000\033[0m     | "
    "\033[92m40000\033[0m     | \033[92m50000    \033[0m |\n");
    printf("|---------------------------------------------------------------------------|\n");

    for(j = 0; j < fatias; j++) {
      tempo[j] = 0;
      for(i = 0; i < 10; i++) {
        vetorReal(produto, tam*(j+1), i + 1);
        inicio = clock();
        cocktailSortReal(produto, tam*(j+1));
        fim = clock();
        tempo[j] += (double)(fim - inicio)/CLOCKS_PER_SEC;
      }
    }
    printf("| CocktailSort\t| ");
    for (i = 0; i < fatias; i++)
      printf("%fs | ", tempo[i]/10);
    printf("\n");

    for(j = 0; j < fatias; j++) {
      tempo[j] = 0;
      for(i = 0; i < 10; i++) {
        vetorReal(produto, tam*(j+1), i + 1);
        inicio = clock();
        heapSortReal(produto, tam*(j+1));
        fim = clock();
        tempo[j] += (double)(fim - inicio)/CLOCKS_PER_SEC;
      }
    }
    printf("| HeapSort \t    | ");
    for (i = 0; i < fatias; i++)
      printf("%fs | ", tempo[i]/10);
    printf("\n");

    for(j = 0; j < fatias; j++) {
      tempo[j] = 0;
      for(i = 0; i < 10; i++) {
        vetorReal(produto, tam*(j+1), i + 1);
        inicio = clock();
        insertionSortReal(produto, tam*(j+1));
        fim = clock();
        tempo[j] += (double)(fim - inicio)/CLOCKS_PER_SEC;
      }
    }
    printf("| InsertionSort\t| ");
    for (i = 0; i < fatias; i++)
      printf("%fs | ", tempo[i]/10);
    printf("\n");

    for(j = 0; j < fatias; j++) {
      tempo[j] = 0;
      for(i = 0; i < 10; i++) {
        vetorReal(produto, tam*(j+1), i + 1);
        inicio = clock();
        pancakeSortReal(produto, tam*(j+1));
        fim = clock();
        tempo[j] += (double)(fim - inicio)/CLOCKS_PER_SEC;
      }
    }
    printf("| PancakeSort \t| ");
    for (i = 0; i < fatias; i++)
      printf("%fs | ", tempo[i]/10);
    printf("\n");

    for(j = 0; j < fatias; j++) {
      tempo[j] = 0;
      for(i = 0; i < 10; i++) {
        vetorReal(produto, tam*(j+1), i + 1);
        inicio = clock();
        quickSortBasicoReal(produto, tam*(j+1));
        fim = clock();
        tempo[j] += (double)(fim - inicio)/CLOCKS_PER_SEC;
      }
    }
    printf("| QuickSort-B \t| ");
    for (i = 0; i < fatias; i++)
      printf("%fs | ", tempo[i]/10);
    printf("\n");

    for(j = 0; j < fatias; j++) {
      tempo[j] = 0;
      for(i = 0; i < 10; i++) {
        vetorReal(produto, tam*(j+1), i + 1);
        inicio = clock();
        quickSortMedianaAleatorioReal(produto, 0, tam*(j+1)-1);
        fim = clock();
        tempo[j] += (double)(fim - inicio)/CLOCKS_PER_SEC;
      }
    }
    printf("| QuickSort-M \t| ");
    for (i = 0; i < fatias; i++)
      printf("%fs | ", tempo[i]/10);
    printf("\n");
    printf("|---------------------------------------------------------------------------|\n\n");

  printf("|--------------------------- Tabela de Caracteres "
         "--------------------------|\n");
  printf("|---------------------------------------------------------------------"
         "------|\n");
  printf("| \033[92m      \033[0m        | \033[92m10000    \033[0m | "
         "\033[92m20000\033[0m     | \033[92m30000\033[0m     | "
         "\033[92m40000\033[0m     | \033[92m50000    \033[0m |\n");
  printf("|---------------------------------------------------------------------"
         "------|\n");

   for(j = 0; j < fatias; j++) {
      tempo[j] = 0;
      for(i = 0; i < 10; i++) {
        vetorChar(produto, tam*(j+1), i + 1);
        inicio = clock();
        cocktailSortChar(produto, tam*(j+1));
        fim = clock();
        tempo[j] += (double)(fim - inicio)/CLOCKS_PER_SEC;
      }
    }
    printf("| CocktailSort\t| ");
    for (i = 0; i < fatias; i++)
      printf("%fs | ", tempo[i]/10);
    printf("\n");

    for(j = 0; j < fatias; j++) {
      tempo[j] = 0;
      for(i = 0; i < 10; i++) {
        vetorChar(produto, tam*(j+1), i + 1);
        inicio = clock();
        heapSortChar(produto, tam*(j+1));
        fim = clock();
        tempo[j] += (double)(fim - inicio)/CLOCKS_PER_SEC;
      }
    }
    printf("| HeapSort \t    | ");
    for (i = 0; i < fatias; i++)
      printf("%fs | ", tempo[i]/10);
    printf("\n");

    for(j = 0; j < fatias; j++) {
      tempo[j] = 0;
      for(i = 0; i < 10; i++) {
        vetorChar(produto, tam*(j+1), i + 1);
        inicio = clock();
        insertionSortChar(produto, tam*(j+1));
        fim = clock();
        tempo[j] += (double)(fim - inicio)/CLOCKS_PER_SEC;
      }
    }
    printf("| InsertionSort\t| ");
    for (i = 0; i < fatias; i++)
      printf("%fs | ", tempo[i]/10);
    printf("\n");

    for(j = 0; j < fatias; j++) {
      tempo[j] = 0;
      for(i = 0; i < 10; i++) {
        vetorChar(produto, tam*(j+1), i + 1);
        inicio = clock();
        pancakeSortChar(produto, tam*(j+1));
        fim = clock();
        tempo[j] += (double)(fim - inicio)/CLOCKS_PER_SEC;
      }
    }
    printf("| PancakeSort \t| ");
    for (i = 0; i < fatias; i++)
      printf("%fs | ", tempo[i]/10);
    printf("\n");

    for(j = 0; j < fatias; j++) {
      tempo[j] = 0;
      for(i = 0; i < 10; i++) {
        vetorChar(produto, tam*(j+1), i + 1);
        inicio = clock();
        quickSortBasicoChar(produto, tam*(j+1));
        fim = clock();
        tempo[j] += (double)(fim - inicio)/CLOCKS_PER_SEC;
      }
    }
    printf("| QuickSort-B \t| ");
    for (i = 0; i < fatias; i++)
      printf("%fs | ", tempo[i]/10);
    printf("\n");

    for(j = 0; j < fatias; j++) {
      tempo[j] = 0;
      for(i = 0; i < 10; i++) {
        vetorChar(produto, tam*(j+1), i + 1);
        inicio = clock();
        quickSortMedianaAleatorioChar(produto, 0, tam*(j+1)-1);
        fim = clock();
        tempo[j] += (double)(fim - inicio)/CLOCKS_PER_SEC;
      }
    }
    printf("| QuickSort-M \t| ");
    for (i = 0; i < fatias; i++)
      printf("%fs | ", tempo[i]/10);
    printf("\n");
  printf("|---------------------------------------------------------------------"
         "------|\n\n");

  return 0;
}