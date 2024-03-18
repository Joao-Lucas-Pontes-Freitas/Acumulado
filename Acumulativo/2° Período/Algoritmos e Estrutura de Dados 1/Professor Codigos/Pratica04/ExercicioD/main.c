#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "string.h"

int main() {
    printf("1) Criando lista: \n");
    Lista *minhaLista = criar(20);
    printf("2) Mostrando lista: \n");
    mostrar(minhaLista);
    Aluno a;
    a.mat = 20;
    strcpy(a.nome,"Carlos");
    a.n1 = 3.4;
    printf("3) Inserindo no inicio: \n");
    inserirInicio(minhaLista,a);
    mostrar(minhaLista);
    a.mat = 20;
    strcpy(a.nome,"Ana");
    a.n1 = 10.4;
    printf("4) Inserindo no inicio: \n");
    inserirInicio(minhaLista,a);
    mostrar(minhaLista);
    a.mat = 30;
    strcpy(a.nome,"Jonas");
    a.n1 = 6.2;
    printf("5) Inserindo no final: \n");
    inserirFim(minhaLista,a);
    mostrar(minhaLista);
    a.mat = 20;
    strcpy(a.nome,"Carolina");
    a.n1 = 10.0;
    int pos = 1;
    printf("5a) Inserindo na posicao %d: \n",pos);
    inserirPosicao(minhaLista,a,pos);
    mostrar(minhaLista);
    pos = 1;
    printf("6a) Removendo da posicao %d: \n",pos);
    removerPosicao(minhaLista,pos);
    mostrar(minhaLista);
    printf("6a) Removendo item 20: \n");
    removerItem(minhaLista,20);
    mostrar(minhaLista);

    int chave = 20;
    struct aluno r;
    printf("6) Buscando chave %d: \n",chave);
    int ret = buscarItemChave(minhaLista,chave,&r);
    if (ret == 0) {
        printf("Item encontrado:\n");
        printf(" - {%d, ",r.mat);
        printf("%s, ",r.nome);
        printf("%.2f}\n",r.n1);
    }else
        printf("Nao encontrou chave %d.\n",chave);
    printf("7) Removendo do inicio: \n");
    removerInicio(minhaLista);
    mostrar(minhaLista);
    printf("7) Removendo do final: \n");
    removerFim(minhaLista);
    mostrar(minhaLista);

    return 0;
}
