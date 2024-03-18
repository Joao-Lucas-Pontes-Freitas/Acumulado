#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trocaVetor(int v[], int t);

int main()
{
    int t, i;

    printf("Digite o tamanho do array: ");

    scanf("%d", &t);

    int *v;
    v = (int *)malloc(t*sizeof(int));

    printf("\nDigite os inteiros do array: ");

    for (i = 0; i < t; i++)
        scanf("%d", &v[i]);

    trocaVetor(v, t);
    printf("\n");

    for (i = 0; i < t; i++){
        printf("%d ", v[i]);
    }

    printf("\n");

    free(v);

    return 0;
}

void trocaVetor(int v[], int t)
{
    int i, x, y, j = t-1;

    for (i = 0, j = j; i < (t/2); i++, j--){
        x = v[i];
        y = v[j];
        v[i] = y;
        v[j] = x;
    }
}
