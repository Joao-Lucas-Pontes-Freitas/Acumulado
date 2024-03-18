#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include"Lista.h"

int main(void) 
{
  Lista *lista;
  Lista *reversa;
  Aluno retorno;
  Aluno it;
  int r, mat, p, m = 0;
  
  while(m != 20)
  {
    printf("\nMenu:\n01) Criar Lista\n02) Limpar Lista\n03) Inserir Inicio\n04) Inserir Fim\n05) Inserir Posicao\n06) Remover Inicio\n07) Remover Fim\n08) Remover Posicao\n09) Remover Item\n10) Buscar Item\n11) Buscar Posicao\n12) Tamanho\n13) Status Lista\n14) Mostrar Lista\n15) Contem Item\n16) Reversa\n17) Conta Item\n18) Encerrar\n\nDigite uma opcao: ");
    scanf("%d", &m);
    __fpurge(stdin);
    switch(m)
    {
      case 1:
        lista = criar();
        break;

      case 2:
        limpar(lista);
        break;

      case 3:
        printf("\nDigite respectivamente a matricula, nome e nota do aluno que deseja inserir: ");
        scanf("%d %s %f", &it.mat, it.nome, &it.n1);
        r = inserirInicio(lista, it);
        if(r == 2)
          printf("\nLista nao foi criada");
        if(r == 1)
          printf("\nLista cheia");
        r = 0;
        break;

      case 4:
        printf("\nDigite respectivamente a matricula, nome e nota do aluno que deseja inserir: ");
        scanf("%d %s %f", &it.mat, it.nome, &it.n1);
        r = inserirFim(lista, it);
        if(r == 2)
          printf("\nLista nao foi criada\n");
        if(r == 1)
          printf("\nLista cheia\n");
        r = 0;
        break;

      case 5: 
        printf("\n(Comecando no 0) Digite a posicao: ");
        scanf("%d", &p);
        printf("\nDigite respectivamente a matricula, nome e nota do aluno que deseja inserir: ");
        scanf("%d %s %f", &it.mat, it.nome, &it.n1);
        r = inserirPosicao(lista, it, p);
        if(r == 2)
          printf("\nLista nao foi criada\n");
        if(r == 1)
          printf("\nLista cheia\n");
        if(r == 3)
          printf("\nPosicao invalida\n");
        r = 0;
        break;

      case 6:
        r = removerInicio(lista);
        if(r == 2)
          printf("\nLista nao foi criada\n");
        if(r == 1)
          printf("\nLista vazia\n");
        r = 0;
        break;
      
      case 7:
        r = removerFim(lista);
        if(r == 2)
          printf("\nLista nao foi criada\n");
        if(r == 1)
          printf("\nLista vazia\n");
        r = 0;
        break;

      case 8:
        printf("\n(Comecando no 0) Digite a posicao: ");
        scanf("%d", &p);
        r = removerPosicao(lista, p);
        if(r == 2)
          printf("\nLista nao foi criada\n");
        if(r == 1)
          printf("\nLista vazia\n");
        if(r == 3)
          printf("\nPosicao invalida\n");
        r = 0;
        break;

      case 9:
        printf("\nDigite a matricula: ");
        scanf("%d", &mat);
        r = removerItem(lista, mat);
        if(r == 2)
          printf("\nLista nao foi criada\n");
        else if(r == 1)
          printf("\nLista vazia\n");
        r = 0;
        break;

      case 10:
        printf("\nDigite a matricula: ");
        scanf("%d", &mat);
        r = buscarItemChave(lista, mat, &retorno);
        if(r == 2)
          printf("\nLista nao foi criada\n");
        else if(r == 1)
          printf("\nLista vazia\n");
        printf("\n[{%d, %s, %.2f}]\n", retorno.mat, retorno.nome, retorno.n1);
        r = 0;
        break;

      case 11:
        printf("\n(Comecando no 0) Digite a posicao: ");
        scanf("%d", &p);
        r = buscarPosicao(lista, p, &retorno);
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
        r = tamanho(lista);
        if(r == 2)
          printf("\nLista nao foi criada\n");
        r = 0;
        break;
      
      case 13:
        r = listaCheia(lista);
        if(r == 2)
          printf("\nLista nao foi criada\n");
        else if(r == 0)
          printf("\nLista cheia\n");
        else
        {
          r = listaVazia(lista);
          if(r == 0)
            printf("\nLista vazia\n");
          else
            printf("\nLista disponivel\n");
        }
        r = 0;
        break;
      
      case 14:
        mostrar(lista);
        break;

      case 15:
        printf("\nDigite a matricula: ");
        scanf("%d", &mat);
        r = ContemItem(lista, mat);
        if(r == 0)
          printf("\nContem\n");
        if(r == 1)
          printf("\nNão Contem\n");
        if (r == -3) 
          printf("\nLista vazia\n");
        r = 0;
        break;

      case 16:
        reversa = Reversa(lista, reversa);
        break;

      case 17:
        printf("\nDigite a matricula: ");
        scanf("%d", &mat);
        r = contaItem(lista, mat);
        printf("\nO item %d aparece %dx\n", mat, r);
        r = 0;
        break;

      case 18:
        limpar(lista);
        return 0;
        break;
    }
  }
}