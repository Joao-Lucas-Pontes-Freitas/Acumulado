#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int divisao (int *a, int *b);

int main()
{
    int a, b;

    printf("Digite dividendo e divisor, respectivamente: ");
    scanf("%d %d", &a, &b);

    if (divisao(&a, &b) == -1)
        return -1;

    printf("\nQuociente: %d \t Resto: %d", a, b);

    return 0;
}

int divisao (int *a, int *b)
{
    int temp = *a;
    int x, y;

    x = fabs(*a);
    y = fabs(*b);

    if ((y > x && x != 0) || *b == 0)
        return -1;

    *a = (*a)/(*b);
    *b = temp%(*b);

    return 0;
}
