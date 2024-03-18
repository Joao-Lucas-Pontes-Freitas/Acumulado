#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char CPF[12];
    char estadoCivil;
    int qtFilhos;
    char **filhos;
}Pessoa;

int main() {
    int numInseridos = 0,i,j,n,p;
    printf("Informe quantidade maxima elementos: ");
    scanf("%d",&n);
    Pessoa *vetor = (Pessoa*)calloc(n,sizeof(Pessoa));
    int op;
    if (vetor != NULL) {
       do {
          printf("1) Inserir cliente\n");
          printf("2) Remover cliente\n");
          printf("3) Exibir clientes\n");
          printf("4) Sair\n");
          printf("OPCAO: ");
          scanf("%d",&op);
          fflush(stdin);
          switch (op) {
          case 1:
              printf("CPF: ");
              fgets(vetor[numInseridos].CPF,12,stdin);
              fflush(stdin);
              printf("Estado Civil: ");
              scanf("%c",&vetor[numInseridos].estadoCivil);
              printf("Quantidade de Filhos:");
              scanf("%d",&vetor[numInseridos].qtFilhos);
              fflush(stdin);
              vetor[numInseridos].filhos = (char**)calloc(vetor[numInseridos].qtFilhos,sizeof(char*));
              if (vetor[numInseridos].filhos != NULL) {
                for (j=0;j<vetor[numInseridos].qtFilhos;j++) {
                     vetor[numInseridos].filhos[j] = (char*)calloc(30,sizeof(char));
                     if (vetor[numInseridos].filhos[j] != NULL) {
                        printf("Filho %d: ",j);
                        fgets(vetor[numInseridos].filhos[j],30,stdin);
                        fflush(stdin);
                     }
                  }
              }
              numInseridos++;
              break;
          case 2:
              printf("Posicao a ser removida: ");
              scanf("%d",&p);
              for (j=0;j<vetor[p].qtFilhos;j++)
                 free(vetor[p].filhos[j]);
              free(vetor[p].filhos);
              for (i=p;i<(numInseridos-1);i++)
                  vetor[i] = vetor[i+1];
              numInseridos--;
              Pessoa *t = (Pessoa*)realloc(vetor,numInseridos*sizeof(Pessoa));
              if (t != NULL) vetor = t;
              printf("Elemento %d removido!\n",p);
              break;
          case 3:
              printf("\nCLIENTES CADASTRADOS:\n");
              for (i=0;i<numInseridos;i++) {
                  printf("CPF: ");
                  puts(vetor[i].CPF);
                  printf("Estado Civil: %c",vetor[i].estadoCivil);
                  printf("\nFilhos (%d):\n",vetor[i].qtFilhos);
                  for (j=0;j<vetor[i].qtFilhos;j++) {
                     printf("- ");
                     puts(vetor[i].filhos[j]);
                  }
                  printf("\n");
              }
              printf("\n====================\n");
              break;
          }

       }while (op != 4);
       for (i=0;i<numInseridos;i++) {
           for (j=0;j<vetor[i].qtFilhos;j++)
               free(vetor[i].filhos[j]);
           free(vetor[i].filhos);
       }
       free(vetor);
    }
    return 0;
}
