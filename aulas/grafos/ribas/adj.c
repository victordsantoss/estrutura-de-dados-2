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

static int cnt = 0, pos[1000], conexos;

Aresta criaAresta (int verticeA, int verticeB);
Grafo *criaGrafo (int qtdeVertices);
Vertice *novoVertice (int vertice, Vertice *proximoVertice);
void insereGrafo (Grafo *g, Aresta e);
void imprimeGrafo (Grafo *g);
int qtdeArestas (Aresta *a, Grafo *g);
void buscaEmProfundidade (Grafo *g, Aresta a);
void procuraGrafo (Grafo *g);
int procuraVertice (Grafo *g, int vertice);
int removeVertice (Grafo *g, int vertice);

// Para BFS
// Para Bfs
typedef struct Queue {
    Aresta e;
    struct Queue *next;
    struct Queue *last;
} Queue;

// Cabeça da Fila
Queue *fila;

void QueueInit (){
    fila = malloc (sizeof(Queue));
    fila->e = criaAresta (0,0);
    fila->next = NULL;
    fila->last = NULL;
}

int QueueEmpty (){
    if (fila->next == NULL)
        return 1;
    return 0;
}

void QueuePut (Aresta e){
    Queue *new = malloc(sizeof(Queue));
    new->e = e;
    if (!QueueEmpty()) {
        Queue *last = fila->last;
        last->next = new;
        fila->last = new;
        return;
    }
    fila->next = new;
    fila->last = new;
    return;
}

Aresta QueueGet() {
    Queue *next = fila->next;
    Aresta e = next->e;
    fila->next = next->next;
    free(next);
    return e;
}

void bfs (Grafo *G, Aresta e) {
    QueuePut(e);
    int v;
    while (!QueueEmpty()) {
        Aresta a = QueueGet();
        v = a.verticeB;
        if (pos[v] == -1)
            pos[v] = cnt++;
        for (Vertice *t = G->listaAdj[v].proximoVertice; t != NULL; t = t->proximoVertice) {
            if (pos[t->vertice] == -1) {
                pos[t->vertice] = cnt++;
                QueuePut(criaAresta(v, t->vertice));
            }
        }
    }
}

void procuraGrafoBfs (Grafo *g) {
    for (int v = 0; v < g->qtdeVertices; v++) pos[v] = -1;
    
    for (int v = 0; v < g->qtdeVertices; v++){
        if (pos[v] == -1){
            bfs(g, criaAresta(v, v));
            conexos ++;
        } 
    }
}



int main (void){

    int qtdeVertices;
    int vA, vB;

    scanf ("%d", &qtdeVertices);

    Grafo *g = criaGrafo (qtdeVertices);
    Aresta *a = malloc (g->qtdeVertices * sizeof (Aresta));
    Vertice *v;

    printf ("Grafo de %d vértices criado!\n", g->qtdeVertices);

    while (scanf ("%d", &vA) != EOF){
        scanf ("%d\n", &vB);
        insereGrafo (g, criaAresta (vA, vB));
    }

    /*imprimeGrafo (g);

    printf ("Quantidade de Arestas: %d\n", qtdeArestas (a, g));
    procuraGrafo (g);

    printf ("Caminho do grafo usando Busca em Profundidade (DFS):\n");
    for (int v = 0; v < g->qtdeVertices; v++) {
        if (pos[v] != -1)
            printf("w: %d pos[w]: %d\n", v, pos[v]);
    }
    
    printf ("Quantidade de Grafos Conexos: %d\n", conexos);

    int verticeProcurado = 1;

    if (procuraVertice (g, 1))
        printf ("Vertice Encontrado!\n");

    if (removeVertice (g, 1))
        printf ("Vertice Removido!\n");

    imprimeGrafo (g);
    */
    QueueInit (g);

    printf ("Caminho do grafo usando Busca em Largura (BFS):\n");
    procuraGrafoBfs (g);
    for (int v = 0; v < g->qtdeVertices; v++) {
        if (pos[v] != -1)
            printf("w: %d pos[w]: %d\n", v, pos[v]);
    }


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

int procuraVertice (Grafo *g, int vertice){

    Vertice *a;

    for (a = g->listaAdj; a != NULL; a = a->proximoVertice){
        if (a->vertice == vertice)
            return 1;
    }
}

int removeVertice (Grafo *g, int vertice){

    Vertice *a, *aux;

    for (a = g->listaAdj; a->proximoVertice != NULL; a = a->proximoVertice){
        if (a->proximoVertice->vertice == vertice){
            aux = a->proximoVertice;
            a->proximoVertice = aux->proximoVertice;
            free(aux);
            return 1;
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

