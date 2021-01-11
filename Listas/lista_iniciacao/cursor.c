#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 1001

int main (){
    int qtdeLinhas, aux2;
    int linha, coluna;
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
/* 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam_max 1001

int main (){
    int qtde_linhas, linha, coluna, tamanho_frase[tam_max], aux;
    char frase[tam_max][tam_max], comando_direcional; 
    
    scanf ("%d", &qtde_linhas);

    for (int i = 1; i <= qtde_linhas; i++){
        scanf (" %[^\n]s", frase[i]);
        tamanho_frase[i] = strlen(frase[i]);
    }
    scanf ("%d", &linha);
    scanf ("%d", &coluna);

    while (scanf ("%c", &comando_direcional) != EOF){
        if (comando_direcional == 'j' && linha < qtde_linhas){
            linha ++;
            aux = tamanho_frase[linha];
            if (coluna > tamanho_frase[linha]) printf ("%d %d %c\n", linha, tamanho_frase[linha], frase[linha][aux-1]);
            else printf ("%d %d %c\n", linha, coluna, frase[linha][coluna-1]);
        }
        else if (comando_direcional == 'j' && linha >= qtde_linhas){
            aux = tamanho_frase[linha];
            if (coluna > tamanho_frase[linha]) printf ("%d %d %c\n", linha, tamanho_frase[linha], frase[linha][aux-1]);
            else printf ("%d %d %c\n", linha, coluna, tamanho_frase[coluna-1]);
        }
        else if (comando_direcional == 'k' && linha > 1){
            linha --;
            aux = tamanho_frase[linha];
            if (coluna > tamanho_frase[linha]) printf ("%d %d %c\n", linha, tamanho_frase[linha], frase[linha][aux-1]);
            else printf ("%d %d %c\n", linha, coluna, frase[linha][coluna-1]);
        }
        else if (comando_direcional == 'k' && linha <= 1){
            aux = tamanho_frase[linha];
            if (coluna > tamanho_frase[linha]) printf ("%d %d %c\n", linha, tamanho_frase[linha], frase[linha][aux-1]);
            else printf ("%d %d %c\n", linha, coluna, frase[linha][coluna-1]);
        }  
    }
    return 0;
}*/
