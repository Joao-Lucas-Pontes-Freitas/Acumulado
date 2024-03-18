#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h> //__fpurge

int fatorial(int *p, int n, int f[n]){
  int i;
  if(f[n] != 0)
    return f[n];
  for(i = *p; i <= n; i++){
    f[i] = i * f[i-1];
  }
  *p = n;
  return f[n];
}

int main(void) {
  int n;
  int p = 1;
  int f[100] = {0};
  f[0] = 1;
  char c;
  while(c != 's'){
    printf("\nDigite o valor de N: ");
    scanf("%d",&n);
    printf("O fatorial de %d vale: %d\n", n, fatorial(&p, n, f));
    printf("\nDeseja encerrar? ");
    fflush(stdin); // __fpurge
    scanf("%c", &c);
  }
  
  return 0;
}