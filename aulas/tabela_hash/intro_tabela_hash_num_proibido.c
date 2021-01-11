#include <stdio.h>
#include <stdlib.h>

#define tam 262139

char v[tam];

int hash (int n);

int main (){

    int n;

    scanf ("%d", &n);

    for (int i = 0; i < n; i++){
        int t;
        scanf ("%d", &t);
        v[hash(t)] = t;
    }

    int c;

    while (scanf ("%d", &c) == 1){
        int t = hash(c);

        if (v[t] == c)
            printf ("proibido\n");
        else if (v[t] ==  0)
            printf ("nao\n");
        else if (v[t] != c)
            printf ("colisao na tabela\n");
    }
    return 0;
}

int hash (int n){
    return n % tam;
}
