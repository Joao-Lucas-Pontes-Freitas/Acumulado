#include<stdio.h>
#include<stdlib.h>
#include"Lista.h"

int main(void)
{
  Lista *lista;
  Lista *lista2;
  int retorno;
  int it;
  int k, r, mat, p, m = 0;

  while(m != 20)
  {
    printf("\nMenu:\n01) Criar Lista\n02) Limpar Lista\n03) Inserir Inicio\n04) Inserir Fim\n05) Inserir Posicao\n06) Remover Inicio\n07) Remover Fim\n08) Remover Posicao\n09) Remover Item\n10) Buscar Item\n11) Buscar Posicao\n12) Tamanho\n13) Status Lista\n14) Mostrar Lista\n15) Comparar Listas\n16) Somar elementos\n17) Reverso\n18) Remover Todos Elementos\n19) Encerrar\n\nDigite uma opcao: ");
    scanf("%d", &m);

    switch(m)
    {
      case 1:
        lista = criar();
        lista2 = criar();
        break;

      case 2:
        printf("\nEscolha a lista (1/2): ");
        scanf("%d", &k);
        if(k == 1)
          limpar(lista);
        else
          limpar(lista2);
        break;

      case 3:
        printf("\nEscolha a lista (1/2): ");
        scanf("%d", &k);
        printf("\nDigite o numero inteiro que deseja inserir: ");
        scanf("%d", &it);
        if(k == 1)
          r = inserirInicio(lista, it);
        else
          r = inserirInicio(lista2, it);
        if(r == 2)
          printf("\nLista nao foi criada\n");
        if(r == 1)
          printf("\nLista cheia\n");
        r = 0;
        break;

      case 4:
        printf("\nEscolha a lista (1/2): ");
        scanf("%d", &k);
        printf("\nDigite o numero inteiro que deseja inserir: ");
        scanf("%d", &it);
        if(k == 1)
          r = inserirFim(lista, it);
        else
          r = inserirFim(lista2, it);
        if(r == 2)
          printf("\nLista nao foi criada\n");
        if(r == 1)
          printf("\nLista cheia\n");
        r = 0;
        break;

      case 5:
        printf("\nEscolha a lista (1/2): ");
        scanf("%d", &k);
        printf("\n(Comecando no 0) Digite a posicao: ");
        scanf("%d", &p);
        printf("\nDigite o numero inteiro que deseja inserir: ");
        scanf("%d", &it);
        if(k == 1)
          r = inserirPosicao(lista, it, p);
        else
          r = inserirPosicao(lista2, it, p);
        if(r == 2)
          printf("\nLista nao foi criada\n");
        if(r == 1)
          printf("\nLista cheia\n");
        if(r == 3)
          printf("\nPosicao invalida\n");
        r = 0;
        break;

      case 6:
        printf("\nEscolha a lista (1/2): ");
        scanf("%d", &k);
        if(k == 1)
          r = removerInicio(lista);
        else
          r = removerInicio(lista2);
        if(r == 2)
          printf("\nLista nao foi criada\n");
        if(r == 1)
          printf("\nLista vaziazn\n");
        r = 0;
        break;

      case 7:
        printf("\nEscolha a lista (1/2): ");
        scanf("%d", &k);
        if(k == 1)
          r = removerFim(lista);
        else
          r = removerFim(lista2);
        if(r == 2)
          printf("\nLista nao foi criada\n");
        if(r == 1)
          printf("\nLista vaziaz\n");
        r = 0;
        break;

      case 8:
        printf("\nEscolha a lista (1/2): ");
        scanf("%d", &k);
        printf("\n(Comecando no 0) Digite a posicao: ");
        scanf("%d", &p);
        if(k == 1)
          r = removerPosicao(lista, p);
        else
          r = removerPosicao(lista2, p);
        if(r == 2)
          printf("\nLista nao foi criada\n");
        if(r == 1)
          printf("\nLista vazia\n");
        if(r == 3)
          printf("\nPosicao invalida\n");
        r = 0;
        break;

      case 9:
        printf("\nEscolha a lista (1/2): ");
        scanf("%d", &k);
        printf("\nDigite a matricula: ");
        scanf("%d", &mat);
        if(k == 1)
          r = removerItem(lista, mat);
        else
          r = removerItem(lista2, mat);
        if(r == 2)
          printf("\nLista nao foi criada\n");
        else if(r == 1)
          printf("\nLista vazia\n");
        r = 0;
        break;

      case 10:
        printf("\nEscolha a lista (1/2): ");
        scanf("%d", &k);
        printf("\nDigite a matricula: ");
        scanf("%d", &mat);
        if(k == 1)
          r = buscarItemChave(lista, mat, &retorno);
        else
          r = buscarItemChave(lista2, mat, &retorno);
        if(r == 2)
          printf("\nLista nao foi criada\n");
        else if(r == 1)
          printf("\nLista vazia\n");
        printf("\n[{%d}]\n", retorno);
        r = 0;
        break;

      case 11:
        printf("\nEscolha a lista (1/2): ");
        scanf("%d", &k);
        printf("\n(Comecando no 0) Digite a posicao: ");
        scanf("%d", &p);
        if(k == 1)
          r = buscarPosicao(lista, p, &retorno);
        else
          r = buscarPosicao(lista2, p, &retorno);
        if(r == 2)
          printf("\nLista nao foi criada\n");
        if(r == 1)
          printf("\nLista vazia\n");
        if(r == 3)
          printf("\nPosicao invalida\n");
        printf("\n[{%d}]\n", retorno);
        r = 0;
        break;

      case 12:
        printf("\nEscolha a lista (1/2): ");
        scanf("%d", &k);
        if(k == 1)
          printf("\nTamanho: %d\n", tamanho(lista));
        else
          printf("\nTamanho: %d\n", tamanho(lista2));
        break;

      case 13:
        printf("\nEscolha a lista (1/2): ");
        scanf("%d", &k);
        if(k == 1)
          r = listaCheia(lista);
        else
          r = listaCheia(lista2);
        if(r == 2)
          printf("\nLista nao foi criada\n");
        else if(r == 0)
          printf("\nLista vazia\n");
        else
          printf("\nLista disponivel\n");
        r = 0;
        break;

      case 14:
        printf("\nEscolha a lista (1/2): ");
        scanf("%d", &k);
        if(k == 1)
          mostrar(lista);
        else
          mostrar(lista2);
        break;

      case 15:
        r = Comparar(lista, lista2);
        if(r == 2)
          printf("\nLista nao foi criada\n");
        else if(r == 3)
          printf("\nLista vazia\n");
        else if(r == 1)
          printf("\nListas diferentes\n");
        else
          printf("\nListas iguais\n");
        break;

      case 16:
        printf("\nSoma: %d\n", Somar(lista));
        break;

      case 17:
        printf("\nEscolha a lista (1/2): ");
        scanf("%d", &k);
        if(k == 1)
          Reverso(lista);
        else
          Reverso(lista2);
        break;

      case 18:
        printf("\nEscolha a lista (1/2): ");
        scanf("%d", &k);
        printf("\nDigite a matricula: ");
        scanf("%d", &mat);
        if(k == 1)
          r = RemoverTodos(lista, mat);
        else
          r = RemoverTodos(lista2, mat);
        if(r == -1)
          printf("\nLista nao existe\n");
        else if(r == 1)
          printf("\nNão Contem\n");
        mostrar(lista);
        printf("\n");
        r = 0;
        break;

      case 19:
        limpar(lista);
        limpar(lista2);
        return 0;
        break;
    }
  }
}
