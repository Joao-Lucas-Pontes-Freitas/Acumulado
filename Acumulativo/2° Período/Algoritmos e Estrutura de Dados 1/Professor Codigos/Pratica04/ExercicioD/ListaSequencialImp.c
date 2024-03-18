#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int total;
    Aluno *valores;
}Lista;

Lista *criar(){
    Lista *l = (Lista *)malloc(sizeof(Lista));
    if (l != NULL) {
        l->total = 0;
        l->valores = NULL;
    }
    return l;
}

void limpar(Lista *l) {
    if (l != NULL) {
        l->total = 0;
    }
}
//-----------------------------------------------
int inserirInicio(Lista *l, Aluno it) {
    int i;
    if (l == NULL) return 2;
    if (listaCheia(l) == 0) return 1;
    Aluno *temp = (Aluno*)realloc(l->valores,(l->total+1)*sizeof(Aluno));
    if (temp == NULL) return 4;
    l->valores = temp;
    for (i=l->total;i>0;i--) {
        l->valores[i] = l->valores[i-1];
    }
    l->valores[0] = it;
    l->total++;
    return 0;
}

int inserirFim(Lista *l, Aluno it) {
    if (l == NULL) return 2;
    if (listaCheia(l) == 0) return 1;
    Aluno *temp = (Aluno*)realloc(l->valores,(l->total+1)*sizeof(Aluno));
    if (temp == NULL) return 4;
    l->valores = temp;
    l->valores[l->total] = it;
    l->total++;
    return 0;
}
//------------------------------------------------
int removerInicio(Lista *l) {
    int i;
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    for (i=0;i<l->total-1;i++)
        l->valores[i] = l->valores[i+1];
    l->total--;
    Aluno *temp = (Aluno*)realloc(l->valores,l->total*sizeof(Aluno));
    if (temp == NULL) return 4;
    l->valores = temp;
    return 0;
}

int removerFim(Lista *l) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    l->total--;
    Aluno *temp = (Aluno*)realloc(l->valores,l->total*sizeof(Aluno));
    if (temp == NULL) return 4;
    l->valores = temp;
    return 0;
}
//------------------------------------------------
int buscarItemChave(Lista *l, int chave, Aluno *retorno) {
    int i;
    if (l == NULL) return -2;
    if (listaVazia(l) == 0) return -3;
    for (i=0;i<l->total;i++)
        if (l->valores[i].mat == chave) {
            if (retorno != NULL)
                *retorno = l->valores[i];
            return i;
        }
    return -1;
}

int listaVazia(Lista *l) {
    if (l == NULL) return 2;
    if (l->total == 0)
        return 0;
    else
        return 1;
}
//------------------------------------------------
int listaCheia(Lista *l) {
    return 1;
}

void mostrar(Lista *l) {
    int i;
    if (l != NULL) {
        printf("[");
        for (i=0;i<l->total;i++) {
            printf(" {%d, ",l->valores[i].mat);
            printf("%s, ",l->valores[i].nome);
            printf("%.2f} ",l->valores[i].n1);
        }
        printf("]\n");
    }
}

int inserirPosicao(Lista *l, Aluno it, int pos) {
    int i;
    if (l == NULL) return 2;
    if (listaCheia(l) == 0) return 1;
    if (pos < 1) return 3;
    if (pos > l->total) pos = (l->total+1);
    Aluno *temp = (Aluno*)realloc(l->valores,(l->total+1)*sizeof(Aluno));
    if (temp == NULL) return 4;
    l->valores = temp;
    for (i=l->total;i>(pos-1);i--) {
        l->valores[i] = l->valores[i-1];
    }
    l->valores[pos-1] = it;
    l->total++;
    return 0;
}

int removerPosicao(Lista *l,int pos) {
    int i;
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    if (pos < 1) return 3;
    if (pos > (l->total-1)) pos = (l->total);
    for (i=(pos-1);i<l->total-1;i++)
        l->valores[i] = l->valores[i+1];
    Aluno *temp = (Aluno*)realloc(l->valores,l->total*sizeof(Aluno));
    if (temp == NULL) return 4;
    l->valores = temp;
    l->total--;
    return 0;
}

int removerItem(Lista *l, int it) {
    int i;
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    i = buscarItemChave(l,it,NULL);
    while (i >= 0) {
       removerPosicao(l,i+1);
       i = buscarItemChave(l,it,NULL);
    }
    return 0;
}
