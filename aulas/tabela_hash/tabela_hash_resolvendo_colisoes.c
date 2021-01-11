#include <stdio.h>
#include <stdlib.h>

#define hash(v, m) (v % m) // ok para m primo
#define hash(v, m) ((16161 * (unsigned) v) % m)

int hash_u (char *v, int m);

typedef struct item{
    int chave;
    long e1, e2;
    long elemento;
}item;

item nullitem = {0,0,0,0};

#define key(x) (x.chave)
#define less(a,b) (key(a) < key(b))
#define null_a(A) (key([A]) == key(nullitem))

static int n, m;
static item *ht;

void htinit (int max){

    int i;
    n = 0;
    m = 2 * max;
    ht = malloc(sizeof(item) * m);

    for (i = 0; i < m; i++)
        ht[i] = nullitem;

}

int htcount (){
    return n;
}

void htinsert (item item){

    int v = key(item);
    int i = hash (v, m);

    while (!null(i))
        i = (i+1)%m;

    ht[i] = item;
    n++;
}

item htsearch (int v){
    int i = hash (v, m);

    while (!null(i)){
        if (eq(v, key(ht[i])))
            return st[i];
        else 
            i = (i+1) % m;       
    }

    return nullitem;
}

// Tabela hash universal com string
int hash_u (char *v, int m){

    int h, a = 31415, b = 27183;

    for (h = 0; *v != '\0'; v++){
        a = a * b % (m-1);
        h = (a * h + *v) % m;
    }
    return h;

}

