#include <stdio.h>
#include <stdlib.h>

int main (void){

    int qtdePessoas, valorConta, i, total, soma = 0;

    scanf ("%d", &qtdePessoas);

    for (i = 0; i < qtdePessoas; i++){
        scanf ("%d", &valorConta);
        soma += valorConta;
    }

    scanf ("%d", &total);

    if (soma == total)
        printf ("Acertou\n");
    else
        printf ("Errou\n");

    return 0;
}