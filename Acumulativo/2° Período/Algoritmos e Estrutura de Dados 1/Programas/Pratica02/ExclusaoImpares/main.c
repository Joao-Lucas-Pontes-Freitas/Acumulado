#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,i,j,ct=0;
    printf("Informe quantidade elementos: ");
    scanf("%d",&n);
    int *vetor = (int*)calloc(n,sizeof(int));
    if (vetor != NULL) {
        for (i=0;i<n;i++) {
            printf("- Elemento %d: ",i);
            scanf("%d",&vetor[i]);
        }
        printf("\nANTES: [");
        for (i=0;i<n;i++) printf(" %d ",vetor[i]);
        printf("]\n");
        for (i=0;i<n;i++) {
            //while (((vetor[i] % 2) != 0)&&(i<n)) { //ALTERNATIVA 01
            if ((vetor[i] % 2) != 0) { //ALTERNATIVA 02
                ct++;
                for (j=i;j<(n-1);j++)
                    vetor[j] = vetor[j+1];
                n--;
                int *t = (int*)realloc(vetor,n*sizeof(int));
                if (t != NULL) vetor = t;
                i--; //ALTERNATIVA 02
            }
        }
        printf("\nElementos retirados: %d.\n",ct);
        printf("\nDEPOIS: [");
        for (i=0;i<n;i++) printf(" %d ",vetor[i]);
        printf("]\n");
    }
    return 0;
}
