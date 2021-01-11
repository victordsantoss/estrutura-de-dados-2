#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;
typedef long long ll;

typedef struct Seed {
    ll id;
    ll score;
} Seed;

ll size = 0;
Seed array[10000005];

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
void insert(Seed newNum)
{
    array[size] = newNum;
	++size;
    if(size == 1LL) return;
    for (ll i = (size/2LL - 1LL); i >= 0LL; i--) { 
    	heapify(i); 
   	}
}

void pop() {
    swap(&array[0], &array[size - 1LL]);
    --size;

    for (ll i = size/2LL-1LL; i >= 0LL; i--) {
        heapify(i);
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

    while(k--) {
    	printf("%lld %lld\n", -array[0].id, -array[0].score);
        pop();
    }

    return 0;
}