#include <stdio.h>
#include <stdbool.h>

int places[2010][2010];
bool is_unsafe[2010];

int main()
{
	int N, M, J;
	scanf("%d %d %d", &N, &M, &J);

	for(int i=0; i<N; i++)
	{
		int A;
		scanf("%d", &places[i][0]);

		for(int j=1; j<=places[i][0]; j++) {
			scanf("%d", &places[i][j]);
		}
	}

	for(int i=0; i<M; i++) {
		int F;
		
		scanf("%d", &F);

		is_unsafe[F] = true;

		for(int j=1; j<=places[F][0]; j++) {
			int unsafe_place = places[F][j];
			is_unsafe[unsafe_place] = true;
		}
	}

	for(int i=0; i<J; i++) {
		int Q;
		scanf("%d", &Q);

		printf("%s\n", is_unsafe[Q] ? "Eu vou estar la" : "Nao vou estar la");
	}

	return 0;
}