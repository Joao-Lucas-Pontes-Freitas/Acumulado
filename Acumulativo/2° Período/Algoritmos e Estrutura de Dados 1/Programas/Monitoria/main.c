#include <stdio.h> // bilbioteca de entrada e saída de dados.
#include <stdlib.h>// funções responsáveis pela alocação de memória e para conversão de inteiros.

int main()
{
    int *vetor, soma = 0, i;

    vetor = (int *)calloc(1500, sizeof(int));

    for (i = 0; i < 1500; i++)
    {
        vetor[i] = 0;
    }

    for (i = 0; i < 1500; i++)
    {
        printf("Posicao [%d]: %d\n", i, vetor[i]);
    }

    free(vetor);

    return 0;
}
