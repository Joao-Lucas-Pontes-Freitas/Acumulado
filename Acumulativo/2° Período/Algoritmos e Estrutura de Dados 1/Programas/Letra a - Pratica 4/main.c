#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vetor(int v[], int t, float *media, int *maior);

int main()
{
    int t, i;

    printf("Digite o tamanho do array: ");

    scanf("%d", &t);

    int *v;
    v = (int *)malloc(t*sizeof(int));

    float media = 0;

    printf("Digite os elementos do array: ");

    for (i = 0; i < t; i++)
        scanf("%d", &v[i]);

    int maior = v[0];

    vetor(v, t, &media, &maior);

    printf("Media: %.2f \t Maior: %d\n", media, maior);

    free(v);

    return 0;
}

void vetor(int v[], int t, float *media, int *maior)
{
    int i;


    for (i = 0; i < t; i++){
        if (v[i] > *maior){
            *maior = v[i];
        }
        *media = *media + v[i];
    }

    *media = *media/t;

}
