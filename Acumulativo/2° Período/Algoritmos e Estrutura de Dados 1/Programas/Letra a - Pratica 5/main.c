#include<stdio.h>
#include<stdlib.h>
#include"String.h"

int main(void)
{
  String *s1;
  String *s2;
  int t1, t2, q, c, m = 0, k = 0;
  char a;

  while(m != 10)
  {
    printf("\nMenu:\n1) Criar String\n2) Tamanho da String\n3) Comparar Caractere\n4) Numero de Vogais\n5) Concatenar Palavras\n6) Mostrar Sting\n7) Encerrar\n\nDigite uma opcao: ");
    scanf("%d", &m);
    fflush(stdin);
    switch(m)
    {
      case 1:
        printf("\nDigite o tamanho maximo desejado: ");
        scanf("%d", &t1);
        fflush(stdin);
        t1++;
        s1 = criar(t1);
        fflush(stdin);
        t1 = tamanho(s1);
        k++;
        break;

      case 2:
        printf("\nO tamanho da string eh: %d\n", t1);
        break;

      case 3:
        printf("\nDigite o caractere a ser comparado: ");
        scanf("%c", &a);
        c = contador(s1, a, t1);
        printf("O numero de repeticoes do caractere '%c' eh: %d\n", a, c);
        break;

      case 6:
        mostrar(s1);
        printf("\n");
        break;

      case 4:
        q = vogais(s1, t1);
        printf("\nNumero de Vogais: %d\n", q);
        break;

      case 5:
        printf("\nDigite o tamanho maximo desejado da segunda string: ");
        scanf("%d", &t2);
        fflush(stdin);
        t2++;
        s2 = criar(t2);
        fflush(stdin);
        t2 = tamanho(s2);
        k++;
        concatenar(s1, s2, &t1, t2);
        break;

      case 7:
        if (k != 0)
          destruir(s1);
        if (k == 2)
          destruir(s2);
        return 0;
        break;
    }
  }
}



