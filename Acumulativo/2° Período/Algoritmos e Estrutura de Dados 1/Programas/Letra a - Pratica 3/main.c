#include <stdio.h>
#include <stdlib.h>

int soma (int x);

int main()
{
    int x , s;
    printf("Digite um numero:");
    scanf("%d", &x);
    s = soma(x);
    printf("\nSoma com seus antecessores maiores que 0: %d\n", s);
    return 0;
}

int soma (int x)
{
    int s = x;
    int i, y = 0;
    for (i = s; i > 0; i--){
        y = y + i;
    }

    return y;
}
