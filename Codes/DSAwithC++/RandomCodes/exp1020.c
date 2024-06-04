#include <stdio.h>

int main(){
    int j = 5, k = 8;
    int *arr[2]={&j,&k};
    printf("%d   %d\n",*arr[0],*arr[1]); 

    int arr1[2] = {10,1};
    int arr2[2] = {2,30};

    int *arrOfArr[2] = {arr1,arr2};

    printf("%d %d %d %d\n",*arrOfArr[0],*(arrOfArr[0]+1),*arrOfArr[1],*(arrOfArr[1]+1));

    return 0;
}