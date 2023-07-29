// Max Heap Implementation. Using Vector implementation (Dynamic array)

#include <stdio.h>
#include <stdlib.h>
#include "Vector.c"

typedef Vector Heap;

void swap(Heap* heap, int first, int second){
    int temp = heap->array[first];
    heap->array[first] = heap->array[second];
    heap->array[second] = temp;
}

int parent(int i){
    return (i-1)/2;
}

int leftChild(int i){
    return 2*i+1;
}

int rightChild(int i){
    return 2*i+2;
}

void sift_up(Heap* heap, int index){
    int parentIndex = parent(index);
    while (index > 0 && heap->array[index] < heap->array[parentIndex]){
        swap(heap, parentIndex, index);
        index = parentIndex;
        parentIndex = parent(index);
    }
}

void sift_down(Heap* heap, int index){
    int left = leftChild(index);
    while (left < heap->size){       
        int right = rightChild(index);
        int toSwap;
        if (right < heap->size && heap->array[right] < heap->array[left]){
            toSwap = right;
        }else{
            toSwap = left;
        }

        if (heap->array[toSwap] < heap->array[index]){
            swap(heap, index, toSwap);
            index = toSwap;
            left = leftChild(index);
        }else{
            return;
        }

        
    }
}

Heap* heapify(Vector* vector){
    for (int i=(vector->size/2)-1; i>=0; i--){
        sift_down(vector, i);
    }
    return vector;
}

void insert(Heap* heap, int value){
    push(heap, value);
    sift_up(heap, (heap->size)-1);
}

int get_min(Heap* heap){
     return heap->array[0];
}

int extract_min(Heap* heap){

    swap(heap, 0 , heap->size-1); // SWAP MIN WITH LAST ELEMENT
    int output = pop(heap); //remove last element;
    sift_down(heap, 0); // rearrange the top element
    return output;
}

// int main(void){
//     Vector* vector = createVector();
//     int list[] = {42, 17, 95, 63, 28, 5, 77, 10, 53, 32};
//     for (int i=0; i< 10; i++){
//         push(vector, list[i]);
//     }
//     Heap* heap = heapify(vector);
//     printVector(heap);
//     extract_max(heap);
//     printVector(heap);
// }