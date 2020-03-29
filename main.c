#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

struct fila {
    int items[SIZE];
    int front;
    int rear;
};

struct fila* criaFila();
void enfileirar(struct fila* q, int);
int defila(struct fila* q);
void mostra(struct fila* q);
int estaVazio(struct fila* q);
void imprimeFila(struct fila* q);

struct node
{
    int vertex;
    struct node* next;
};

struct node* createNode(int);

struct Graph
{
    int numVertices;
    struct node** adjLists;
    int* visited;
};

struct Graph* criaGrafo(int vertices);
void addAresta(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);
void bfs(struct Graph* graph, int startVertex);

int main()
{
    struct Graph* graph = criaGrafo(6);
    addAresta(graph, 0, 1);
    addAresta(graph, 0, 2);
    addAresta(graph, 1, 2);
    addAresta(graph, 1, 4);
    addAresta(graph, 1, 3);
    addAresta(graph, 2, 4);
    addAresta(graph, 3, 4);

    bfs(graph, 0);

    return 0;
}

void bfs(struct Graph* graph, int startVertex) {

    struct fila* q = criaFila();

    graph->visited[startVertex] = 1;
    enfileirar(q, startVertex);

    while(!estaVazio(q)){
        imprimeFila(q);
        int currentVertex = defila(q);
        printf("Visited %d\n", currentVertex);

       struct node* temp = graph->adjLists[currentVertex];

       while(temp) {
            int adjVertex = temp->vertex;

            if(graph->visited[adjVertex] == 0){
                graph->visited[adjVertex] = 1;
                enfileirar(q, adjVertex);
            }
            temp = temp->next;
       }
    }
}


struct node* createNode(int v)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}


struct Graph* criaGrafo(int vertices)
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node*));
    graph->visited = malloc(vertices * sizeof(int));


    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addAresta(struct Graph* graph, int src, int dest)
{
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

struct fila* criaFila() {
    struct fila* q = malloc(sizeof(struct fila));
    q->front = -1;
    q->rear = -1;
    return q;
}


int estaVazio(struct fila* q) {
    if(q->rear == -1)
        return 1;
    else
        return 0;
}

void enfileirar(struct fila* q, int value){
    if(q->rear == SIZE-1)
        printf("\nfila is Full!!");
    else {
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int defila(struct fila* q){
    int item;
    if(estaVazio(q)){
        printf("fila is empty");
        item = -1;
    }
    else{
        item = q->items[q->front];
        q->front++;
        if(q->front > q->rear){
            printf("Resetting fila");
            q->front = q->rear = -1;
        }
    }
    return item;
}

void imprimeFila(struct fila *q) {
    int i = q->front;

    if(estaVazio(q)) {
        printf("fila is empty");
    } else {
        printf("\nfila contains \n");
        for(i = q->front; i < q->rear + 1; i++) {
                printf("%d ", q->items[i]);
        }
    }
}
