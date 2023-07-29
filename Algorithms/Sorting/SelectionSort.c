// Selection sort implementation
#include <stdio.h>
#include <stdlib.h>

void swap(int* array, int idx1, int idx2){
    int temp = array[idx1];
    array[idx1] = array[idx2];
    array[idx2] = temp;
}
void selectionSort(int* array, int array_size){
    int sort_idx = 0;
    int min_idx;
    while (sort_idx < array_size){
        int current_min = INT_MAX;
        min_idx = sort_idx;

        for (int i=sort_idx; i<array_size; i++){
            if (array[i] < current_min){
                min_idx = i;
                current_min = array[i];
            }
        }
        swap(array, sort_idx, min_idx);
        sort_idx++;

    }

    
}

int main(void){
    int list[] = {6,82,69,50,68,13,8,1,84,39,19,17,33,83,23,95,72,22,51,78,64,73,98,36,53,25,66,57,15,43,65,88,44,24,90,42,41,20,58,38,52,54,4,21,32,93,40,59,29,30,37,91,56,28,79,60,99,100,14,16,77,76,5,48,70,97,27,26,9,94,7,80,87,63,55,45,47,71,46,34,92,31,85,67,3,35,96,89,11,2,18,49,86,10,75,74,61,12,81,62};
    //int list[] ={82,25,8,67,21,58,99,70,80,94};
    int array_size = 100;
    selectionSort(list, array_size);
    for (int i=0; i<array_size; i++){
        printf("%d ", list[i]);
    }
    return 0;
}