#define MAX 100

typedef struct fila Fila;

typedef struct paciente {
  char *nome;
} Paciente;

Fila *criar();
void limpar(Fila *f);
int inserir(Fila *f, Paciente it);
int remover(Fila *f);
int tamanho(Fila *f);
int filaVazia(Fila *f);
int filaCheia(Fila *f);
void mostrar(Fila *f);

