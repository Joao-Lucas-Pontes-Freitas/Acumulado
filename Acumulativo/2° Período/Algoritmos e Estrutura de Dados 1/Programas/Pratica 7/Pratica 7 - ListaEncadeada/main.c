#include<stdio.h>
#include<stdlib.h>
#include"Lista.h"

int main(void)
{
  Lista *lista;
  Lista *lista2;
  Lista *concatena;
  Aluno retorno;
  Aluno it;
  int k, r, mat, p, n, m = 0;

  while(m != 20)
  {
    printf("\nMenu:\n01) Criar Lista\n02) Limpar Lista\n03) Inserir Inicio\n04) Inserir Fim\n05) Inserir Posicao\n06) Remover Inicio\n07) Remover Fim\n08) Remover Posicao\n09) Remover Item\n10) Buscar Item\n11) Buscar Posicao\n12) Tamanho\n13) Status Lista\n14) Mostrar Lista\n15) Contem Item\n16) Concatena\n17) Maior Nota\n18) Remover N Elementos\n19) Encerrar\n\nDigite uma opcao: ");
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
        printf("\nDigite respectivamente a matricula, nome e nota do aluno que deseja inserir: ");
        scanf("%d %s %f", &it.mat, it.nome, &it.n1);
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
        printf("\nDigite respectivamente a matricula, nome e nota do aluno que deseja inserir: ");
        scanf("%d %s %f", &it.mat, it.nome, &it.n1);
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
        printf("\nDigite respectivamente a matricula, nome e nota do aluno que deseja inserir: ");
        scanf("%d %s %f", &it.mat, it.nome, &it.n1);
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
        printf("\n[{%d, %s, %.2f}]\n", retorno.mat, retorno.nome, retorno.n1);
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
        printf("\n[{%d, %s, %.2f}]\n", retorno.mat, retorno.nome, retorno.n1);
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
        printf("\nEscolha a lista (1/2): ");
        scanf("%d", &k);
        printf("\nDigite a matricula: ");
        scanf("%d", &mat);
        if(k == 1)
          r = ContemItem(lista, mat);
        else
          r = ContemItem(lista2, mat);
        if(r == 0)
          printf("\nContem\n");
        if(r == 1)
          printf("\nNão Contem\n");
        if (r == -3)
          printf("\nLista vazia\n");
        r = 0;
        break;

      case 16:
        concatena = Concatena(lista, lista2);
        if (concatena == NULL)
          printf("\nNao foi possivel concatenar\n");
        else
          mostrar(concatena);
        break;

      case 17:
        printf("\nEscolha a lista (1/2): ");
        scanf("%d", &k);
        if(k == 1)
          r = MaiorNota(lista);
        else
          r = MaiorNota(lista2);
        if(r == 2)
          printf("\nLista nao foi criada\n");
        else if(r == 1)
          printf("\nLista vazia\n");
        break;

      case 18:
        printf("\nEscolha a lista (1/2): ");
        scanf("%d", &k);
        printf("\nDigite N: ");
        scanf("%d", &n);
        if(k == 1)
          r = RemoverNos(lista, n);
        else
          r = RemoverNos(lista2, n);
        if(r == 2)
          printf("\nLista nao foi criada\n");
        else if(r == 1)
          printf("\nLista vazia\n");
        break;

      case 19:
        limpar(lista);
        limpar(lista2);
        return 0;
        break;
    }
  }
}
