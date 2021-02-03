#include <stdio.h>
#include <stdlib.h>

int main (){

    int num, contador = 0;

    while (scanf ("%d", &num) != EOF)
        contador++;

    printf ("%d\n", contador);
    
    return 0;
}