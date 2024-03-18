#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int troca(char v[], int t, char x);

int main()
{
    char v[20];
    char c;
    int t, q;
    printf("Digite uma palavra: ");
    fgets(v, 20, stdin);

    fflush(stdin);

    printf("\nDigite um caractere dessa palavra: ");
    scanf("%c", &c);

    t = strlen(v);

    q = troca(v, t, c);

    printf("Numero de trocas: %d", q);

    printf("\nA palavra nova eh: ");
    puts(v);

    return 0;
}

int troca(char v[], int t, char x)
{
    int i;
    int c = 0;

    for (i = 0; i < t; i++){
        if (v[i] == x){
            v[i] = '*';
            c++;
        }
    }

    return c;
}
