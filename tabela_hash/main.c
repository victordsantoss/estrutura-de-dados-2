#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabelaHash.h"

int main (){

    Hash* ha = criaHash(262139);

    struct aluno al;

    al.matricula = 1234; 
    al.n1  = 5;
    al.n2 = 10;
    al.n3 = 7;

    int x = insereHash_semColisao (ha, al);

    if (buscaHash_semColisao(ha, al.matricula, &al))
        printf (" ----- Encontrado\n");
    else
        printf(" ----- Nao Encontrado\n");   

    al.matricula = 125;  
    al.n1  = 5;
    al.n2 = 10;
    al.n3 = 7; 

    x = insereHash_EnderAberto (ha, al);

    if (buscaHash_EnderAberto(ha, al.matricula, &al))
        printf (" ----- Encontrado\n ");
    else
        printf(" ----- Nao Encontrado\n"); 
    
    if (buscaHash_EnderAberto(ha, 752, &al))
        printf (" ----- Encontrado\n ");
    else
        printf(" ----- Nao Encontrado\n"); 

    return 0;
}
