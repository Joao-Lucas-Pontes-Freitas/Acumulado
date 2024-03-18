typedef struct aluno{
  int mat;
  char nome[30];
  float n1;
}Aluno;

typedef struct lista Lista;

Lista *criar();
void limpar(Lista *l);
void mostrar(Lista *l);
int tamanho(Lista *l);
int listaCheia(Lista *l);
int listaVazia(Lista *l);
int inserirInicio(Lista *l, Aluno it);
int inserirFim(Lista *l, Aluno it);
int inserirPosicao(Lista *l, Aluno it, int pos); 
int removerInicio(Lista *l);
int removerFim(Lista *l);
int removerPosicao(Lista *l, int pos); 
int removerItem(Lista *l, int it);
int buscarItemChave(Lista *l, int chave, Aluno *retorno);
int buscarPosicao(Lista *l, int posicao, Aluno *retorno);
int ContemItem(Lista *l, int it);
Lista *Reversa(Lista *l, Lista *r);
int contaItem(Lista *l, int chave);