#include <stdio.h>
#include <stdlib.h>

// Estrutura pra uma aresta que liga um vértice A à um vértice B
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
    int qtdeArestas;
    Vertice *listaAdj;
} Grafo;

static int cnt = 0, pos[100000], conexos;

Aresta criaAresta (int verticeA, int verticeB);
Grafo *criaGrafo (int qtdeVertices);
Vertice *novoVertice (int vertice, Vertice *proximoVertice);
void insereGrafo (Grafo *g, Aresta e);
void imprimeGrafo (Grafo *g);
int qtdeArestas (Aresta *a, Grafo *g);
void buscaEmProfundidade (Grafo *g, Aresta a);
void procuraGrafo (Grafo *g);
int verificaConexao (Grafo *g);

int main (void){

    int qtdeVertices;
    int vA, vB, contador = 0;

    scanf ("%d", &qtdeVertices);

    Grafo *g = criaGrafo (qtdeVertices);
    Aresta *a = malloc (g->qtdeVertices * sizeof (Aresta));

    while (scanf ("%d", &vA) == 1){
        if (scanf ("%d", &vB) != 1)
            insereGrafo (g, criaAresta (vA, vA));
        else
            insereGrafo (g, criaAresta(vA, vB));
    }
    procuraGrafo (g);
    printf ("%d\n", conexos);

    return 0;
}


Aresta criaAresta (int verticeA, int verticeB){
    Aresta e;
    e.verticeA = verticeA;
    e.verticeB = verticeB;
    return e;
}

Grafo *criaGrafo (int qtdeVertices){

    int i;
    Grafo *g = malloc (qtdeVertices * sizeof (Grafo));

    g->qtdeVertices = qtdeVertices;
    g->qtdeArestas = 0;

    g->listaAdj = malloc (qtdeVertices * sizeof (Vertice));

    for (i = 0; i < g->qtdeVertices; i++)
        g->listaAdj[i].proximoVertice = NULL;

    return g;
}

Vertice *novoVertice (int vertice, Vertice *proximoVertice){

    Vertice *x = malloc (sizeof(Vertice));

    if (x == NULL)
        exit(EXIT_FAILURE);

    x->vertice = vertice;
    x->proximoVertice = proximoVertice;

    return x;
}

void insereGrafo (Grafo *g, Aresta e){

    int verticeA = e.verticeA, verticeB = e.verticeB;

    Vertice *proximoVerticeA = g->listaAdj[e.verticeA].proximoVertice;
    Vertice *proximoVerticeB = g->listaAdj[e.verticeB].proximoVertice;

    g->listaAdj[e.verticeA].proximoVertice = novoVertice (e.verticeB, proximoVerticeA);
    g->listaAdj[e.verticeB].proximoVertice = novoVertice (e.verticeA, proximoVerticeB);
    g->qtdeArestas++;
}

int qtdeArestas (Aresta *a, Grafo *g){

    int v, qtdeArestas = 0;
    Vertice *t;

    for (v = 0; v < g->qtdeVertices; v++){
        for (t = g->listaAdj[v].proximoVertice; t != NULL; t = t->proximoVertice){
            if (v < t->vertice)
                a[qtdeArestas++] = criaAresta(v, t->vertice);
        }
    }
    return qtdeArestas;
}

void procuraGrafo (Grafo *g) {
    for (int v = 0; v < g->qtdeVertices; v++) pos[v] = -1;
    
    for (int v = 0; v < g->qtdeVertices; v++){
        if (pos[v] == -1){
            buscaEmProfundidade(g, criaAresta(v, v));
            conexos ++;
        } 
    }
}

void buscaEmProfundidade (Grafo *g, Aresta a){
    int v = a.verticeB;
    pos[v] = cnt++;
    for (Vertice *p = g->listaAdj[v].proximoVertice; p != NULL; p = p->proximoVertice) {
        int w = p->vertice;
        if (pos[w] == -1){
            buscaEmProfundidade (g, criaAresta(v, w));
        }
    }
}

void imprimeGrafo (Grafo *g){

    int i, j;
    Vertice *a;

    for (i = 0; i < g->qtdeVertices; i++){
        printf ("Vértice %d: ", i);
        for (a = g->listaAdj[i].proximoVertice; a != NULL; a = a->proximoVertice){
            printf ("%d ", a->vertice);
        }
        printf ("\n");
    }
}

