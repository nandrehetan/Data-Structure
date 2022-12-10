#include <stdio.h>
#include <malloc.h>
 struct node{
    int data;
    int weight;
    struct node * next;

};
struct Graph {
  int vertNum;
  struct node** adjLists;
};

struct node* createNode(int v,int c) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->data = v;
  newNode->next = NULL;
  newNode->weight = c;
  return newNode;
}

struct Graph* createAGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->vertNum = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));

  int i;
  for (i = 0; i < vertices; i++)
    graph->adjLists[i] = NULL;

  return graph;
}

void addEdge(struct Graph* graph, int s, int d,int c) {
  struct node* newNode = createNode(d,c);
  newNode->next = graph->adjLists[s];
  graph->adjLists[s] = newNode;
}

void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->vertNum; v++) {
    struct node* temp = graph->adjLists[v];
    printf("\n Vertex %d\n: ", v);
    while (temp) {
      printf("%d -> ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}

struct Graph * mstcreate(struct Graph * graph){
    struct Graph* new = createAGraph(graph->vertNum);
    return new;
}

int main() {
    int n,m,x,y,z;
    printf("enter the number of matrices");
    scanf("%d",&n);
    printf("enter the number of edges");
    scanf("%d",&m);

    struct Graph* graph = createAGraph(n);
    for (int i = 0; i < m; i++){
        printf("enter the nodes of edge");
        scanf("%d",&x);
        scanf("%d",&y);
        printf("enter the cost of edge");
        scanf("%d",&z);
        addEdge(graph,x,y,z);
    }
    printGraph(graph);
    struct Graph* mst = mstcreate(graph);
    return 0;
}
