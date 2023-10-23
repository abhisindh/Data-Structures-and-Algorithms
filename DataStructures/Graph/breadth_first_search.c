#include "adjacency_list.c"
#include "../Queue_.c"


int not_visited(int* array, int size, int node)
{
    for (int i=0; i<size; i++)
    {
        if (array[i] == node) return 0;
    }
    return 1;
}

void bfs(Graph* graph, int node)
{
    int list_index = 0;
    Queue* queue = create_queue();
    int* visited = malloc(sizeof(int)* graph->N);
    enqueue(queue, node);
    visited[list_index] = node;
    list_index++;

    while (!empty(queue))
    {
        int current = dequeue(queue);
        Node* neighbour = graph->adjacency_list[current];
        printf("%d ", current);
        while (neighbour)
        {
            if (not_visited(visited, list_index+1, neighbour->node_id))
            {
                enqueue(queue, neighbour->node_id);
                visited[list_index] = neighbour->node_id;
                list_index++;
            }
            neighbour = neighbour->next;
        }            
    }
}



int main()
{
    Graph* graph = createGraph(7);
    addEdge(graph, 0, 1);addEdge(graph, 1, 0);
    addEdge(graph, 0, 2);addEdge(graph, 2, 0);
    addEdge(graph, 1, 2);addEdge(graph, 2, 1);
    addEdge(graph, 0, 3);addEdge(graph, 3, 0);
    addEdge(graph, 3, 4);addEdge(graph, 4, 3);
    addEdge(graph, 3, 5);addEdge(graph, 5, 3);
    addEdge(graph, 3, 6);addEdge(graph, 6, 3);
    addEdge(graph, 4, 5);addEdge(graph, 5, 4);
    addEdge(graph, 5, 6);addEdge(graph, 6, 5);
    bfs(graph, 5);
    return EXIT_SUCCESS;
}