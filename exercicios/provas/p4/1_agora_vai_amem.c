#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

#define tamMax 1048577
        
typedef struct mensagem{
    ll codigo;
    char caractere;
} mensagem;

ll hash (ll n);
mensagem *init (ll tam);

ll main (){

    ll codigo, maior = -1, contador = 0, menor =  __LONG_LONG_MAX__;
    char caractere;
    mensagem *vetorMensagem = init (tamMax);

    while (scanf (" %lld", &codigo) != EOF){
        vetorMensagem[hash(codigo)].codigo = codigo;
        scanf (" %c", &caractere);
        vetorMensagem[hash(codigo)].caractere = caractere;
        if (codigo > maior)
            maior = codigo;
        if (codigo < menor)
            menor = codigo;
    }

    for (ll i = menor; i <= maior; i++){
        printf ("%c", vetorMensagem[hash(i)].caractere);
    }
    printf ("\n");

    free (vetorMensagem);

    return 0;
}

mensagem *init (ll tam){

    ll i;
    mensagem *m = malloc (tamMax * sizeof (mensagem));

    for (i = 0; i < tam; i++){
        m[i].caractere = ' ';
        m[i].codigo = -1;
    }
    return m;
}

ll hash (ll n){
    return n % tamMax;
}
