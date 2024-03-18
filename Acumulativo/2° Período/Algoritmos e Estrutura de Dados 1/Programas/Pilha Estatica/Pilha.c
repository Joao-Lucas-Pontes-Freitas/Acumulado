#include <stdio.h> 
#include <stdlib.h>
#include "Pilha.h"
#include <string.h>

typedef struct pilha {    
  int topo;    
  int valores[MAX]; 
} Pilha;
/*
  Letra A

  int push(Pilha *p, int it) 
{    
  if (p == NULL) return 2;    
  if (pilhaCheia(p) == 0) return 1;    
  p->valores[p->topo] = it;    
  p->topo++;    return 0; 
}

int pop(Pilha *p, int *it) 
{    
  if (p == NULL) return 2;    
  if (pilhaVazia(p) == 0) return 1;    
  *it = p->valores[p->topo-1];    
  p->topo--;    
  return 0; 
}

int consultar(Pilha *p, int *it) 
{    
  if (p == NULL) return 2;    
  if (pilhaVazia(p) == 0) return 1;    
  *it = p->valores[p->topo-1];    
  return 0; 
} 

int tamanho(Pilha *p) {    
  if (p == NULL) return -1;    
  return p->topo; 
}

int pilhaVazia(Pilha *p) 
{    
  if (p == NULL) return 2;    
  if (p->topo == 0) return 0;    
  else return 1; 
} 

int pilhaCheia(Pilha *p) 
{    
  if (p == NULL) return 2;    
  if (p->topo == MAX) return 0;    
  else return 1; 
}

void mostrar(Pilha *p) 
{   
  if (p != NULL ) {      
    printf("[\n");      
    int i;      
    for (i = p->topo-1; i >= 0; i--){//i = 0; i < p->topo; i++) {                
      printf("  { %d }\n",p->valores[i]);      
    }      
    printf("]\n");   
  } 
}


*/
Pilha *criar() 
{   
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));   
  p->topo = 0;   
  return p; 
} 

void limpar(Pilha *p) 
{   
  free(p);   
  p = NULL; 
}

int push(Pilha *p, char it) 
{    
  if (p == NULL) return 2;    
  if (pilhaCheia(p) == 0) return 1;    
  p->valores[p->topo] = it;    
  p->topo++;    return 0; 
}

int pop(Pilha *p, char *it) 
{    
  if (p == NULL) return 2;    
  if (pilhaVazia(p) == 0) return 1;    
  *it = p->valores[p->topo-1];    
  p->topo--;    
  return 0; 
}

int consultar(Pilha *p, char *it) 
{    
  if (p == NULL) return 2;    
  if (pilhaVazia(p) == 0) return 1;    
  *it = p->valores[p->topo-1];    
  return 0; 
} 

int tamanho(Pilha *p) {    
  if (p == NULL) return -1;    
  return p->topo; 
}

int pilhaVazia(Pilha *p) 
{    
  if (p == NULL) return 2;    
  if (p->topo == 0) return 0;    
  else return 1; 
} 

int pilhaCheia(Pilha *p) 
{    
  if (p == NULL) return 2;    
  if (p->topo == MAX) return 0;    
  else return 1; 
}

void mostrar(Pilha *p) 
{   
  if (p != NULL ) {      
    printf("[\n");      
    int i;      
    for (i = p->topo-1; i >= 0; i--){//i = 0; i < p->topo; i++) {                
      printf("  { %c}\n",p->valores[i]);      
    }      
    printf("]\n");   
  } 
}

int palindromo(char *it)
{
  Pilha *p = criar();
  int i, total = strlen(it)-1;
  int metade = total/2;
  for(i = 0; i < metade; i++)
    push(p,it[i]);
  if((total%2) != 0)
    metade++;
  char c;
  for(i = metade; i < total; i++)
    if((pop(p, &c) != 0) || (c != it[i]))
      return 1;
  return 0;
  
  return 0;
}

int validar(char *it)
{
  Pilha *p = criar();
  int i, tam = strlen(it)-1;
  char c;
  for(i = 0; i < tam; i++){
    switch (it[i]){
      case ')':
        if((pop(p,&c) != 0) || (c != '('))
          return 1;
        break;
      case ']':
        if((pop(p,&c) != 0) || (c != '['))
          return 1;
        break;
      case '}':
        if((pop(p,&c) != 0) || (c != '{'))
          return 1;
        break;
      default:
        push(p,it[i]);
    }
  }
  if(pilhaVazia(p) == 0) return 0;
  else return 1;
}

