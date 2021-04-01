#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 1001

int main (){
	int qtdeLinhas, aux2;
    int linha, coluna, contador = 0;
    char comandoDireciolnal;

    scanf ("%d", &qtdeLinhas);
    char frase [max][max];
    int vetorAux[max];

    for (int i = 1; i <= qtdeLinhas; i++){
        scanf(" %[^\n]s", frase[i]);    
        vetorAux[i] = strlen(frase[i]);
    }
 

    scanf ("%d", &linha);
    scanf ("%d", &coluna);

    while (scanf ("%c", &comandoDireciolnal) != EOF){
        if (linha < qtdeLinhas && comandoDireciolnal == 'j'){
            linha++;
            if (coluna > vetorAux[linha]){
                aux2 = vetorAux[linha];
                printf ("%d %d %c\n", linha, vetorAux[linha], frase[linha][aux2-1]);
            }else
                printf ("%d %d %c\n", linha, coluna, frase[linha][coluna-1]);
        }
        else if (linha >= qtdeLinhas && comandoDireciolnal == 'j'){
            if (coluna > vetorAux[linha]){
                aux2 = vetorAux[linha];
                printf ("%d %d %c\n", linha, vetorAux[linha], frase[linha][aux2-1]);
            }else
                printf ("%d %d %c\n", linha, coluna, frase[linha][coluna-1]);        
        }
        else if (linha > 1 && comandoDireciolnal == 'k'){
            linha--;
            if (coluna > vetorAux[linha]){
                aux2 = vetorAux[linha];
                printf ("%d %d %c\n", linha, vetorAux[linha], frase[linha][aux2-1]);
            }else
                printf ("%d %d %c\n", linha, coluna, frase[linha][coluna-1]);       
        }
        else if (linha <= 1 && comandoDireciolnal == 'k'){
            if (coluna > vetorAux[linha]){
                aux2 = vetorAux[linha];
                printf ("%d %d %c\n", linha, vetorAux[linha], frase[linha][aux2-1]);
            }else
                printf ("%d %d %c\n", linha, coluna, frase[linha][coluna-1]);        
        }
    }
    return 0;
}
