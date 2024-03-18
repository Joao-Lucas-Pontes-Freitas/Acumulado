#include<stdio.h>
#include<stdlib.h>
#include"Conjunto.h"

int main(void)
{
  int *c1;
  int *c2;
  int t1, t2, p, a, b = 0, d = 0, m = 0, k = 0;
  int e;

  while(m != 10)
  {
    printf("\nMenu:\n01) Criar Conjunto\n02) Verificar Membro\n03) Verificar Posicao\n04) Inserir\n05) Remover\n06) Uniao\n07) Interseccao\n08) Diferenca\n09) Mostrar Conjunto\n10) Encerrar\n\nDigite uma opcao: ");
    scanf("%d", &m);
    fflush(stdin);
    switch(m)
    {
      case 1:
        printf("\nDigite o numero de elementos que deseja inserir: ");
        scanf("%d", &t1);
        fflush(stdin);
        c1 = criar(t1);
        k++;
        printf("\nDigite o numero de elementos que deseja inserir no segundo conjunto: ");
        scanf("%d", &t2);
        fflush(stdin);
        c2 = criar(t2);
        k++;
        break;

      case 2:
        fflush(stdin);
        printf("Digite o elemento que deseja verificar: ");
        scanf("%d", &a);
        b = membro(c1, a, t1);
        d = membro(c2, a, t2);
        if (b == 0 && d != 0)
          printf("'%d' pertence a 2 mas nao a 1\n", a);
        else if (d == 0 && b != 0)
          printf("'%d' pertence a 1 mas nao a 2\n", a);
        else if (b != 0 && d != 0)
          printf("'%d' pertence a 1 e a 2\n", a);
        else
          printf("'%d' nao pertence a 1 nem a 2\n", a);
        break;

      case 3:
        printf("\nEscolha qual conjunto (1/2): ");
        scanf("%d", &e);
        printf("Digite a posicao que deseja verificar: ");
        scanf("%d", &p);
        if(e == 1)
          pos_membro(c1, p);
        else
          pos_membro(c2, p);
        e = 0;
        break;

      case 4:
        printf("\nEscolha qual conjunto (1/2): ");
        scanf("%d", &e);
        if(e == 1)
          inserir(c1, &t1);
        else
          inserir(c2, &t2);
        e = 0;
        break;

      case 5:
        printf("\nEscolha qual conjunto (1/2): ");
        scanf("%d", &e);
        if(e == 1)
          remover(c1, &t1);
        else
          remover(c2, &t2);
        e = 0;
        break;

      case 6:
        uniao(c1, c2, t1, t2);
        break;

      case 7:
        inter(c1, c2, t1, t2);
        break;

      case 8:
        difer(c1, c2, t1, t2);
        break;

      case 9:
        printf("\nEscolha qual conjunto (1/2): ");
        scanf("%d", &e);
        if(e == 1)
          mostrar(c1, t1);
        else
          mostrar(c2, t2);
        e = 0;
        break;

      case 10:
        if(k == 2){
          destruir(c1);
          destruir(c2);
          return 0;
        }
        else
          return 0;
        break;
    }
  }
}
