#include <stdio.h>
#include <stdlib.h>

float taylor (int x, int y);
float fatorial (int x);
float potencia (int x, int y);

int main()
{
    int x, y;
    float t;

    printf("Digite, respectivamente, uma base e um expoente: ");
    scanf("%d %d", &x, &y);

    t = taylor(x, y);

    printf("\nSerie de Taylor: %.4f", t);

    return 0;
}

float potencia (int x, int y)
{
    int b = x;
    int e = y, i;
    float p = 1;

    for (i = 0; i < e; i++){
        p = p*b;
    }

    return p;
}

float fatorial (int x)
{
    int i = x;
    int f = 1;

    for (i = i; i > 0; i--)
        f = f*i;

    return f;
}

float taylor (int x, int y)
{
    int i = y;
    float p, f, t = 0;

    for (i = i; i > -1; i--){
        p = potencia(x,i);
        f = fatorial (i);
        t = t + (p/f);
    }

    return t;
}
