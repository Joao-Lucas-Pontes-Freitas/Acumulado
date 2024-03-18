#define MAX 100
/*typedef struct aluno{
  int mat;
  char nome[30];
  float n1;
} Aluno;*/

typedef struct pilha Pilha;

/*LETRA A

Pilha *criar(); void limpar(Pilha *p);
int push(Pilha *p, int it);
int pop(Pilha *p, int *it);
int consultar(Pilha *p, int *it);
int tamanho(Pilha *p);
int pilhaVazia(Pilha *p);
int pilhaCheia(Pilha *p);
void mostrar(Pilha *p);*/


/* LETRA B e C*/



Pilha *criar(); void limpar(Pilha *p);
int push(Pilha *p, char it);
int pop(Pilha *p, char *it);
int consultar(Pilha *p, char *it);
int tamanho(Pilha *p);
int pilhaVazia(Pilha *p);
int pilhaCheia(Pilha *p);
void mostrar(Pilha *p);
int palindromo(char *it);
int validar(char *it);
