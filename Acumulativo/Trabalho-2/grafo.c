#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Grafos.h"

#define MAXNUMVERTICES  100
#define MAXNUMARESTAS   4500
#define FALSE           0
#define TRUE            1
#define branco 0
#define cinza 1
#define preto 2

int t[MAXNUMVERTICES + 1];
int s[MAXNUMVERTICES + 1];

int ar[MAXNUMVERTICES + 1] = {-1};


/*--Entram aqui os operadores do Programa 2.4--*/
void FLVazia(Lista *Lista) {
  Lista->Primeiro = (Apontador)malloc(sizeof(Celula));
  Lista->Ultimo = Lista->Primeiro;
  Lista->Primeiro->Prox = NULL;
}
void BuscaEmProfundidade(Grafo *Grafo, char c[MAXNUMVERTICES][50]){
  int x; 
  int Tempo;
  int d[MAXNUMVERTICES + 1], t[MAXNUMVERTICES + 1];
  int Cor[MAXNUMVERTICES+1]; 
  short Antecessor[MAXNUMVERTICES+1];
  Tempo = 0;
  for(x = 0; x <= Grafo->NumVertices - 1; x++){
    Cor[x] = branco;
    Antecessor[x] = -1;
  }
  for(x = 0; x <= Grafo->NumVertices - 1; x++){
    if(Cor[x] == branco)
      VisitaDfs(x, Grafo, &Tempo, d, t, Cor, Antecessor, c);
  }
}

void VisitaDfs(int u, Grafo *g, int* Tempo, int* d, int* t, int* Cor, short* Antecessor, char c[MAXNUMVERTICES][50])
{
  printf("1\n");
  short FimListaAdj; 
  int Peso; 
  Apontador Aux;
  int v; 
  Cor[u] = cinza; 
  (*Tempo)++; 
  d[u] = (*Tempo);
  printf("2\n");
  printf("Visita%2d Tempo descoberta:%2d cinza\n", u, d[u]); getchar();
  if(!ListaAdjVazia(&u, g)){
    Aux = PrimeiroListaAdj(u, g);
    FimListaAdj = FALSE;
    printf("3\n");
    while(!FimListaAdj){
      ProxAdj(g, &v, &Peso, &Aux, &FimListaAdj, c);
      if(Cor[v] == branco){ 
        Antecessor[v] = u;
        VisitaDfs(v, g, Tempo, d, t, Cor, Antecessor, c);
      }
      printf("4\n");
    }
  }
  Cor[u] = preto; (*Tempo)++; t[u] = (*Tempo);
  printf("Visita%2d Tempo termino:%2d preto\n", u, t[u]); getchar();
}

short Vazia(Lista Lista) { return (Lista.Primeiro == Lista.Ultimo); }

void Insere(Aresta *x, Lista *Lista) {
  /*-- Insere depois do ultimo Aresta da lista --*/
  Lista->Ultimo->Prox = (Apontador)malloc(sizeof(Celula));
  Lista->Ultimo = Lista->Ultimo->Prox;
  Lista->Ultimo->Aresta = *x;
  Lista->Ultimo->Prox = NULL;
}

/*-- Fim operadores do Programa 2.4 --*/
Grafo FGVazio() {
  Grafo *g = (Grafo *) malloc(sizeof(Grafo));
  g->NumArestas = 0;
  g->NumVertices = 0;
  for (int i = 0; i < MAXNUMVERTICES; i++)
    FLVazia(&g->Adj[i]);
  return *g;
}

// void InsereAresta(int *V1, int *V2, int *Peso, Grafo *g) {
//   Aresta x;
//   x.Vertice = *V2;
//   x.Peso = *Peso;
//   Insere(&x, &g->Adj[*V1]);
// }


void InsereArestaAlt(char str1[], char str2[], int *distancia, int *pedagio, Grafo *g, char c[MAXNUMVERTICES][50]) {
  Aresta x;
  strcpy(x.vertice, str1);
  strcpy(x.vertice, str2);
  x.dist = *distancia;
  Insere(&x, &g->Adj[findVertice(c, str1)]);
}

