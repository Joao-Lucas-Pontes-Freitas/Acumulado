#include <stdio.h>
#include <stdlib.h>

int main() {
    int **matriz;
    int d1, d2, i, j, k;
    printf("Informe as dimensões (x,y) da matriz: ");
    scanf("%d %d",&d1, &d2);
    matriz = (int**)calloc(d1,sizeof(int*));
    for (i=0;i<d1;i++)
        matriz[i] = (int*)calloc(d2,sizeof(int));

    for (i=0;i<d1;i++)
        for (j=0;j<d2;j++) {
            printf("Elemento %d,%d:",i,j);
            scanf("%d",&matriz[i][j]);
        }

    int *vetor = NULL, size = 0, achou;
    for (i=0;i<d1;i++)
        for (j=0;j<d2;j++) {
            achou = 0;
            if (size > 0) {
            for (k=0;k<size;k++)
               if (matriz[i][j] == vetor[k])
                  achou = 1;
            }
            if (achou == 0) {
                vetor = (int*)realloc(vetor,(size+1)*sizeof(int));
                vetor[size] = matriz[i][j];
                size++;
            }
    }
    printf("\nMATRIZ:\n");
    for (i=0;i<d1;i++) {
        for (j=0;j<d2;j++)
            printf(" %d ",matriz[i][j]);
        printf("\n");
    }
    printf("\nVETOR: [");
    for (i=0;i<size;i++) {
        printf(" %d ",vetor[i]);
    }
    printf("]\n");
    free(vetor);
    for (i=0;i<d1;i++)
        free(matriz[i]);
    free(matriz);
    return 0;
}
