#include<stdio.h>
#include<stdlib.h>
#include"Lista.h"

int main(void)
{
  Lista *lista;
  Lista *lista2;
  Aluno it;
  int c = 0, k, r, p1, p2, m = 0;

  while(m != 20)
  {
    printf("\nMenu:\n01) Cadastrar Aluno\n02) Remover Aluno\n03) Listar Alunos Cadastrados\n04) Aluno Com Maior Nota\n05) Remover Todos Os Alunos\n06) Trocar Posicoes\n07) Verificar Ordem\n08) Comparar Listas\n09) Sair\n\nDigite uma opcao: ");
    scanf("%d", &m);

    switch(m)
    {
      case 1:
        if (c == 0){
          lista = criar();
          lista2 = criar();
          c++;
        }
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

      case 2:
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

      case 3:
        printf("\nEscolha a lista (1/2): ");
        scanf("%d", &k);
        if(k == 1)
          mostrar(lista);
        else
          mostrar(lista2);
        break;

      case 4:
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

      case 5:
        printf("\nEscolha a lista (1/2): ");
        scanf("%d", &k);
        if(k == 1)
          limpar(lista);
        else
          limpar(lista2);
        break;

      case 6:
        printf("\nEscolha a lista (1/2): ");
        scanf("%d", &k);
        printf("\nDigite as duas posicoes que gostaria de trocar: ");
        scanf("%d %d", &p1, &p2);
        if(k == 1)
          Troca(lista, p1, p2);
        else
          Troca(lista2, p1, p2);
        if(r == 2)
          printf("\nLista nao foi criada\n");
        else if(r == 3)
          printf("\nLista vazia\n");
        break;

      case 7:
        printf("\nEscolha a lista (1/2): ");
        scanf("%d", &k);
        if(k == 1)
          r = Ordenada(lista);
        else
          r = Ordenada(lista2);
        if(r == 0)
          printf("\nLista esta em ordem crescente\n");
        else if(r == 1)
          printf("\nLista nao esta em ordem crescente\n");
        else if(r == 2)
          printf("\nLista nao foi criada\n");
        else if(r == 3)
          printf("\nLista vazia\n");
        break;

      case 8:
        r = Compara(lista, lista2);
        if(r == 0)
          printf("\nListas iguais\n");
        else if(r == 1)
          printf("\nListas nao iguais\n");
        else if(r == 2)
          printf("\nLista nao foi criada\n");
        else if(r == 3)
          printf("\nLista vazia\n");
        break;

      case 9:
        limpar(lista);
        limpar(lista2);
        free(lista);
        lista = NULL;
        free(lista2);
        lista2 = NULL;
        return 0;
        break;

    }
  }
}
