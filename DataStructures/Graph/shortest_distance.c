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

Graph* spanning_tree(Graph* graph, int start)
{
    Graph* tree = createGraph(graph->N);
    int list_index = 0;
    Queue* queue = create_queue();
    int* visited = malloc(sizeof(int)* graph->N);
    enqueue(queue, start);
    visited[list_index] = start;
    list_index++;

    while (!empty(queue))
    {
        int current = dequeue(queue);
        Node* neighbour = graph->adjacency_list[current];
        while (neighbour)
        {
            if (not_visited(visited, list_index+1, neighbour->node_id))
            {
                
                addEdge(tree, current, neighbour->node_id);
                enqueue(queue, neighbour->node_id);
                visited[list_index] = neighbour->node_id;
                list_index++;
            }
            neighbour = neighbour->next;
        }            
    }

    return tree;
}

int shortest_dist(Graph* graph, int start, int end)
{
    if (start == end) return 0;
    int depth = 0;
    Graph* tree = spanning_tree(graph, start);
    int* stack = malloc(sizeof(int)*graph->N);
    int stack_index = 0;
    stack[stack_index] = start;
    stack_index++;
    while (stack_index > 0)
    {
        depth++;
        int current = stack[stack_index-1];
        stack_index--;
        Node* neighbour = tree->adjacency_list[current];
        while (neighbour)
        {
            stack[stack_index] = neighbour->node_id;
            stack_index++;
            if (neighbour->node_id == end) return depth;
            neighbour = neighbour->next;
        }
        
    }
    return INT_MAX;
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
    printGraph(spanning_tree(graph, 0));
    printf("\n");
    printf("Shortest distance : %d", shortest_dist(graph, 0, 5));
    return EXIT_SUCCESS;
}