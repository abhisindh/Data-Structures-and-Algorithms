#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node
{
    int node_id;
    Node* next;

};

typedef struct Graph{
    int N;
    Node **adjacency_list;
}Graph;

Graph* createGraph(int N){
    Graph* newGraph = malloc(sizeof(Graph));
    newGraph->N = N;

    Node **adjacency_list = calloc(N, sizeof(Node*));
    newGraph->adjacency_list = adjacency_list;

    return newGraph;
}

static Node* createNode(int id){
    Node* new_node = malloc(sizeof(Node));
    new_node->node_id = id;
    new_node->next = NULL;
    return new_node;
}

static Node* push_tail(Node* head, int id){
    Node* new_node = createNode(id);
    if (!head) head = new_node;
    else {
        Node* current = head;
        while (current->next){
            current = current->next;
        }
        current->next = new_node;
    }
    return head;
}


void addEdge(Graph* graph, int source_id, int dest_id){
    Node* head = graph->adjacency_list[source_id];
    graph->adjacency_list[source_id] = push_tail(head, dest_id);
}

void printGraph(Graph* graph){
    for (int i=0; i<graph->N; i++){
        printf("%d->", i);
        Node* current = graph->adjacency_list[i];
        while (current){
            printf("%d ", current->node_id);
            current = current->next;
        }
        printf("\n");
    }

}

// int main(){
//     Graph* graph = createGraph(5); // ids - 0, 1, 2, 3, 4
//     addEdge(graph, 1, 3);
//     addEdge(graph, 1, 4);
//     addEdge(graph, 1, 2);
//     addEdge(graph, 2, 3);
//     addEdge(graph, 3, 4);
//     printGraph(graph);
// }
    