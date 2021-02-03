#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef long long ll;

ll N;
ll adj[2005][2005];

bool visited[2005];

void dfs(ll at) {
	if(visited[at]) return;

	visited[at] = true;

	ll i=0;

	while(adj[at][i] != -1) {
		dfs(adj[at][i]);
		++i;
	}
}

ll solve() {

	for(ll i=1; i<=N; i++) {
		
		for(ll k=1; k<=N; k++) visited[k] = false;

		dfs(i);

		bool visited_all = true;

		for(ll k=1; k<=N; k++) {
			visited_all &= visited[k];
		}

		if(visited_all == false) { return 0; }
	}

	return 1;
}

int main()
{
	while(scanf("%lld", &N) == 1)
	{
		for(ll i=1; i<=N; i++) {
			for(ll j=1; j<=N; j++) {
				adj[i][j] = -1;
			}
		}

		if(N == 0) break;
		
		ll M;
		scanf("%lld", &M);

		for(ll i=0; i<M; ++i) {
			ll V, W, P;
			scanf("%lld %lld %lld", &V, &W, &P);

			// printf("%lld\n", V);
			
			ll j=0; while(adj[V][j] != -1) ++j;

			adj[V][j] = W;

			if(P==2) {
				j=0; while(adj[W][j] != -1) ++j;
				adj[W][j] = V;
			}
		}

		printf("%lld\n", solve());
	}

	return 0;
}