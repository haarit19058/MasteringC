#include <stdio.h>

int decimaltobinary(int n,int arr[]){
    int rem=0,i=0;
    while(n>0){
        rem = n % 2;
        arr[i] = rem;
        n = n/2;
        i++;
    }
    int sum = 0;
    while(--i>=0){
        sum = 10* sum + arr[i];
        // i--;
    }

    return sum;
}

int main(){ 
    int arr[100];
    int dec = 53;
    int bin = decimaltobinary(dec,arr);
    printf("%d",bin);
    return 0;
}