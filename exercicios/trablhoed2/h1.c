#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void buscaEmProfundidade (int a);
void iniciaMat (int N);
void iniciaVet (int N);
int conexao (int N);

#define tamMax 5000

int matrizAdj[tamMax][tamMax];
bool visitado[tamMax];

int main (void){

    // Var principais
    int numInter, numRuas;
    int ruaV, ruaW;
    int identificadorRua; // 1 mão única e 2 mão dupla 

    // var auxiliares
    int i, j;

    while (1){

        scanf("%d", &numInter);

		if (numInter == 0) 
            break;
        		
        iniciaMat (numInter);

		scanf("%d", &numRuas);

		for (i = 0; i < numRuas; ++i){
            scanf ("%d", &ruaV);
            scanf ("%d", &ruaW);
            scanf ("%d", &identificadorRua);

            j = 0;
            while (matrizAdj[ruaV][j] != -1) 
                ++j;

			matrizAdj[ruaV][j] = ruaW;

			if (identificadorRua == 2){
				j = 0; 
                while(matrizAdj[ruaW][j] != -1) 
                    ++j;
				matrizAdj[ruaW][j] = ruaV;
			}
		}
		printf("%d\n", conexao(numInter));
	}
    return 0;
}

void iniciaMat (int N){

    int i, j;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			matrizAdj[i][j]=-1;
		}
	}
}

void iniciaVet (int N){

    int j;
    for (j = 1; j <=N; j++)
        visitado[j] = false;
}

void buscaEmProfundidade (int a){

    int i;

    if (visitado[a])
        return;

    visitado[a] = true;
    i = 0;

    while (matrizAdj[a][i] != -1){
        buscaEmProfundidade (matrizAdj[a][i]);
        ++i;
    }   
}

int conexao (int N){

    int i, j;
    bool vis;

    for (i = 1; i <= N; i++){
        iniciaVet (N);
        buscaEmProfundidade(i);
        vis = true;

        for (j = 1; j <=N; j++)
            vis &= visitado[j];

        if (vis == false)
            return 0;
    }
    return 1;
}
