#include <stdio.h> 
#include <stdlib.h>
#include "Pilha.h"
#include <string.h>

typedef struct no {    
  int valor;    
  struct no *prox; 
} No;

typedef struct pilha {    
  No *topo; 
} Pilha;
/*
Pilha *criar() 
{   
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));   
  p->topo = NULL;
  return p;
} 

void limpar(Pilha *p) 
{   
  if (p == NULL) return;   
  while (pilhaVazia(p) != 0) 
    pop(p, NULL);   
  free(p);   
  p = NULL; 
}

int push(Pilha *p, int it) 
{    
  if (p == NULL) return 2;    
  No *no = (No *)malloc(sizeof(No));    
  no->valor = it;    
  no->prox = p->topo;    
  p->topo = no;    
  return 0; 
}

int pop(Pilha *p, int *it) 
{    
  if (p == NULL) return 2;    
  if (pilhaVazia(p) == 0) return 1;    
  No *temp = p->topo;    
  *it = temp->valor;    
  p->topo = temp->prox;    
  free(temp);    
  return 0; 
}

int consultar(Pilha *p, int *it) 
{    
  if (p == NULL) return 2;    
  if (pilhaVazia(p) == 0) return 1;    
  No *temp = p->topo;    
  *it = temp->valor;    
  return 0; 
}

int tamanho(Pilha *p) 
{    
  if (p == NULL) return -1;    
  int ct = 0;    
  No *no = p->topo;    
  while (no != NULL) {       
    ct++;       
    no = no->prox;    
  }    
  return ct; 
}

int pilhaVazia(Pilha *p) 
{    
  if (p == NULL) return 2;    
  if (p->topo == NULL) return 0;    
  else return 1; 
} 

int pilhaCheia(Pilha *p) 
{    
  return 1; 
}

void mostrar(Pilha *p) 
{    
  if (p != NULL) {       
    printf("[");       
    No *no = p->topo;       
    while (no != NULL) {                         
      printf("{%d} ",no->valor);          
      no = no->prox;       
    }       
    printf("]\n");    
  } 
}

*/

Pilha *criar() 
{   
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));   
  p->topo = NULL;
  return p;
} 

void limpar(Pilha *p) 
{   
  if (p == NULL) return;   
  while (pilhaVazia(p) != 0) 
    pop(p, NULL);   
  free(p);   
  p = NULL; 
}

int push(Pilha *p, char it) 
{    
  if (p == NULL) return 2;    
  No *no = (No *)malloc(sizeof(No));    
  no->valor = it;    
  no->prox = p->topo;    
  p->topo = no;    
  return 0; 
}

int pop(Pilha *p, char *it) 
{    
  if (p == NULL) return 2;    
  if (pilhaVazia(p) == 0) return 1;    
  No *temp = p->topo;    
  *it = temp->valor;    
  p->topo = temp->prox;    
  free(temp);    
  return 0; 
}

int consultar(Pilha *p, char *it) 
{    
  if (p == NULL) return 2;    
  if (pilhaVazia(p) == 0) return 1;    
  No *temp = p->topo;    
  *it = temp->valor;    
  return 0; 
}

int tamanho(Pilha *p) 
{    
  if (p == NULL) return -1;    
  int ct = 0;    
  No *no = p->topo;    
  while (no != NULL) {       
    ct++;       
    no = no->prox;    
  }    
  return ct; 
}

int pilhaVazia(Pilha *p) 
{    
  if (p == NULL) return 2;    
  if (p->topo == NULL) return 0;    
  else return 1; 
} 

int pilhaCheia(Pilha *p) 
{    
  return 1; 
}

void mostrar(Pilha *p) 
{    
  if (p != NULL) {       
    printf("[");       
    No *no = p->topo;       
    while (no != NULL) {                         
      printf("{%c} ",no->valor);          
      no = no->prox;       
    }       
    printf("]\n");    
  } 
}

int palindromo(char *it)
{
  Pilha *p = criar();
  int i, total = strlen(it) -1;
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



