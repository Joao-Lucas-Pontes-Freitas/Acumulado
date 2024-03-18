#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Alunos {
   int idade;
   char nome[50];
};
typedef struct Alunos Aluno;

int main( ) {

    Aluno *aluno;
    int t, i, m = 0;
    char maior[50];


    scanf("%d",&t);

    aluno = (Aluno *)malloc(t*sizeof(Aluno));

    for (i = 0; i < t; i++)
        scanf( "%d %[^\n]", &aluno[i].idade,  &aluno[i].nome);

    for(i = 0; i < t; i++){
        if(aluno[i].idade > m){
            strcpy(maior, aluno[i].nome);
            m = aluno[i].idade;
        }
    }

    printf("%s", maior);

    free(aluno);

    return 0;
}
