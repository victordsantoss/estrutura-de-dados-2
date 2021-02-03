#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

clock_t begin;
void start() { begin = clock(); }
void end() { printf("\nTime elpased is %f seconds\n", (double)(clock()-begin)/CLOCKS_PER_SEC); }

typedef long long ll;
typedef struct Seed { ll id, score; } Seed;

Seed xs1[10005000];
ll N1=0;

Seed xs2[10005000];
ll N2=0;

ll parent(ll i) { return i/2LL; }
ll left(ll i) { return 2LL*i; }
ll right(ll i) { return 2LL*i + 1LL; }

void swap(Seed* a, Seed* b) { Seed temp = *b; *b = *a; *a = temp; }

void insert(Seed x) {

    // printf("inserting => %lld %lld\n", x.id, x.score);

    xs1[N1 + 1] = x;

    ll i = N1 + 1;
    ll p = parent(i);

    while ( p &&
        ( (xs1[i].score <  xs1[p].score) || 
          (xs1[i].score == xs1[p].score && xs1[i].id < xs1[p].id)
        )
    )
    {
        swap(&xs1[p], &xs1[i]);
        i = p;
        p = parent(i);
    }

    ++N1;

    // printf("top => %lld %lld\n\n", xs1[1].id, xs1[1].score);
}

void insert2(Seed x) {
    xs2[N2 + 1] = x;

    ll i = N2 + 1;
    ll p = parent(i);

    while ( p && xs2[p].id > xs2[i].id )
    {
        swap(&xs2[p], &xs2[i]);
        i = p;
        p = parent(i);
    }

    ++N2;
}

bool empty() { return N1 == 0; }

Seed pop()
{
    Seed x = xs1[1];
    swap(&xs1[1], &xs1[N1]);

    --N1;

    ll i = 1;
    ll n = left(i) > N1 ? 0 : left(i);

    while (n)
    {
        ll r = right(i) > N1 ? 0 : right(i);

        if ( 
            r && (
                (xs1[r].score < xs1[n].score) || 
                (xs1[r].score == xs1[n].score && xs1[r].id < xs1[n].id)
            )
        ) {
            n = r;
        }

        if (
            (xs1[n].score <  xs1[i].score) || 
            (xs1[n].score == xs1[i].score && xs1[n].id < xs1[i].id)
        ) {
            swap(&xs1[i], &xs1[n]);
            i = n;
            n = left(i) > N1 ? 0 : left(i);
        } else n = 0;
    }

    return x;
}

Seed pop2()
{
    Seed x = xs2[1];
    swap(&xs2[1], &xs2[N2]);

    --N2;

    ll i = 1;
    ll n = left(i) > N2 ? 0 : left(i);

    while (n)
    {
        ll r = right(i) > N2 ? 0 : right(i);

        if ( r && xs2[r].id < xs2[n].id ) { 
            n = r;
        }

        if ( xs2[i].id > xs2[n].id ) {
            swap(&xs2[i], &xs2[n]);
            i = n;
            n = left(i) > N2 ? 0 : left(i);
        } 

        else n = 0;
    }

    return x;
}

int compare2(const void*a, const void*b) {
    Seed x = *((Seed*) a);
    Seed y = *((Seed*) b);
    return x.id < y.id ? -1 : 1;
}

int main()
{
    // start();

    ll Q;
    scanf("%lld", &Q);

    Seed s;
    while(scanf("%lld %lld", &s.id, &s.score) == 2) {
        insert(s);
    }

    Q = (Q < N1 ? Q : N1);

    for(ll i=0; i<Q; i++) {
        xs2[i] = pop();
        // Seed d = pop();
        // printf("%lld %lld\n", d.id, d.score);
        // insert2(d);
    }

    qsort(xs2, Q, sizeof(Seed), compare2);

    for(ll i=0; i<Q; i++) {
        printf("%lld %lld\n", xs2[i].id, xs2[i].score);
    }

    // while(Q--) {
    //     Seed d = pop2();
    //     printf("%lld %lld\n", d.id, d.score);
    // }

    // end();

    return 0;
}