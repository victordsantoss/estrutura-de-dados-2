#include <stdio.h>
#include <stdlib.h>

typedef struct Edge{
    int vA;
    int vB;
} Edge;

typedef struct Graph {
    int qtdeV;  
    int qtdeA; 
    int **matrizAdj;
} Graph;

Edge EDGE (int v, int w);
int **iniMatriz (int n);
Graph *iniGraph (int v);
Graph *iniGraph (int v);
void insertGraph (Graph *g, Edge e);
void removeGraph (Graph *g, Edge e);
int graphEdges(Edge *a, Graph *g) ;
Graph* graphCopy(Graph *g) ;
static void matrizDestroy(int **M, int v) ;
void graphDestroy (Graph *g);
void imprimeGrafo (Graph *g);

int main (void){

    int qtdeV = 5;  
    int verticeA, verticeB;
    Edge e[qtdeV];

    Graph *g = iniGraph (qtdeV);

    printf ("Grafo de %d Vértices Inicializado!\n", g->qtdeV);
    imprimeGrafo (g);

    while (scanf ("%d", &verticeA) != EOF){
        scanf("%d", &verticeB);
        printf ("Ligando o vértice %d ao vértice %d:\n", verticeA, verticeB);
        insertGraph(g, EDGE(verticeA, verticeB));
        imprimeGrafo (g);
        printf ("Quantidade de Arestas: %d\n", graphEdges (e, g));
    }

    while (scanf ("%d", &verticeA) != EOF){
        scanf("%d", &verticeB);
        printf ("Removendo Aresta que liga o vértice %d ao vértice %d:\n", verticeA, verticeB);
        removeGraph(g, EDGE(verticeA, verticeB));
        imprimeGrafo (g);
        printf ("Quantidade de Arestas: %d\n", graphEdges (e, g));
    }

    graphDestroy (g);

    return 0;
}

Edge EDGE (int v, int w){
    Edge e;
    e.vA = v;
    e.vB = w;
    return e;
}

int **iniMatriz (int n){

    int i, j, **m;
    m = malloc (n * sizeof(int*));

    for (i = 0; i < n; i++){
        m[i] = malloc (n * sizeof (int));
        for (j = 0; j < n; j++)
            m[i][j] = 0;
    }
    return m;
}

Graph *iniGraph (int v){
    Graph *g = malloc(sizeof(g));
    g->qtdeV = v;
    g->qtdeA = 0;
    g->matrizAdj = iniMatriz(v);
}

void insertGraph (Graph *g, Edge e){
    int v = e.vA;
    int w = e.vB;

    if (g->matrizAdj[v][w] == 0){
        g->matrizAdj[v][w] = 1;
        g->matrizAdj[w][v] = 1;
        g->qtdeA ++;
    }
}

void removeGraph (Graph *g, Edge e){
    int v = e.vA;
    int w = e.vB;

    if (g->matrizAdj[v][w] == 1){
        g->matrizAdj[v][w] = 0;
        g->matrizAdj[w][v] = 0;
        g->qtdeA --;
    }
}

int graphEdges(Edge *a, Graph *g) {
    int E = 0;
    for (int i = 0; i < g->qtdeV; i++) {
        for (int j = i+1; j < g->qtdeV; j++) {
            if (g->matrizAdj[i][j] == 1) {
                a[E++] = EDGE(i, j);
            }
        }
    }
    return E;
}

void imprimeGrafo (Graph *g){
 for (int i = 0; i < g->qtdeV; i++){
        for (int j = 0; j < g->qtdeV; j++)
            printf ("%d ", g->matrizAdj[i][j]);
        printf ("\n");
    }
}

Graph* graphCopy(Graph *g) {
    Graph *copy = malloc(sizeof(Graph));
    copy->qtdeV = g->qtdeV;
    copy->qtdeA = g->qtdeA;
    copy->matrizAdj = iniMatriz(g->qtdeV);
    for (int i = 0; i < g->qtdeV; i++) {
        for (int j = 0; j < g->qtdeV; j++) {
            copy->matrizAdj[i][j] = g->matrizAdj[i][j];
        }
    }
    return copy;
}

void graphDestroy (Graph *g) {
    matrizDestroy(g->matrizAdj, g->qtdeV);
    free(g);
}

static void matrizDestroy(int **M, int v) {
    for (int i = 0; i < v; i++) {
        free(M[i]);
    }
    free(M);
}
