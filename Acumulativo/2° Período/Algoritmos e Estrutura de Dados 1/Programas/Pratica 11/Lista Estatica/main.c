#include<stdio.h>
#include<stdlib.h>
#include"Fila.h"

int main(void)
{
  Fila *fila;
  Fila *fila2;
  Fila *fila3;
  int it;
  int k = 0, r, m = 0;

  while(m != 11)
  {
    printf("\nMenu:\n01) Criar fila\n02) Excluir fila\n03) Inserir\n04) Remover\n05) Tamanho\n06) Status fila\n07) Consultar\n08) Mostrar fila\n09) Intercalar filas\n10) Excluir negativos\n11) Encerrar\n\nDigite uma opcao: ");
    scanf("%d", &m);

    switch(m)
    {
      case 1:
        fila = criar();
        fila2 = criar();
        k = 1;
        break;

      case 2:
        printf("\nEscolha a fila (1/2): ");
        scanf("%d", &k);
        if(k == 1)
          limpar(fila);
        else
          limpar(fila2);
        break;

      case 3:
        printf("\nEscolha a fila (1/2): ");
        scanf("%d", &k);
        printf("\nDigite o numero inteiro que deseja inserir: ");
        scanf("%d", &it);
        if(k == 1)
          r = inserir(fila, it);
        else
          r = inserir(fila2, it);
        if(r == 2)
          printf("\nfila nao foi criada\n");
        if(r == 1)
          printf("\nfila cheia\n");
        r = 0;
        break;

      case 4:
        printf("\nEscolha a fila (1/2): ");
        scanf("%d", &k);
        if(k == 1)
          r = remover(fila, &it);
        else
          r = remover(fila2, &it);
        if(r == 2)
          printf("\nfila nao foi criada\n");
        if(r == 1)
          printf("\nfila vaziazn\n");
        r = 0;
        break;

      case 5:
        printf("\nEscolha a fila (1/2): ");
        scanf("%d", &k);
        if(k == 1)
          printf("\nTamanho: %d\n", tamanho(fila));
        else
          printf("\nTamanho: %d\n", tamanho(fila2));
        break;

      case 6:
        printf("\nEscolha a fila (1/2): ");
        scanf("%d", &k);
        if(k == 1)
          r = filaCheia(fila);
        else
          r = filaCheia(fila2);
        if(r == 2)
          printf("\nfila nao foi criada\n");
        else if(r == 0)
          printf("\nfila vazia\n");
        else
          printf("\nfila disponivel\n");
        r = 0;
        break;

      case 8:
        printf("\nEscolha a fila (1/2): ");
        scanf("%d", &k);
        if(k == 1)
          mostrar(fila);
        else
          mostrar(fila2);
        break;

      case 9:
        fila3 = intercalar(fila, fila2);
        if (fila3 != NULL)
          mostrar(fila3);
        break;

      case 10:
        printf("\nEscolha a fila (1/2): ");
        scanf("%d", &k);
        if(k == 1){
          r = RetiraNegativo(fila);
          if(r == 2)
            printf("\nfila nao foi criada\n");
          else
            mostrar(fila);
        }
        else{
          r = RetiraNegativo(fila2);
          if(r == 2)
            printf("\nfila nao foi criada\n");
          else
            mostrar(fila2);
        }
        r = 0;
        break;

      case 11:
        if (k != 0){
          limpar(fila);
          limpar(fila2);
        }
        return 0;
        break;
    }
  }
}
