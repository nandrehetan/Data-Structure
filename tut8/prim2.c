#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
};

struct AdjList {
    struct AdjListNode* head;
};

struct Graph {
    int V;
    struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest, int weight){
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight){
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

struct heaNode {
    int v;
    int key;
};

struct hea {
    int size;
    int capacity;
    int* pos;
    struct heaNode** array;
};

struct heaNode* newheaNode(int v, int key){
    struct heaNode* heaNode = (struct heaNode*)malloc(sizeof(struct heaNode));
    heaNode->v = v;
    heaNode->key = key;
    return heaNode;
}

struct hea* createhea(int capacity){
    struct hea * hea = (struct hea*)malloc(sizeof(struct hea));
    hea->pos = (int*)malloc(capacity * sizeof(int));
    hea->size = 0;
    hea->capacity = capacity;
    hea->array = (struct heaNode**)malloc(capacity * sizeof(struct heaNode*));
    return hea;
}

void swapheaNode(struct heaNode** a, struct heaNode** b){
    struct heaNode* t = *a;
    *a = *b;
    *b = t;
}

void heapify(struct hea* hea, int idx){
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < hea->size && hea->array[left]->key < hea->array[smallest]->key)
        smallest = left;

    if (right < hea->size && hea->array[right]->key < hea->array[smallest]->key)
        smallest = right;

    if (smallest != idx) {
        struct heaNode* smallestNode = hea->array[smallest];
        struct heaNode* idxNode = hea->array[idx];
        hea->pos[smallestNode->v] = idx;
        hea->pos[idxNode->v] = smallest;
        swapheaNode(&hea->array[smallest], &hea->array[idx]);
        heapify(hea, smallest);
    }
}

int isEmpty(struct hea* hea){
    return hea->size == 0;
}

struct heaNode* extractMin(struct hea* hea){
    if (isEmpty(hea))
        return NULL;

    struct heaNode* root = hea->array[0];

    struct heaNode* lastNode = hea->array[hea->size - 1];
    hea->array[0] = lastNode;

    hea->pos[root->v] = hea->size - 1;
    hea->pos[lastNode->v] = 0;

    --hea->size;
    heapify(hea, 0);

    return root;
}

void decreaseKey(struct hea* hea, int v, int key){
    int i = hea->pos[v];

    hea->array[i]->key = key;

    while (i && hea->array[i]->key < hea->array[(i - 1) / 2]->key) {

        hea->pos[hea->array[i]->v] = (i - 1) / 2;
        hea->pos[hea->array[(i - 1) / 2]->v] = i;
        swapheaNode(&hea->array[i], &hea->array[(i - 1) / 2]);

        i = (i - 1) / 2;
    }
}


bool isInhea(struct hea* hea, int v){
    if (hea->pos[v] < hea->size)
        return true;
    return false;
}

void printArr(int arr[], int n){
    for (int i = 1; i < n; ++i)
        printf("%d - %d\n", arr[i], i);
}

void PrimMST(struct Graph* graph){
    int V = graph->V;
    int parent[V];
    int key[V];
    struct hea* hea = createhea(V);

    for (int v = 1; v < V; ++v) {
        parent[v] = -1;
        key[v] = INT_MAX;
        hea->array[v] = newheaNode(v, key[v]);
        hea->pos[v] = v;
    }

    key[0] = 0;
    hea->array[0] = newheaNode(0, key[0]);
    hea->pos[0] = 0;

    hea->size = V;

    while (!isEmpty(hea)) {
        struct heaNode* heaNode= extractMin(hea);
        int u= heaNode->v;
        struct AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl != NULL) {
            int v = pCrawl->dest;

            if (isInhea(hea, v)
                && pCrawl->weight < key[v]) {
                key[v] = pCrawl->weight;
                parent[v] = u;
                decreaseKey(hea, v, key[v]);
            }
            pCrawl = pCrawl->next;
        }
    }

    printArr(parent, V);
}

int main(){
    int n,m,x,y,z;
    printf("enter the number of matrices");
    scanf("%d",&n);
    printf("enter the number of edges");
    scanf("%d",&m);

    struct Graph* graph = createGraph(n);
    for (int i = 0; i < m; i++){
        printf("enter the nodes of edge");
        scanf("%d",&x);
        scanf("%d",&y);
        printf("enter the cost of edge");
        scanf("%d",&z);
        addEdge(graph,x,y,z);
    }
    PrimMST(graph);
    return 0;
}
