#include <stdio.h>
#include <stdlib.h>

#define tam 10000013

int hash (int n);

int main (){

    int n;
    int maior = 0;

    scanf ("%d", &n);
    while (n != 0){
        int *v = malloc (tam * sizeof(int));
        int *r = malloc (tam * sizeof(int));

        for (int i = 0; i < n; i++){
            int t;
            scanf ("%d", &t);
        
            if (v[hash(t)] != 0){
                r[hash(t)] = r[hash(t)] + 1;
                if (maior < r[hash(t)]){
                    maior = v[hash(t)];
                }
            }else{
                v[hash(t)] = t;
                r[hash(t)] = r[hash(t)] + 1;
            }
        }
        printf ("%d\n", maior);
        free(v);
        free(r);
        maior = 0;
        scanf ("%d", &n);
    }
    return 0;
}

int hash (int n){
    return n % tam;
}
