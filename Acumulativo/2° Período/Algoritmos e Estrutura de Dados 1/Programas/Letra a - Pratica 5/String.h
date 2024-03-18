typedef struct string String;
String *criar(int t);
int tamanho(String *s);
int contador(String *s, char a, int t);
int vogais(String *s, int t);
void concatenar(String *s1, String *s2, int *t1, int t2);
void mostrar(String *s);
void destruir(String *s);
