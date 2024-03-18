#include <stdio.h>
#include <stdlib.h>

int potencia (int x, int y);
int main()
{
    int x, y, t;

    printf("Digite, respectivamente, uma base e um expoente: ");
    scanf("%d %d", &x, &y);

    t = potencia(x, y);

    printf("\nTotal: %d", t);

    return 0;
}

int potencia (int x, int y)
{
    int b = x;
    int e = y;
    int i, t = 1;

    for (i = 0; i < e; i++){
        t = t*b;
    }

    return t;
}
