#include <stdio.h>
#include <stdlib.h>

int main (){

    int valor, contador = 0;

    while (scanf("%d", &valor) != EOF) contador += 1;
    printf ("%d\n", contador);

    return 0;
}