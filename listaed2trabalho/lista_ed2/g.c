#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char creatures[5005][31];
int adj[5005][5005];
bool visited[5005];
bool visited2[5005];

int chain_size = 0;
void dfs(int at) {
	if(visited[at]) return;

	visited[at] = true;
	++chain_size;

	int j=0;
	while(adj[at][j] != -1) {
		dfs(adj[at][j]);
		++j;
	}
}

void reset(int C) {
	for(int i=0; i<C; i++) {
		for(int j=0; j<31; j++) {
			creatures[i][j]=0;
		}
	}

	for(int i=0; i<C; i++) {
		for(int j=0; j<C; j++) {
			adj[i][j]=-1;
			// rev_adj[i][j]=-1;
		}
	}

	for(int i=0; i<C; ++i) visited[i] = false;
}

int main()
{
	int C, R;
	while(scanf("%d %d", &C, &R) == 2 && C!=0)
	{
		reset(C);

		for(int i=0; i<C; ++i) {
			char name[31];
			scanf("%s", name);
			strcpy(creatures[i], name);
		}

		for(int i=0; i<R; ++i) {
			char name1[31], name2[31];
			scanf("%s %s", name1, name2);

			int id1 = 0;
			int id2 = 0;

			for(int j=0; j<C; ++j) {
				if(strcmp(name1, creatures[j]) == 0) { id1 = j; break; }
			}
			for(int j=0; j<C; ++j) {
				if(strcmp(name2, creatures[j]) == 0) { id2 = j; break; }
			}

			int j;

			j=0; while(adj[id2][j] != -1) ++j;
			adj[id2][j] = id1;

			j=0; while(adj[id1][j] != -1) ++j;
			adj[id1][j] = id2;
		}

		// for(int i=0; i<C; i++) {
		// 	printf("%d > ", i);
		// 	for(int j=0; j<C; j++) {
		// 		if(adj[i][j] == -1) continue;
		// 		printf("%d ", adj[i][j]);
		// 	}
		// 	printf("\n");
		// }
		// printf("\n");
		// printf("\n");

		int ans = 0;

		for(int i=0; i<C; ++i) {
			if(visited[i]) continue;
			chain_size = 0;
			dfs(i);
			ans = (chain_size > ans ? chain_size : ans);
		}

		printf("%d\n", ans);
	}

	return 0;
}