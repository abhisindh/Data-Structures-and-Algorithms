// // Implementation using fixed sized array

#include <stdio.h>
#include <stdlib.h>



#define MAX_SIZE 10

typedef struct Queue{
    int* array;
    int start;
    int end;
}Queue;

Queue* create_queue(){
    Queue* queue = malloc(sizeof(Queue));
    int* array = malloc(MAX_SIZE*sizeof(int));
    queue->array = array;
    queue->start = -1;
    queue->end = -1;
    return queue;
}

int increment(int index){
    return (index+1)%MAX_SIZE;
}

int decrement(int index){
    return (index+MAX_SIZE-1) % MAX_SIZE;
}

int full(Queue* queue){
    if (increment(queue->end) == queue->start) return 1;
    return 0;
}

int empty(Queue* queue){
    if (queue->end == queue->start) return 1;
    return 0;
}
void enqueue(Queue* queue, int data){
    if (full(queue)){
        printf("out of range\n");
        return;
    }
    if (queue->start == -1) queue->start = 0; 
    
    queue->end = increment(queue->end);
    queue->array[queue->end] = data;

}

int dequeue(Queue* queue){
    if (empty(queue)) return -1;

    int index = increment(queue->start);
    int return_value = queue->array[queue->start];
    queue->start = index;
    return return_value;
}

void printQueue(Queue* queue){
    if (empty(queue)) return;
    int current;
    for (current=queue->start; current != queue->end; current = increment(current)){
        printf("%d, ", queue->array[current]);
    }
    printf("%d\n", queue->array[queue->end]);

    
}

int main(void){
    Queue* queue = create_queue();
    for (int i=0; i<10; i++){
        enqueue(queue, i);
    }
    printQueue(queue);

    for (int i=0; i<5; i++){
        dequeue(queue);
    }
    printQueue(queue);
    
    for (int i=0; i<5; i++){
        enqueue(queue, i);
    }
    printQueue(queue);

    for (int i=0; i<5; i++){
        dequeue(queue);
    }
    printQueue(queue);

    for (int i=0; i<6; i++){
        dequeue(queue);
    }
    printQueue(queue);
    return EXIT_SUCCESS;
}

