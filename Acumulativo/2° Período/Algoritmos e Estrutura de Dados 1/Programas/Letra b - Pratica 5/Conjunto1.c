#include "Conjunto.h"
#include <stdio.h>
#include <stdlib.h>

int *criar(int t)
{
  int *c, i;
  c = (int *)malloc(t*sizeof(int));

  printf("Digite os inteiros do conjunto: ");
  for (i = 0; i < t; i++)
    scanf("%d", &c[i]);
  return c;
}

int membro(int *c, int a, int t){
  int i, k = 0;
  for (i = 0; i < t; i++)
    if(c[i] == a){
      k = 1;
      break;
    }
  return k;
}

void pos_membro(int *c, int p)
{
  printf("O membro do conjunto na posicao '%d' eh: %d\n", p, c[p]);
}

void mostrar(int *c, int t)
{
  printf("Conjunto: ");
  int i;
  for (i = 0; i < t; i++)
    printf("%d ", c[i]);
  printf("\n");
}

void inserir(int *c, int *t)
{
  int i, j;
  printf("Digite o numero de elementos que deseja adiconar: ");
  scanf("%d", &j);
  c = (int *)realloc(c,*t+j*sizeof(int));
  printf("\nDigite o elemento a ser adiconado: ");
  for (i = 0; i < j; i++)
    scanf("%d", &c[*t + i]);
  *t = *t + j;
}

void remover(int *c, int *t)
{
  int p, i;
  printf("Digite a posicao que deseja remover: ");
  scanf("%d", &p);
  (*t)--;
  for (i = p; i < *t; i++)
    c[p] = c[p+1];
  c = (int *)realloc(c,*t*sizeof(int));
}

void uniao(int *c1, int *c2, int t1, int t2)
{
  int *u, t = 0, i, j, k;
  u = (int *)malloc(1*sizeof(int));
  for(i = 0; i < t1; i++)
  {
    k = 0;
    for(j = 0; j < t2; j++)
      if(c1[i] == c2[j])
        k++;
    if(k == 0){
      u[t] = c1[i];
      t++;
      u = (int *)realloc(u,t*sizeof(int));
    }
  }
  for (i = 0; i < t2; i++, t++)
    u[t] = c2[i];
  mostrar(u, t);
}

void inter(int *c1, int *c2, int t1, int t2)
{
  int *in, i, j, t = 0;
  in = (int *)malloc(1*sizeof(int));
  for (i = 0; i < t1; i++)
    for (j = 0; j < t2; j++)
      if(c1[i] == c2[j]){
        in[t] = c1[i];
        t++;
        in = (int *)realloc(in,t*sizeof(int));
      }
  mostrar(in, t);
}

void difer(int *c1, int *c2, int t1, int t2)
{
  int *d, t = 0, i, j, k;
  d = (int *)malloc(1*sizeof(int));
  for(i = 0; i < t1; i++)
  {
    k = 0;
    for(j = 0; j < t2; j++)
      if(c1[i] == c2[j])
        k++;
    if(k == 0){
      d[t] = c1[i];
      t++;
      d = (int *)realloc(d,t*sizeof(int));
    }
  }
  mostrar(d, t);
}

void destruir(int *c)
{
  free(c);
}
