#include"String.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string{
  char *c;
}String;

String *criar(int t)
{
  int i;
  String *s = (String *)malloc(sizeof(String));

  s-> c = (char *)malloc(t*sizeof(char));

  printf("Digite a string: ");

  fgets(s->c, t, stdin);

  for(i = 0; i < t; i++)
    if ((*s).c[i] == '\n')
      (*s).c[i] = '\0';

  return s;
}

int tamanho(String *s)
{
  int t = strlen(s-> c);
  s-> c = realloc(s-> c,t*sizeof(char));

  return t;
}

int contador(String *s, char a, int t)
{
  int i, j = 0;
  for (i = 0; i < t; i++){
    if ((*s).c[i] == a){
      j++;
    }
  }
  return j;
}

int vogais(String *s, int t)
{
  int i, j = 0;
  for (i = 0; i < t; i++)
    if ((*s).c[i] == 'a' || (*s).c[i] == 'e' || (*s).c[i] == 'i' || (*s).c[i] == 'o' || (*s).c[i] == 'u')
      j++;
  return j;
}

void mostrar(String *s)
{
  printf("\nA string eh: ");
  printf("%s\n", s->c);
}

void concatenar(String *s1, String *s2, int *t1, int t2)
{
  s1->c = realloc(s1-> c,*t1+t2*sizeof(char));
  strcat(s1->c, s2->c);
  mostrar(s1);
  *t1 = strlen(s1-> c);
}

void destruir(String *s)
{
  free(s->c);
  free(s);
}
