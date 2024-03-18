#include "Matriz.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct matriz{
  float **m;
  int l;
  int c;
}Matriz;

Matriz *criar(int l, int c)
{
  Matriz *mat = (Matriz*)malloc(sizeof(Matriz));
  int i;
  mat-> l = l;
  mat-> c = c;
  mat-> m = (float**)calloc(l,sizeof(float*));
  for(i = 0; i < l; i++)
    mat-> m[i] = (float*)calloc(c,sizeof(float));
  return mat;
}
void mostrar(Matriz *mat)
{
  int i, j;
  int l = mat->l;
  int c = mat->c;
  for (i = 0; i < l; i++)
    for (j = 0; j < c; j++)
      printf("%.2f ", mat->m[i][j]);
  printf("\n");
}
void inserir(Matriz *mat, int l, int c)
{
  printf("Digite o elemento que deseja adicionar: ");
  scanf("%f", &mat->m[l][c]);
}
void remover(Matriz *mat, int l, int c)
{
  mat-> m[l][c] = 0;
}
void membro(Matriz *mat, int l, int c)
{
  printf("%.2f\n", mat->m[l][c]);
}
void linhas(Matriz *mat)
{
  printf("Numero de linhas: %d\n", mat->l);
}
void colunas(Matriz *mat)
{
  printf("Numero de colunas: %d\n", mat->c);
}
Matriz *preencher(Matriz *mat, float a, float b)
{
  int i, j;
  int l = mat->l;
  int c = mat->c;
  for (i = 0; i < l; i++)
    for (j = 0; j < c; j++){
      mat->m[i][j] = ((float) rand() / (float) RAND_MAX) * (b-a) + a;
    }
  mostrar(mat);
  return mat;
}
void somar(Matriz *mat1, Matriz *mat2)
{
  int i, j;
  Matriz *s;
  int l1 = mat1->l;
  int c1 = mat1->c;
  int l2 = mat2->l;
  int c2 = mat2->c;

  if(l1 != l2 || c1 != c2){
    printf("Soma invalida\n");
    return;
  }
  s = criar(l1, c1);
  for (i = 0; i < l1; i++)
    for (j = 0; j < c1; j++)
      s->m[i][j] = mat1->m[i][j] + mat2->m[i][j];
  mostrar(s);
  destruir(s);
}
void destruir(Matriz *mat)
{
  int i;
  int l = mat->l;
  for(i = 0; i < l; i++)
    free(mat->m[i]);
  free(mat->m);
  free(mat);
}
