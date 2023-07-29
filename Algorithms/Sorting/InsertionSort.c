#include <stdio.h>

void swap(int* array, int idx1, int idx2){
    int temp = array[idx1];
    array[idx1] = array[idx2];
    array[idx2] = temp;
}

void insertionSort(int* array, int array_size){
    int pointer = 1;
    while (pointer < array_size)
    {  
        int temp = array[pointer];
        for (int i=pointer-1;i>=0 && array[i] > temp; i--){
        swap(array, i, i+1);
        }
        pointer++;
    }
    
    
}
int main(void){
    //int array[] = {1, 6, 7, 4, 2, 9, 8, 5, 3};
    int array[] = {6,82,69,50,68,13,8,1,84,39,19,17,33,83,23,95,72,22,51,78,64,73,98,36,53,25,66,57,15,43,65,88,44,24,90,42,41,20,58,38,52,54,4,21,32,93,40,59,29,30,37,91,56,28,79,60,99,100,14,16,77,76,5,48,70,97,27,26,9,94,7,80,87,63,55,45,47,71,46,34,92,31,85,67,3,35,96,89,11,2,18,49,86,10,75,74,61,12,81,62};
    int array_size = 100;
    insertionSort(array, array_size);
    for (int i=0; i< array_size; i++){
        printf("%d ", array[i]);
    }

}