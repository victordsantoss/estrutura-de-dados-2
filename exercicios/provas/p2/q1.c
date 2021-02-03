#include <stdio.h>
#include <stdlib.h>

int main (){

    int numRestaurantes, maior = 0;
    int k, dia = 1, i;

    while(scanf("%d", &numRestaurantes) != EOF){
        int *codigo = malloc(numRestaurantes * sizeof(int));
        int *nota = malloc(numRestaurantes * sizeof(int));

        for (i = 0; i < numRestaurantes;i++){
            scanf("%d", &codigo[i]);
            scanf("%d", &nota[i]);

            if (nota[i] > maior){
                maior = nota[i];
                k = i;
            // Verificação do menor código
            }else if (nota[i] == maior){
                // Compara o código da maior nota anterior com a nota atual
                if (codigo[k] > codigo[i]){
                    k = i;
                }
            }
        }

        printf ("Dia %d\n", dia);
        printf ("%d\n", codigo[k]);
        printf ("\n");
        dia ++;
        maior = 0;
        k = 0;
    }
    return 0;
}