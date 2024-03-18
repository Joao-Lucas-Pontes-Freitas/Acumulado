#include<stdio.h>
#include<stdlib.h>
#include"Matriz.h"

int main(void)
{
  Matriz *m1, *m2;
  int m, e, k = 0, l = 0, c = 0;
  float a, b;

  while(m != 10)
  {
    printf("\nMenu:\n01) Criar Matriz\n02) Mostrar Matriz\n03) Atribuir Valor\n04) Acessar Elemento\n05) Remover Elemento\n06) Num de Linhas\n07) Num de Colunas\n08) Preencher Aleatoriamente\n09) Somar Matrizes\n10) Encerrar\n\nDigite uma opcao: ");
    scanf("%d", &m);
    fflush(stdin);
    switch(m)
    {
      case 1:
        printf("\nDigite o numero de linhas e colunas da primeira matriz: ");
        scanf("%d %d", &l, &c);
        fflush(stdin);
        m1 = criar(l, c);
        k++;
        printf("Digite o numero de linhas e colunas da segunda matriz: ");
        scanf("%d %d", &l, &c);
        fflush(stdin);
        m2 = criar(l, c);
        k++;
        break;

      case 2:
        printf("\nEscolha qual matriz (1/2): ");
        scanf("%d", &e);
        printf("Matriz %d: ", e);
        if(e == 1)
          mostrar(m1);
        else
          mostrar(m2);
        e = 0;
        break;

      case 3:
        printf("\nEscolha qual matriz (1/2): ");
        scanf("%d", &e);
        printf("Digite as coordenadas: ");
        scanf("%d %d", &l, &c);
        if(e == 1)
          inserir(m1, l, c);
        else
          inserir(m2, l, c);
        e = 0;
        break;

      case 4:
        printf("\nEscolha qual matriz (1/2): ");
        scanf("%d", &e);
        printf("Digite as coordenadas: ");
        scanf("%d %d", &l, &c);
        if(e == 1)
          membro(m1, l, c);
        else
          membro(m2, l, c);
        e = 0;
        break;
        break;

      case 5:
        printf("\nEscolha qual matriz (1/2): ");
        scanf("%d", &e);
        printf("Digite as coordenadas: ");
        scanf("%d %d", &l, &c);
        if(e == 1)
          remover(m1, l, c);
        else
          remover(m2, l, c);
        e = 0;
        break;

      case 6:
        printf("\nEscolha qual matriz (1/2): ");
        scanf("%d", &e);
        if(e == 1 && k != 0)
          linhas(m1);
        else if(e == 2 && k ==  2)
          linhas(m2);
        else
          printf("0\n");
        e = 0;
        break;

      case 7:
        printf("\nEscolha qual matriz (1/2): ");
        scanf("%d", &e);
        if(e == 1 && k != 0)
          colunas(m1);
        else if(e == 2 && k ==  2)
          colunas(m2);
        else
          printf("0\n");
        e = 0;
        break;

      case 8:
        printf("\nEscolha qual matriz (1/2): ");
        scanf("%d", &e);
        printf("Digite o minimo e maximo: ");
        scanf("%f %f", &a, &b);
        if(e == 1)
          m1 = preencher(m1, a, b);
        else
          m2 = preencher(m2, a, b);
        e = 0;
        break;

      case 9:
        somar(m1, m2);
        break;

      case 10:
        if(k == 2){
          destruir(m1);
          destruir(m2);
          return 0;
        }
        else
          return 0;
        break;
    }
  }
}
