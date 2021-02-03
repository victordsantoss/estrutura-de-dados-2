#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 1001
#define tamHash 255

typedef struct freqChar {
    int codigo;
    int qtde;
}freqChar;

freqChar vetorResultado[tam];

int hash (int n){
    return n % tamHash;
}

void insertion_sort_codigo (freqChar *vetor_final, int n){
    int i, j;
    freqChar aux;

    for (i = 1; i < n; i++){
        aux = vetor_final[i];
        for (j = i; (j>0) && (aux.qtde<vetor_final[j-1].qtde); j--)
            vetor_final[j] = vetor_final[j-1];
        vetor_final[j] = aux;
    }
}


int main (){

    char *palavra = malloc(tam * sizeof(char));

    while (scanf("%s", palavra) != EOF){

        for (int i = 0; i < strlen(palavra); i++){
            int codigoAscii = (int)palavra[i];
            if (vetorResultado[hash(codigoAscii)].codigo != 0){
                vetorResultado[hash(codigoAscii)].qtde += 1;
            }else{
                vetorResultado[hash(codigoAscii)].codigo = codigoAscii;
                vetorResultado[hash(codigoAscii)].qtde = 1;
            }
        }
                
        insertion_sort_codigo (vetorResultado, tam);

        for (int i = 0; i < tam; i++){
            if (vetorResultado[i].codigo != 0){
                printf ("%d %d\n", vetorResultado[i].codigo, vetorResultado[i].qtde);
            }
        }

        for (int i = 0; i < tam; i++){
            vetorResultado[i].codigo = 0;
            vetorResultado[i].qtde = 0;
        }
    }   
    return 0;
}