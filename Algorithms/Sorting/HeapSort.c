//================================ HEAP SORT USING HEAP DATASTRUCTURE====================================================
#include "../../DataStructures/Heap.c"
void heapSort(int* array, int array_size){
    Heap* heap = createVector();
    for (int i=0; i<array_size; i++){
        push(heap, array[i]);
    }
    heap = heapify(heap); // creates a min-heap with given list
    for (int i=0; i<array_size; i++){
        array[i] = extract_min(heap); // extracts the top element of heap to push to array and reorders the heap
    }
    deleteVector(heap);
}
//=====================================================================================================================



int main(void){
    int list[] = {6,82,69,50,68,13,8,1,84,39,19,17,33,83,23,95,72,22,51,78,64,73,98,36,53,25,66,57,15,43,65,88,44,24,90,42,41,20,58,38,52,54,4,21,32,93,40,59,29,30,37,91,56,28,79,60,99,100,14,16,77,76,5,48,70,97,27,26,9,94,7,80,87,63,55,45,47,71,46,34,92,31,85,67,3,35,96,89,11,2,18,49,86,10,75,74,61,12,81,62, INT_MIN};
    heapSort(list, 100);
    for (int i=0; list[i]!=INT_MIN; i++){
        printf("%d ", list[i]);
    }
    return 0;
}