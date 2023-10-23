// Implementation using Linked List.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Queue Queue;

struct Node{
    void* data;
    Node* next;
};

struct Queue{
    Node* head;
    Node* tail;
};

Queue* createQueue(){
    Queue* queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

Node* createNode(void* data){
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

int empty(Queue* queue){
    if (queue->head == NULL && queue->tail == NULL) return 1;
    return 0;
}
void enqueue(Queue* queue, void* data){
    Node* new_node = createNode(data);
    if (empty(queue)){
        queue->head = queue->tail = new_node;
        return;
    } 
    queue->tail->next = new_node;
    queue->tail = new_node;
}

void* dequeue (Queue* queue){
    if (empty(queue)) return NULL;
    if (queue->head == queue->tail) queue->tail = NULL;
    Node* current = queue->head;
    queue->head = current->next;
    void* return_value = current->data;
    free(current);
    return return_value;
}

void print_queue(Queue* queue){
    if (!empty(queue)){
        printf("head -> ");
        Node* current = queue->head;
        while (current){
            printf("%p ", current->data);
            current = current->next;
        }
        printf("<- tail");
    }
}

int main(void){
    Queue* queue = createQueue();
    for (int i=0; i<5; i++){
        int* pointer = malloc(sizeof(int));
        *pointer = i;
        enqueue(queue, pointer);
    }
    print_queue(queue);


    return EXIT_SUCCESS;
}