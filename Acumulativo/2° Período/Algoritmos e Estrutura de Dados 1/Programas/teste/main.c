#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h, m, s, d, x, y;

    scanf("%d %d %d %d", &h, &m, &s, &d);


    x = (s+d)%60;
    y = (m + (s+d)/60)%60;
    h = h + (m+(s+d)/60)/60;

    printf("h:%d m:%d s:%d", h, y, x);

    return 0;
}
