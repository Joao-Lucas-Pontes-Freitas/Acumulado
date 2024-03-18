#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void multiplicaVetor(float v[], int t, float x);

int main()
{
    int t, i;
    float x;

    printf("Digite o tamanho do array: ");

    scanf("%d", &t);

    float *v;
    v = (float *)malloc(t*sizeof(float));

    printf("\nDigite os inteiros do array: ");

    for (i = 0; i < t; i++)
        scanf("%f", &v[i]);

    printf("\nDigite o multiplicador: ");
    scanf("%f", &x);

    printf("\nAntes: ");

    for (i = 0; i < t; i++){
        printf("%.2f ", v[i]);
    }

    multiplicaVetor(v, t, x);

    printf("\nDepois: ");

    for (i = 0; i < t; i++){
        printf("%.2f ", v[i]);
    }

    printf("\n");

    free(v);

    return 0;
}

void multiplicaVetor(float v[], int t, float x)
{
    int i;

    for (i = 0; i < t; i++){
        v[i] = v[i]*x;
    }
}