// short ExisteAresta(int Vertice1, int Vertice2, Grafo *g) {
//   Apontador Aux;
//   short EncontrouAresta = FALSE;
//   Aux = g->Adj[Vertice1].Primeiro->Prox;
//   while (Aux != NULL && EncontrouAresta == FALSE) {
//     if (Vertice2 == Aux->Aresta.Vertice)
//       EncontrouAresta = TRUE;
//     Aux = Aux->Prox;
//   }

//   return EncontrouAresta;
// }

/* Operadores para obter a lista de adjacentes */
short ListaAdjVazia(int *Vertice, Grafo *g) {
  return (g->Adj[*Vertice].Primeiro == g->Adj[*Vertice].Ultimo);
}

Apontador PrimeiroListaAdj(int Vertice, Grafo *g) {
  return (g->Adj[Vertice].Primeiro->Prox);
}

void ProxAdj(Grafo *g, int *Adj, int *dist, Apontador *Prox, short *FimListaAdj, char c[MAXNUMVERTICES][50]) {
  /* Retorna Adj e Peso do Aresta apontado por Prox */
  *Adj = findVertice(c, (*Prox)->Aresta.vertice);
  *dist = (*Prox)->Aresta.dist;
  *Prox = (*Prox)->Prox;
  if (*Prox == NULL)
    *FimListaAdj = TRUE;  
}

void ProxAdjPed(Grafo *g, int *Adj, int *peso, Apontador *Prox, short *FimListaAdj, char c[MAXNUMVERTICES][50]) {
  /* Retorna Adj e Peso do Aresta apontado por Prox */
  *Adj = findVertice(c, (*Prox)->Aresta.vertice);
  *peso = (*Prox)->Aresta.pedagio;
  *Prox = (*Prox)->Prox;
  if (*Prox == NULL)
    *FimListaAdj = TRUE;  
}


void Retira(Apontador p, Lista *Lista, Aresta *Aresta) {
  /*--Obs.: Aresta a ser retirado e o seguinte ao apontado por p--*/
  Apontador q;
  if (Vazia(*Lista) || p == NULL || p->Prox == NULL) {
    printf("Erro: Lista vazia ou posicao nao existe\n");
    return;
  }
  q = p->Prox;
  *Aresta = q->Aresta;
  p->Prox = q->Prox;
  if (p->Prox == NULL)
    Lista->Ultimo = p;
  free(q);
}

// void RetiraAresta(int *V1, int *V2, int *Peso, Grafo *g) {
//   Apontador AuxAnterior, Aux;
//   short EncontrouAresta = FALSE;
//   Aresta x;
//   AuxAnterior = g->Adj[*V1].Primeiro;
//   Aux = g->Adj[*V1].Primeiro->Prox;
//   while (Aux != NULL && EncontrouAresta == FALSE) {
//     if (*V2 == Aux->Aresta.Vertice) {
//       Retira(AuxAnterior, &g->Adj[*V1], &x);
//       g->NumArestas--;
//       EncontrouAresta = TRUE;
//     }
//     AuxAnterior = Aux;
//     Aux = Aux->Prox;
//   }
// }

void LiberaGrafo(Grafo *g) {
  Apontador AuxAnterior, Aux;
  for (int i = 0; i < g->NumVertices; i++) {
    Aux = g->Adj[i].Primeiro->Prox;
    free(g->Adj[i].Primeiro); /*Libera celula cabeca*/
    g->Adj[i].Primeiro = NULL;
    while (Aux != NULL) {
      AuxAnterior = Aux;
      Aux = Aux->Prox;
      free(AuxAnterior);
    }
  }
  g->NumVertices = 0;
}

