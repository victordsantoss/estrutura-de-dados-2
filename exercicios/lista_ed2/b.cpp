#include <iostream>
#include <cstdio>
#include <ctime>
#include <queue>

const clock_t begin_time = clock();

#define isb ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0)

using namespace std;
using ll = long long;

#define ff first
#define ss second

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

// typedef struct Seed { ll id, score; } Seed;
using Seed = pair<ll,ll>;
Seed array[10000000];

int main() 
{
	isb;

	ll k;
    cin >> k;

    min_heap<Seed> s;

	ll T = 0;
	ll score, id;
    while (cin >> id >> score) {
        s.push({score, id});
    }

    while(k--) {
        auto & [score, id] = s.top();
        cout << id << " " << score << '\n';
        s.pop();
    }

    cout << "Elapsed time: " << (clock() - begin_time) / (double)CLOCKS_PER_SEC << " seconds" << endl;
    
	return 0;
}