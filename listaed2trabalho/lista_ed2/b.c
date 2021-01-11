#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;
typedef long long ll;

typedef struct Seed { ll id; ll score; } Seed;

ll size = 0;
ll size2 = 0;

Seed array[10000005];
Seed array2[10000005];

void swap(Seed* a, Seed* b) { Seed temp = *b; *b = *a; *a = temp; }

void heapify(ll i)
{
    if (size == 1ULL) return;

    ll largest = i;
    ll l = 2LL * i + 1LL;
    ll r = 2LL * i + 2LL;

    if (l < size && array[l].score >= array[largest].score)
    {
        if(array[l].score == array[largest].score) {
            largest = (array[l].id > array[largest].id ? l : largest);
        }

        else { largest = l; }
    }

    if (r < size && array[r].score >= array[largest].score)
    {
        if(array[r].score == array[largest].score) {
            largest = (array[r].id > array[largest].id ? r : largest);
        }

        else { largest = r; }
    }

    if (largest != i) {
        swap(&array[i], &array[largest]);
        heapify(largest);
    }
}

void heapify2(ll i)
{
    if (size2 == 1ULL) return;

    ll largest = i;
    ll l = 2LL * i + 1LL;
    ll r = 2LL * i + 2LL;

    if (l < size2 && array2[l].id > array2[largest].id) {
        largest = l;
    }

    if (r < size2 && array2[r].id > array2[largest].id) {
        largest = r;
    }

    if (largest != i) {
        swap(&array2[i], &array2[largest]);
        heapify2(largest);
    }
}

void insert(Seed newNum)
{
    array[size] = newNum;
    ++size;
    if(size == 1LL) return;
    for (ll i = (size/2LL - 1LL); i >= 0LL; i--) { 
        heapify(i); 
    }
}

void insert2(Seed newNum)
{
    array2[size2] = newNum;
    ++size2;
    if(size2 == 1LL) return;
    for (ll i = (size2/2LL - 1LL); i >= 0LL; i--) { 
        heapify2(i); 
    }
}

void pop() {
    swap(&array2[0], &array2[size2 - 1LL]);
    --size2;

    for (ll i = size2/2LL-1LL; i >= 0LL; i--) {
        heapify2(i);
    }
}

int main()
{
    ll k;
    scanf("%lld", &k);

    ll id;
    ll score;

    while (scanf("%lld %lld", &id, &score) == 2) {
        Seed s; 
        s.id = -id;
        s.score = -score;

        insert(s);
    }

    k = (k < size ? k : size);

    for(ull i=0; i<k; ++i) {
        insert2(array[i]);
    }

    while(k--) {
        printf("%lld %lld\n", -array2[0].id, -array2[0].score);
        pop();
    }

    return 0;
}