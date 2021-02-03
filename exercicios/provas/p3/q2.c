#include <stdio.h>
#include <stdlib.h>

typedef struct Aresta {
    int verticeA;
    int verticeB;
} Aresta;

typedef struct Vertice {
    int vertice;
    struct Vertice *proximoVertice;
} Vertice;

typedef struct Grafo {
    int qtdeVertices;
    struct Vertice **listaAdj;
}Grafo;

#define tamMax 100000
static int conexos[tamMax], tamConexos[tamMax], minConexos[tamMax];
static int contadorConexos = 1;
// static int cnt = 0, pos[100000], conexos; q1

Grafo *criaGrafo (int qtdeVertices);
Vertice *novoVertice (int vertice);
void buscaEmProfundidade (Grafo *g, int v);
void adicionaAresta (Grafo *g, int atual, int destino);
int qtdeArestas (Aresta *a, Grafo *g);
void imprimeGrafo (Grafo *g);

int main (void){

    int qtdeVertices, cidadeJoao, verticeA, verticeB;
    int prox = 0, i;
    int max = 0, iMax = -1;

    scanf ("%d", &qtdeVertices);
    scanf ("%d", &cidadeJoao);

    Grafo *g = criaGrafo (qtdeVertices);

    while (scanf ("%d", &verticeA) == 1){
        if (scanf ("%d", &verticeB) != 1) 
            adicionaAresta (g, verticeA, verticeA);

        adicionaAresta (g, verticeA, verticeB);
        adicionaAresta (g, verticeB, verticeA);

        if (verticeA == cidadeJoao) prox = 1;
        if (verticeB == cidadeJoao) prox = 1;
    }

    // imprimeGrafo (g);

    i = 0;
    while ( i < qtdeVertices){
        if (conexos[i] == 0){
            minConexos[contadorConexos] = i;
            buscaEmProfundidade (g, i);
            contadorConexos++;
        }
        i++;
    }

    i = 0;
    while (i < contadorConexos){
        if ((tamConexos[i] > max) || (tamConexos[i] == max && minConexos[iMax] > minConexos[i])){
            max = tamConexos[i];
            iMax = i;
        }
        i++;
    }

    if (tamConexos[conexos[cidadeJoao]] == max){
        if (prox == 0) printf ("Fique em casa\n");
        else printf ("Bora pra estrada\n");
    }else printf ("Vamos para %d\n", minConexos[iMax]);
    
    return 0;
}

Grafo *criaGrafo (int qtdeVertices){

    int i;
    Grafo *g = malloc (sizeof (Grafo));
    g->qtdeVertices = qtdeVertices;
    g->listaAdj = malloc (qtdeVertices * sizeof (Vertice*));

    for (i = 0; i < qtdeVertices; i++) g->listaAdj[i] = NULL;

    return g;
}

Vertice *novoVertice (int vertice){

    Vertice *x = malloc (sizeof(Vertice));
    if (x == NULL)
        exit(EXIT_FAILURE);

    x->vertice = vertice;
    x->proximoVertice = NULL;
    return x;
}

void adicionaAresta (Grafo *g, int atual, int destino){

    Vertice *v = novoVertice (destino);
    v->proximoVertice = g->listaAdj[atual];
    g->listaAdj[atual] = v;

    v = novoVertice (atual);
    v->proximoVertice = g->listaAdj[destino];
    g->listaAdj[destino] = v;
}

void buscaEmProfundidade (Grafo *g, int v){

    if (conexos[v] != 0) 
        return;
    
    Vertice *adjList = g->listaAdj[v];
    Vertice *tmpAux = adjList;

    conexos[v] = contadorConexos;

    if (v < minConexos[contadorConexos]) 
        minConexos[contadorConexos] = v;
    
    tamConexos[contadorConexos]++;

    while (tmpAux != NULL){
        int conexo = tmpAux->vertice;
        buscaEmProfundidade (g, conexo);
        tmpAux = tmpAux->proximoVertice;
    }
}

void imprimeGrafo (Grafo *g){

    int i, j;
    Vertice *a;

    for (i = 0; i < g->qtdeVertices; i++){
        printf ("Vértice %d: ", i);
        for (a = g->listaAdj[i]; a != NULL; a = a->proximoVertice){
            printf ("%d ", a->vertice);
        }
        printf ("\n");
    }
}

