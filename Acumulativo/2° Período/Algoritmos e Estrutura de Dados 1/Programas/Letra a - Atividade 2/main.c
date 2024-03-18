#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{

    int n = 0, i, t, j, c;
    int tp;
    int *vetor;

    scanf("%d", &t);

    vetor = (int *)malloc(t*sizeof(int));

    for (i = 0, j = 0; i < t; i++, j++){

        scanf("%d", &*(vetor+j));
        if(*(vetor+j) == *(vetor+j-1)){
            *(vetor+j) = 0;
            j--;
            n++;
        }
    }

    printf("Tamanho do vetor: %d posicoes\n", t);

    c = t-n;


    vetor = (int *)realloc(vetor, (c)*sizeof(int));

    for (i = 0; i < (c); i++)
        printf("%d ", *(vetor+i));

    printf("\nTamanho do vetor: %d posicoes\n", c);

    printf("\nDigite mais numeros, caso queira adiciona-los ou encerre o programa com 0\n");


    for (j = c; tp != 0; i++, j++){
        scanf("%d", &*(vetor+j));
        tp = *(vetor+j);
        if(*(vetor+j)%2 != 0){
            fprintf(stderr, "Numero deve ser par\n");
            j--;
            n++;
        }
    }

    t = j;

    vetor = (int *)realloc(vetor, t*sizeof(int));

    for (i = 0; i < t; i++)
        printf("%d ", *(vetor+i));

    printf("\n");
        printf("Tamanho do vetor: %d posicoes\n", j);

   free(vetor);


    return 0;

}
