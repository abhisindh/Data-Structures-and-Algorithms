// mutable array with automatic resizing

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>



typedef struct Vector{
    int size;
    int capacity;
    int* array;
}Vector;

int minmax(Vector* vector, int index){
    if (index<0) return 0;
    if (index>vector->size) return vector->size;
    return index;
}

void resize(Vector* vector, int new_capacity){
    int* new_array = malloc(new_capacity*sizeof(int));
    for (int i=0; i<vector->size; i++){
        new_array[i] = vector->array[i];
    }
    free(vector->array);
    vector->array = new_array;
    vector->capacity = new_capacity;
}

Vector* createVector(){
    Vector* new_vector = malloc(sizeof(Vector));
    new_vector->size = 0;
    new_vector->capacity = 16;
    new_vector->array = malloc(new_vector->capacity*sizeof(int));
    if (new_vector == NULL){
        printf("ERROR!!!  caught error with number %d", errno);
    }
    return new_vector;
}

int size(Vector* vector){
    if (!vector){
        printf("Vector does not exists.Returning zero...\n");
        return 0;
    }
    return vector->size;
}

int capacity(Vector* vector){
    if (!vector){
        printf("Vector does not exists.Returning zero...\n");
        return 0;
    }
    return vector->capacity;  
}

int is_empty(Vector* vector){
    if (!vector){
        printf("Vector does not exists.Returning one...\n");
        return 1;
    }
    if (vector->size == 0){
        return 1;
    }
    return 0;
}

int at(Vector* vector, int index){
    if (!vector){
        printf("Vector does not exists.Returning zero...\n");
        return 0;
    }
    if (index > vector->size){
        printf("Index out of range. Returning zero...\n");
        return 0;
    }
    return *(vector->array + index);
}

void push(Vector* vector, int data){
    if (vector->size >= vector->capacity){
        resize(vector, 1.5*vector->capacity);
    }
    vector->array[(++vector->size)-1] = data;
}

void vector_insert(Vector* vector, int index, int item){
    index = minmax(vector, index);
    if (vector->size >= vector->capacity){
        resize(vector, 1.5*vector->capacity);
    }
    for (int i=vector->size; i > index; i--){
        vector->array[i] = vector->array[i-1];
    }
    vector->array[index] = item;   
    vector->size++;
}

void prepend(Vector* vector, int item){
    vector_insert(vector, 0, item);
}

int pop(Vector* vector){
    return at(vector, --vector->size);
}

void delete(Vector* vector, int index){
    index = minmax(vector, index);
    for (int i=index; i<vector->size; i++){
        vector->array[i] = at(vector, i+1);
    }
    vector->size--;
}

void removeItem(Vector* vector, int item){
    int writeIndex = 0;
    for (int readIndex=0; readIndex<vector->size; readIndex++){
        if (vector->array[readIndex] != item){
            vector->array[writeIndex] = vector->array[readIndex];
            writeIndex++;
        }
    }
    vector->size = writeIndex;
}

int find(Vector* vector, int item){
    for (int i=0; i<vector->size;i++){
        if (vector->array[i] == item){
            return i;
        }
    }
    return -1;
}

void printVector(Vector* vector){
    for (int i=0; i<vector->size; i++){
        printf("%d ", at(vector,i));
    }
    printf("\n");
}

void deleteVector(Vector* vector){
    free(vector->array);
    free(vector);
}

