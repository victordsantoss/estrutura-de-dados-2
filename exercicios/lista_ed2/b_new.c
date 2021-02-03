#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t begin = clock();

typedef unsigned long long ull;
typedef long long ll;
typedef struct Seed { ll id, score; } Seed;

Seed array[10000000];

int compare1(const void*a, const void*b)
{
    Seed x = *((Seed*) a);
    Seed y = *((Seed*) b);

    if(x.score != y.score) {
        return x.score < y.score ? -1 : 1;
    }
    
    return x.id < y.id ? -1 : 1;
}

int compare2(const void*a, const void*b)
{
    Seed x = *((Seed*) a);
    Seed y = *((Seed*) b);
    return x.id < y.id ? -1 : 1;
}


int main()
{
	ll k;
    // scanf("%lld", &k);

    // ll id, score, T=0;
    // while (scanf("%lld %lld", &array[T].id, &array[T].score) == 2) ++T;

    // k = (k < T ? k : T);

    // qsort(array, T, sizeof(Seed), compare1);
    // qsort(array, k, sizeof(Seed), compare2);

    // for(ll i=0; i<k; ++i){
    //     printf("%lld %lld\n", array[i].id, array[i].score);
    // }


    // clock_t end = clock();
    // double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    // printf("\nTime elpased is %f seconds\n", time_spent);

    return 0;
}

