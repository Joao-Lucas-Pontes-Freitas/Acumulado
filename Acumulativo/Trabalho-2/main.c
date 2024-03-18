#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Grafos.h"

char cidades[MAXNUMVERTICES][50];
int indice = 0;

int main() {  
  char origem[50];
  int i, j, k = 0, correspondentes;
  Grafo g = FGVazio();
  Grafo t = FGVazio();
  Apontador Prox;
  short FimListaAdj;

  FILE *arq1 = fopen("grafo.txt", "r");
  if(arq1 == NULL)
    printf("Erro na abertura do arquivo\n");
  
  i = 0;
  Aresta x;  
  while(fscanf(arq1,"%[^ ] %[^ ] %d %d\n", origem, x.vertice, &x.dist, &x.pedagio) != EOF) {
    // CIDADE DE ORIGEM
    for (j = 0; j < indice; j++)
      if (strcmp(cidades[j], origem) == 0)
        break; 
    if (j == indice) 
      strcpy(cidades[indice++], origem);
    // CIDADE DESTINO
    for (j = 0; j < indice; j++)
      if ((strcmp(cidades[j], x.vertice) == 0))
        break; 
    if (j == indice)
      strcpy(cidades[indice++], x.vertice);

    // COLOCAR CIDADE NO GRAFO
    for (j = 0; j < indice; j++)
      if (strcmp(cidades[j], origem) == 0)
        break;
    Insere(&x, &g.Adj[j]);
    
    i++;  
    g.NumArestas++;
  }
  g.NumVertices = indice;   

  char sp[] = "São-Paulo-SP";
  char str[50];
   printf("Digite o vértice: ");
   scanf("%s", str);
   printf("\nCidades a menos de 100km de %s: ", str);
   if ((correspondentes = findVertice(cidades, str)) != -1)
     CidadesPerto(&g, correspondentes, cidades);  

  char rota[MAXNUMVERTICES * 50];
  memset(rota, 0, sizeof(rota));
  rotasAresta(&g, findVertice(cidades, sp), 3, 0, cidades, rota);
  // ImprimeGrafo(&g, cidades);
   //GrafoTransposto(&t, &g, cidades);
  // printf("\n\n\n");
  // ImprimeGrafo(&t, cidades);

  
  /*
  
  
  
  
  
  
  
  
  
  */
//   Apontador Aux;
//   long i;
//   int NArestas, Peso, NVertices, V1, V2, Adj;
//   short FimListaAdj;
//   Grafo GrafoN, GrafoT;  

//   printf("No. vertices:");
//   scanf("%d%*[^\n]", &NVertices);
//   getchar();
//   printf("No. arestas:");
//   scanf("%d%*[^\n]", &NArestas);
//   getchar();
//   GrafoN.NumVertices = NVertices;
//   GrafoN.NumArestas = 0;
//   FGVazio(&GrafoN);
  
//   for (i = 0; i < NArestas; i++) {
//     printf("Insere V1 -- V2 -- Peso:");
//     scanf("%d%d%d%*[^\n]", &V1, &V2, &Peso);
//     getchar();
//     GrafoN.NumArestas++;
//     InsereAresta(&V1, &V2, &Peso, &GrafoN); /* 1 chamada g-direcionado    */
//     /*InsereAresta(V2, V1, Peso, Grafo);*/

//     /* 2 chamadas g-naodirecionado*/
//   }

//   ImprimeGrafo(&GrafoN);
//   scanf("%*[^\n]");
//   getchar();
  
//   printf("Grafo transposto:\n");
//   GrafoTransposto(&GrafoN, &GrafoT);
//   ImprimeGrafo(&GrafoT);
  
//   scanf("%*[^\n]");
//   getchar();
  
//   printf("Insere V1 -- V2 -- Peso:");  
//   scanf("%d%d%d%*[^\n]", &V1, &V2, &Peso);  
//   if (ExisteAresta(V1, V2, &GrafoN))
//     printf("Aresta ja existe\n");
//   else {
//     GrafoN.NumArestas++;
//     InsereAresta(&V1, &V2, &Peso, &GrafoN);
//     /*InsereAresta(V2, V1, Peso, Grafo);*/
//   }

//   ImprimeGrafo(&GrafoN);
//   scanf("%*[^\n]");
//   getchar();
  
//   printf("Lista adjacentes de: ");
//   scanf("%d*[^\n]", &V1);
//   if (!ListaAdjVazia(&V1, &GrafoN)) {
//     Aux = PrimeiroListaAdj(&V1, &GrafoN);
//     FimListaAdj = FALSE;
//     while (!FimListaAdj) {
//       ProxAdj(&V1, &GrafoN, &Adj, &Peso, &Aux, &FimListaAdj);
//       printf("%2d (%d)", Adj, Peso);
//     }
//     putchar('\n');
//     scanf("%*[^\n]");
//     getchar();
//   }

//   printf("Retira aresta V1 -- V2:");
//   scanf("%d %d", &V1, &V2);
//   if (ExisteAresta(V1, V2, &GrafoN)) {
//     GrafoN.NumArestas--;
//     RetiraAresta(&V1, &V2, &Peso, &GrafoN);
//     /*RetiraAresta(V2, V1, Peso, Grafo);*/
//   } else
//     printf("Aresta nao existe\n");
  
//   ImprimeGrafo(&GrafoN);
//   scanf("%*[^\n]");
//   getchar();

//   printf("Existe aresta V1 -- V2:");
//   scanf("%d*[^\n]", &V1);
//   scanf("%d*[^\n]", &V2);
//   getchar();

//   if (ExisteAresta(V1, V2, &GrafoN))
//     printf(" Sim\n");
//   else
//     printf(" Nao\n");
//   LiberaGrafo(&GrafoN); /* Imprime sujeira normalmente */
//   ImprimeGrafo(&GrafoN);

  return 0;
}

// /*
// Exemplo de entrada:

// 6
// 7
// 0 1 3
// 0 3 1
// 1 4 1
// 4 3 2
// 3 1 5
// 2 4 4
// 2 5 1

// */