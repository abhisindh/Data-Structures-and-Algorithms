#include <stdio.h>

int linearSearch(int array[], int length, int item){
    for (int i=0; i<length; i++){
        if (array[i] == item){
            printf("Found!\n");
            return 1;
        }
    }
    printf("Not found!\n");
    return 0;
}

int binarySearch(int array[], int length, int target){
    int left = 0, right = length;
    while (left <= right){
        int mid = (left + right) / 2;
        if (array[mid] == target){
            return mid;
        }
        if (array[mid] < target){
            left = mid+1;
        }else if (array[mid] > target){
            right = mid-1;
        }
    }
    return -1;
}

int binarySearchRecursion(int array[], int left, int right, int target){
    int mid = (left + right)/2;
    if (left > right) return -1;
    if (array[mid] < target) return binarySearchRecursion(array, mid+1, right, target);
    if (array[mid] > target) return binarySearchRecursion(array, left, mid-1, target);
    return mid;
}

int main(void){
    int array[] = {1, 3, 5, 6, 144, 170};
    int length = 6;
    int target = 144;
    printf("%d\n", binarySearchRecursion(array, 0, length-1, target));
    return 0;
}