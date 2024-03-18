#include <stdio.h>
#include <stdlib.h>

float *aloca(float x, int t);

int main()
{
    float x;
    int t, i;
    float *v;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &t);

    printf("\nDigite o numero que o vetor sera preenchido: ");
    scanf("%f", &x);

    printf("\n");

    v = aloca(x , t);

    for (i = 0; i < t; i++)
        printf("%.2f ", v[i]);

    free(v);

    return 0;
}

float *aloca(float x, int t)
{
    int i;
    float *v;
    v = (float *)malloc(t*sizeof(float));

    for (i = 0; i < t; i++)
        v[i] = x;

    return v;
}
