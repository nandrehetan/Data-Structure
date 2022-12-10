#include <stdio.h>
#include <malloc.h>
 struct node
{
    int data;
    struct node * next;

};
struct Graph {
  int vertNum;
  struct node** adjLists;
};

struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->data = v;
  newNode->next = NULL;
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

void addEdge(struct Graph* graph, int s, int d) {
  struct node* newNode = createNode(d);
  newNode->next = graph->adjLists[s];
  graph->adjLists[s] = newNode;
  newNode = createNode(s);
  newNode->next = graph->adjLists[d];
  graph->adjLists[d] = newNode;
}

void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct node* temp = graph->adjLists[v];
    printf("\n Vertex %d\n: ", v);
    while (temp) {
      printf("%d -> ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}
int main() {
    int n,m,x,y;
    printf("enter the number of matrices");
    scanf("%d"&n);
    printf("enter the number of edges");
    scanf("%d"&m);

    struct Graph* graph = createAGraph(n);
    for (int i = 0; i < m; i++){
        printf("enter the the nodes of edges");
        scanf("%d"&x);
        scanf("%d"&y);
        addEdge(graph,x,y);
    }
    printGraph(graph);
    return 0;
}
