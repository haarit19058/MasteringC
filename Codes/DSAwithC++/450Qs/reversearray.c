#include <stdio.h>
#include <stdlib.h>

void reverseArray(int arr[],int size){
    int temp;
    for (int i = 0;i<(size)/2;i++){
        temp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = temp;
    }
}

int* rA(int arr[],int size){
    int *newArr = malloc(sizeof(int)*size);

    for(int i = 0; i < size ; i++){
        *(newArr+i) = arr[size-i-1];
    }

    return newArr;
}


int main(){
    int arr[]={1,2,3,4,5,6,7};
    int sizeArr = sizeof(arr)/sizeof(arr[0]);
    int *newArr = rA(arr,sizeArr);
    printf("%d\n",sizeArr);
    reverseArray(arr,sizeArr);
    for(int i = 0; i < sizeArr;i++){
        printf("%d ",*(newArr+i));
    }
    printf("\n");
    return 0;
}