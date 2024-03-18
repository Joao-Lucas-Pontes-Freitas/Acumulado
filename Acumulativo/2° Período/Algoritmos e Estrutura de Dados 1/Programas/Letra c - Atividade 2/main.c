#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int **mat;
    int *vetor1, *vetor2;
    int L, C, c, i, j, tam, n = 0;

    scanf("%d %d", &L, &C);

    mat = (int**)malloc(L*sizeof(int*));
    vetor1 = (int*)malloc(L*C*sizeof(int));
    vetor2 = (int*)malloc(L*C*sizeof(int));

    tam = L*C;

    for(i = 0;i < L; i++)
        mat[i]=(int*)malloc(C*sizeof(int));

    for (i = 0; i < L; i++)
        for (j = 0; j < C; j++){
            scanf("%d", &*(mat[i]+j));
        }

    for(i = 0; i < L; i++){
        for(j = 0; j < C; j++, c++){
            vetor1[c] = *(mat[i]+j);
        }

    }

    for( i = 0; i < tam; i++)
    {
        for( j = 0; j < n; j++ )
        {
            if( *(vetor1+i) == *(vetor2+j) )
                break;
        }

        if( j == n )
        {
            *(vetor2+n) = *(vetor1+i);
            n++;
        }
    }

    vetor2 = (int*)realloc(vetor2,n*sizeof(int));

    for( i = 0; i < n; i++ )
        printf("%d ", *(vetor2+i) );
    printf("\nTamanho: %d\n", n);

    free(mat);
    free(vetor1);
    free(vetor2);

    return 0;
}