void ImprimeGrafo(Grafo *g, char c[MAXNUMVERTICES][50]) {
  Apontador Aux;
  for (int i = 0; i < g->NumVertices; i++) {
    if (c[i] != 0) printf("(%d) %s: ", i+1,c[i]);
    if (!Vazia(g->Adj[i])) {
      Aux = g->Adj[i].Primeiro->Prox;
      while (Aux != NULL) {
        printf("%3s (%d, %d) ",Aux->Aresta.vertice, Aux->Aresta.dist, Aux->Aresta.pedagio);
        Aux = Aux->Prox;
      }
    }
    putchar('\n');
  }
}

void ImprimeLista(Lista Lista) {
  Apontador Aux;
  Aux = Lista.Primeiro->Prox;
  while (Aux != NULL) {
    printf("%3s (%d) ", Aux->Aresta.vertice, Aux->Aresta.pedagio);
    Aux = Aux->Prox;
  }
}

void GrafoTransposto(Grafo *GrafoT, Grafo *g, char c[MAXNUMVERTICES][50]){
  int v, Adj;
  int Peso;
  int x = 1;
  Apontador Aux;
  short FimListaAdj;
  GrafoT->NumVertices = g->NumVertices;
  GrafoT->NumArestas = g->NumArestas;
  for (v = 0; v <= g->NumVertices - 1; v++) {
    if (!ListaAdjVazia(&v, g)) {
      Aux = PrimeiroListaAdj(v, g);
      FimListaAdj = FALSE;
      while (!FimListaAdj) {
        ProxAdj(g, &Adj, &Peso, &Aux, &FimListaAdj, c);
        InsereArestaAlt(c[Adj], c[v], &Peso, &x, GrafoT,c);
      }
    }
  }
}

void rotasAresta(Grafo *g, int indice, int tam, int tipo, char c[MAXNUMVERTICES][50], char *rota) {
  int peso, adj;
  short FimListaAdj = FALSE;
  Apontador Aux;
  Aux = g->Adj[indice].Primeiro->Prox;
  while ((Aux != NULL) && (tam > 0)) {
    if (tipo == 0) ProxAdj(g, &adj, &peso, &Aux, &FimListaAdj, c);
    else ProxAdjPed(g, &adj, &peso, &Aux, &FimListaAdj, c);
    strcat(rota, c[indice]);
    strcat(rota, " - ");
    strcat(rota, c[adj]);
    char p[10];
    sprintf(p, " (%d)", peso);
    strcat(rota, p);
    if (tam > 0) {
      strcat(rota, " -> ");
      rotasAresta(g, adj, tam-1, tipo, c, rota);
    }
    rota[strlen(rota) - ( strlen(c[indice]) + strlen(c[adj]) + strlen(p) + 3)] = '\0';
  }
  rota[strlen(rota) - 4] = '\0';
  if (tam == 0 && FimListaAdj == FALSE) printf("\n-: %s\n", rota);
}

void CidadesPerto(Grafo *g, int indice, char c[MAXNUMVERTICES][50]) {
  int i, j, dist;
  Apontador Prox = PrimeiroListaAdj(indice, g);
  short FimListaAdj;
  Apontador Aux;
  Aux = g->Adj[indice].Primeiro->Prox;
  for(i = 0; Aux != NULL; i++) {
    ProxAdj(g, &j, &dist, &Prox, &FimListaAdj, c);
    if(dist < 100)
      printf("\n - %2s (%d) ", c[j], dist);
    Aux = Aux->Prox;
  }
  for (i = 0; i < g->NumVertices; i++) {
    if (!Vazia(g->Adj[i])) {
      Aux = g->Adj[i].Primeiro->Prox;
      while (Aux != NULL) {
        if ((strcmp(Aux->Aresta.vertice, c[indice]) == 0) && (Aux->Aresta.dist < 100))
          printf("\n - %2s (%d) ", c[i], Aux->Aresta.dist);
        Aux = Aux->Prox;
      }
    }
  }
  putchar('\n');
}

