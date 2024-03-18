#include <stdio.h>
#include <stdlib.h>

#define MAXNUMVERTICES 100
#define FALSE 0
#define TRUE 1

typedef struct vertc{
  char nome[50];
}Vertc;
typedef struct Celula *Apontador;

// typedef struct Aresta {
//   int Vertice;
//   int Peso;
// } Aresta;
typedef struct aresta {
  char vertice[50];
  int dist;
  int pedagio;
  int ordem;
} Aresta;

typedef struct Celula {
  Aresta Aresta;
  Apontador Prox;
} Celula;

typedef struct Lista {
  Apontador Primeiro, Ultimo;
} Lista;

typedef struct Grafo {
    Lista Adj[MAXNUMVERTICES];
    int NumVertices;
    int NumArestas;
} Grafo;

/* TESTE ARESTAS */


/*--Entram aqui os operadores do Programa 2.4--*/
void FLVazia(Lista *Lista);
short Vazia(Lista Lista);
void Insere(Aresta *x, Lista *Lista);

/*-- Fim operadores do Programa 2.4 --*/
Grafo FGVazio();
void InsereAresta(int *V1, int *V2, int *Peso, Grafo *g);
short ExisteAresta(int Vertice1, int Vertice2, Grafo *g);

/* Operadores para obter a lista de adjacentes */
short ListaAdjVazia(int *Vertice, Grafo *g);
Apontador PrimeiroListaAdj(int Vertice, Grafo *g);
void ProxAdj(Grafo *g, int *Adj, int *dist, Apontador *Prox, short *FimListaAdj, char c[MAXNUMVERTICES][50]);
void ProxAdjPed(Grafo *g, int *Adj, int *ped, Apontador *Prox, short *FimListaAdj, char c[MAXNUMVERTICES][50]);
void Retira(Apontador p, Lista *Lista, Aresta *Aresta);
void RetiraAresta(int *V1, int *V2, int *Peso, Grafo *g);
void LiberaGrafo(Grafo *g);
void ImprimeGrafo(Grafo *g,  char c[MAXNUMVERTICES][50]);
void ImprimeLista(Lista Lista);
void GrafoTransposto(Grafo *GrafoT, Grafo *g, char c[MAXNUMVERTICES][50]);
void GrafoTranspostoAlt(Grafo *GrafoT, Grafo *g);
void BuscaEmProfundidade(Grafo *Grafo, char c[MAXNUMVERTICES][50]);
void VisitaDfs(int u, Grafo *Grafo, int* Tempo, int* d, int* t, int* Cor, short* Antecessor, char c[MAXNUMVERTICES][50]);
int findVertice(char c[MAXNUMVERTICES][50], char s[]);
/* Questão B */
void rotasAresta(Grafo *g, int indice, int arestas, int tipo, char c[MAXNUMVERTICES][50], char *rota);


/* Questão C */
void CidadesPerto(Grafo *grafo, int indice, char c[MAXNUMVERTICES][50]);




