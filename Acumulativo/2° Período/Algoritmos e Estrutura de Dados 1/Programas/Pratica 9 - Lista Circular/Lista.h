typedef struct aluno{
int mat;
char nome[30];
float n1;
}Aluno;

typedef struct lista Lista;

Lista *criar();
void limpar(Lista *l);
int inserirInicio(Lista *l, Aluno it);
int inserirFim(Lista *l, Aluno it);
int inserirPosicao(Lista *l, Aluno it, int pos);
int removerInicio(Lista *l);
int removerFim(Lista *l);
int removerPosicao(Lista *l, int pos);
int removerItem(Lista *l, int it);
int buscarItemChave(Lista *l, int chave, Aluno *retorno);
int buscarPosicao(Lista *l, int posicao, Aluno *retorno);
int listaVazia(Lista *l);
int listaCheia(Lista *l);
int tamanho(Lista *l);
void mostrar(Lista *l);
int TiraMeio(Lista *l);
int ContaElementos(Lista *l, Aluno it);
int MaisAparece(Lista *l);
int SepararListas(Lista *l1, Lista *l2, Lista *l3, float nota);
int RemoverAparicao(Lista *l, int it);
int Interseccao(Lista *l1, Lista *l2, Lista *l3);
int Produto(Lista *l1, Lista *l2, Lista *l3);
