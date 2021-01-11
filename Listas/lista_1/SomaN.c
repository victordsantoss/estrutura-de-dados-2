#include <stdio.h>

int main (){

    int numLinhas, num, soma = 0;

    scanf ("%d", &numLinhas);

    while (numLinhas > 0){
        scanf ("%d", &num);
        soma += num;
        numLinhas--;
    }
    printf ("%d\n", soma);
    
    return 0;
}