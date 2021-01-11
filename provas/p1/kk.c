#include <stdio.h>
#include <stdlib.h>

typedef int item;
#define key(a) (a)
#define less(a,b) (key(a) < key(b))
#define exch(a,b) {item t = a; a = b; b = t;}
#define cmpexch(a,b) {if (less(b,a)) exch(a,b);}

int separa (item *v, int l, int r);
void quick_select (item *v, int l, int r, int k);
void quick_sort (item *v, int l, int r);

int main (){

    int n, qtde_itens;
    int p;
    int codigo;

    scanf("%d", &n);
    scanf("%d", &p);
    scanf("%d", &qtde_itens);

    item *v = malloc (n * sizeof(int));
    
    for(int i = 0; i < n; i++){
        scanf("%d", &codigo);
        v[i] = codigo;
    }

    int aux = p * qtde_itens;

    quick_select (v, 0, n-1, aux);

    int cont = aux + qtde_itens - 1;
        
    while (cont > aux){
        if (cont < n){
            quick_select (v, aux, n-1, cont);
            break;
        }else
            cont--;
    }

    quick_sort (v, aux, cont);
        
    for (int i = aux; i <= cont; i++)
            printf("%d\n", v[i]);
    
    return 0;
}

int separa (item *v, int l, int r){

    int pivo = v[r];
    int j = l;

    for (int k = l; k < r; k++)
        if (less(v[k], pivo)){
            exch (v[k], v[j]);
            j++;
        }
        exch (v[j], v[r]);

    return j;
} 

void quick_select (item *v, int l, int r, int k){

    int i;

    if (r <= l)
        return;

    i = separa (v, l, r);

    if (i > k)
        quick_select (v, l, i-1, k);
    if (i < k)
        quick_select (v, i+1, r, k);

}

void quick_sort (item *v, int l, int r){
    
    int j;

    if (r <= l) return;

    exch (v[(l+r)/2], v[r-1]);
    cmpexch (v[l], v[r-1]);
    cmpexch (v[l], v[r]);
    cmpexch (v[r-1], v[r]);

    j = separa (v, l+1, r-1); 
    quick_sort (v, l, j-1);
    quick_sort (v, j+1, r);
}
