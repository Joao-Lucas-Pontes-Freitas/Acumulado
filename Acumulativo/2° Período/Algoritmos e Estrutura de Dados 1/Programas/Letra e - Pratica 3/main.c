#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calculaHexagono(float l, float *area, float *perimetro);

int main()
{
    float l;
    float area;
    float perimetro;

    printf("Digite a medida do lado do hexagono: ");
    scanf("%f", &l);

    calculaHexagono(l, &area, &perimetro);

    printf("\nA area do hexano regular de lado %.3f eh: %.3f\nO perimetro do hexano regular de lado %.3f eh: %.3f\n", l, area, l, perimetro);

    return 0;
}

void calculaHexagono(float l, float *area, float *perimetro)
{
    float x = l;
    float r = sqrt(3);
    *perimetro = 6*x;
    *area = 3*x*x*r/2;

}
