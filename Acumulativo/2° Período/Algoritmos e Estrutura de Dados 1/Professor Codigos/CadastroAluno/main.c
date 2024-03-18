#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *nome;
    int idade;
}Aluno;

int main() {
    Aluno *vetor;
    int n,i;
    printf("Informe o numero de alunos: ");
    scanf("%d",&n);
    fflush(stdin);
    vetor = (Aluno*)calloc(n,sizeof(Aluno));
    for (i=0;i<n;i++) {
        vetor[i].nome = (char*)calloc(30,sizeof(char));
        printf("Nome: ");
        fgets(vetor[i].nome,30,stdin);
        printf("Idade: ");
        scanf("%d",&vetor[i].idade);
        fflush(stdin);
    }
    for (i=0;i<n;i++) {
        printf("{");
        puts(vetor[i].nome);
        printf(": %d anos}",vetor[i].idade);
        printf("\n");
    }
    Aluno maisVelho = vetor[0];
    for (i=1;i<n;i++)
       if (vetor[i].idade > maisVelho.idade)
          maisVelho = vetor[i];

    printf("ALUNO MAIS VELHO:\n");
    puts(maisVelho.nome);
    printf("Idade: %d anos\n",maisVelho.idade);
    for (i=1;i<n;i++)
        free(vetor[i].nome);
    free(vetor);
    return 0;
}
