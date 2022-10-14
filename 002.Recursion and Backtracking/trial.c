// calculates facotial of a positive integer

#include<stdio.h>

int Fact(int n){
    if (n==1){ // base case: fact of 0 or 1 is 1
        return 1;
    }else if (n==0){
        return 1;
    }else{ // recursive case: multiply n by (n-1) factorial
        return n*Fact(n-1);
    }
}

int Print(int n){
    if (n==0){ // base case
        return 0;
    }else{ // recursive case
        printf("%d \n",n);
        return Print(n-1);
    }
}

int main(){
    int n;
    printf("Enter a number :");
    scanf("%d", &n);
    // printf("Factorial of %d is %d",n,Fact(n)); //Fact
    Print(n);
    return 0;
}