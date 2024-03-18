#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Produto
#define MAX 30
typedef struct {
  float preco;   
  int codigo;    
  char descricao[MAX]; 
} Produto;

void quickSortBasico(int v[], int n);
void qbSort(int v[], int esq, int dir);
//
void quickSortBasicoInteiro(Produto p[], int n);
void qbSortInteiro (Produto p[], int esq, int dir);
void quickSortBasicoReal(Produto p[], int n);
void qbSortReal (Produto p[], int esq, int dir);
void quickSortBasicoChar(Produto p[], int n);
void qbSortChar (Produto p[], int esq, int dir);

void quickSortMedianaAleatorio(int p[], int esq, int dir);
int particaoAleatoria1(int p[], int esq, int dir);
int particaoAleatoria2(int p[], int esq, int dir);
//
void quickSortMedianaAleatorioInteiro(Produto p[], int esq, int dir);
int particaoAleatoria1Inteiro(Produto p[], int esq, int dir);
int particaoAleatoria2Inteiro(Produto p[], int esq, int dir);
void quickSortMedianaAleatorioReal(Produto p[], int esq, int dir);
int particaoAleatoria1Real(Produto p[], int esq, int dir);
int particaoAleatoria2Real(Produto p[], int esq, int dir);
void quickSortMedianaAleatorioChar(Produto p[], int esq, int dir);
int particaoAleatoria1Char(Produto p[], int esq, int dir);
int particaoAleatoria2Char(Produto p[], int esq, int dir);

void insertionSort (int vet[], int n);
//
void insertionSortReal (Produto vet[], int n);
void insertionSortInteiro (Produto vet[], int n);
void insertionSortChar (Produto vet[], int n);

void criaHeap(int v[], int i, int f);
void heapSort(int v[], int N);
//
void criaHeapInteiro(Produto p[], int i, int f);
void heapSortInteiro(Produto p[], int N);
void criaHeapReal(Produto vet[], int i, int f);
void heapSortReal(Produto p[], int N);
void criaHeapChar(Produto vet[], int i, int f);
void heapSortChar(Produto p[], int N);

void bucketSortInteiro (Produto p[], int N);

void cocktailSort(int v[], int n);
//
void cocktailSortInteiro(Produto p[], int n);
void cocktailSortReal(Produto p[], int n);
void cocktailSortChar(Produto p[], int n);

void pancakeSort(int arr[], int n);
int findMax(int p[], int n);
void flip(int p[], int i);
//
void pancakeSortInteiro(Produto arr[], int n);
int findMaxInteiro(Produto p[], int n);
void flipInteiro(Produto p[], int i);
void pancakeSortReal(Produto arr[], int n);
int findMaxReal(Produto p[], int n);
void flipReal(Produto p[], int i);
void pancakeSortChar(Produto arr[], int n);
int findMaxChar(Produto arr[], int n);
void flipChar(Produto arr[], int i);


//FUNÇÕES ADICIONAIS
int particao (int p[], int esq, int dir);
int particaoInteiro (Produto p[], int esq, int dir);
int particaoReal (Produto p[], int esq, int dir);
int particaoChar (Produto p[], int esq, int dir);

void troca (int p[], int i, int j);
void trocaInteiro (Produto p[], int i, int j);
void trocaReal (Produto p[], int i, int j);
void trocaChar (Produto p[], int i, int j);

void mostraVetorInt(int vet[], int tam);
void mostraVetorInteiro(Produto vet[], int tam);
void mostraVetorReal(Produto vet[], int tam);
void copiaVetorInteiro(Produto copia[], Produto p[], int tam);
void criarVetorInteiro(int v[], int t, int qtd);
void vetorInt(int v[], int tam, int qtd);
void vetorInteiro(Produto p[], int tam, int qtd);
void vetorReal(Produto p[], int tam, int qtd);
void vetorChar(Produto p[], int tam, int qtd);
void transformar(int vet[], Produto p[]);
