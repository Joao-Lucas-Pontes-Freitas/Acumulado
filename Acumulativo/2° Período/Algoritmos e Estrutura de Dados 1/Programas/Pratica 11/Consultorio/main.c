#include<stdio.h>
#include<stdlib.h>
#include"Fila.h"

int main(void)
{
  Fila *fila;
  Paciente it;
  it.nome = (char *)malloc(100*sizeof(char));

  int k = 0, r, m = 0;

  while(m != 4)
  {
    printf("\nMenu:\n1) Cadastrar Paciente\n2) Atender Proximo\n3) Mostrar fila\n4) Encerrar\n\nDigite uma opcao: ");
    scanf("%d", &m);

    switch(m)
    {
      case 1:
        if (k == 0){
          fila = criar();
          k++;
        }
        printf("\nDigite o nome que deseja inserir: ");
        fflush(stdin);
        scanf("%s", it.nome);
        r = inserir(fila, it);
        if(r == 2)
          printf("\nfila nao foi criada\n");
        if(r == 1)
          printf("\nfila cheia\n");
        r = 0;
        break;

      case 2:
        r = remover(fila);
        if(r == 2)
          printf("\nfila nao foi criada\n");
        if(r == 1)
          printf("\nfila vazia\n");
        r = 0;
        break;

      case 3:
        mostrar(fila);
        break;

      case 4:
        if (k != 0)
          limpar(fila);
        return 0;
        break;
    }
  }
}