int findVertice(char c[MAXNUMVERTICES][50], char s[]) {
  int i;
  for(i = 0; i < MAXNUMVERTICES; i++){
    if (strcmp(c[i], s) == 0)
     return i;
  }
  return -1;
}

/*
typedef struct TipoTempoTermino {
  TipoValorTempo t[MAXNUMVERTICES + 1];
  short Restantes[MAXNUMVERTICES + 1];
  TipoValorVertice NumRestantes;
} TipoTempoTermino;

TipoValorVertice MaxTT(TipoTempoTermino ∗TT, TipoGrafo ∗Grafo) {
  TipoValorVertice Result;
  short i = 0, Temp;
  while (!TT− > Restantes[i])
    i++;
  Temp = TT− > t[i];
  Result = i;
  for (i = 0; i <= Grafo− > NumVertices − 1; i++) {
    i f(TT− > Restantes[i]) {
      i f(Temp<TT−> t[i]) {
        Temp = TT− > t[i];
        Result = i;
      }
    }
  }
  return Result;
}

void VisitaDfs(TipoValorVertice u, TipoGrafo *Grafo, int* Tempo, int* d, int* t, int* Cor, short* Antecessor) { 
  short FimListaAdj; 
  int Peso; 
  TipoApontador Aux; 
  TipoValorVertice v; 
  Cor[u] = cinza; 
  (*Tempo)++; 
  d[u] = (*Tempo);
  printf("Visita%2d Tempo descoberta:%2d cinza\n", u, d[u]); 
  getchar();
  if(!ListaAdjVazia(&u, Grafo)) { 
    Aux = PrimeiroListaAdj(&u, Grafo);
    FimListaAdj = FALSE;
    while(!FimListaAdj){
      ProxAdj(&u, Grafo, &v, &Peso, &Aux, &FimListaAdj);
      if(Cor[v] == branco){
        printf("Aresta de %d - %d é árvore\n",u,v);
        Antecessor[v] = u;
        VisitaDfs(v, Grafo, Tempo, d, t, Cor, Antecessor);
      }
    }
  }
  Cor[u] = preto; 
  (*Tempo)++; 
  t[u] = (*Tempo);
  s[u] = (*Tempo);
  printf("Visita%2d Tempo termino:%2d preto\n", u, t[u]); 
  getchar();
} 

void BuscaEmProfundidade(TipoGrafo *Grafo){
  TipoValorVertice x; 
  int Tempo;
  int d[MAXNUMVERTICES + 1];
  int Cor[MAXNUMVERTICES+1]; 
  short Antecessor[MAXNUMVERTICES+1];
  Tempo = 0;
  for(x = 0; x <= Grafo->NumVertices - 1; x++){ 
    Cor[x] = branco; 
    Antecessor[x] = -1; 
  }
  for(x = 0; x <= Grafo->NumVertices - 1; x++){ 
    if(Cor[x] == branco)
      VisitaDfs(x, Grafo, &Tempo, d, t, Cor, Antecessor);
  }
  for(i = 0; i < 6; i++){
    printf("%d ", t[i]);
  }
}

void BuscaEmProfundidadeAlt(TipoGrafo *Grafo){
  TipoValorVertice x; 
  int Tempo;
  int i, maior = 0;
  int d[MAXNUMVERTICES + 1];
  int Cor[MAXNUMVERTICES+1]; 
  short Antecessor[MAXNUMVERTICES+1];
  Tempo = 0;
  for(x = 0; x <= Grafo->NumVertices - 1; x++){ 
    Cor[x] = branco; 
    Antecessor[x] = -1; 
  }
  for(x = 0; x <= Grafo->NumVertices - 1; x++){
    for(i = 0; i < 6; i++){
      if(t[i] > t[maior]){
        maior = i;
      }
    }
    t[maior] = 0;
    if(Cor[x] == branco)
      VisitaDfs(maior, Grafo, &Tempo, d, t, Cor, Antecessor);
  }
  for(i = 0; i < 6; i++){
    printf("%d ", s[i]);
  }
}




*/

  


