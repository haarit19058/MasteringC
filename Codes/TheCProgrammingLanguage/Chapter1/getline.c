#include <stdio.h>

void copy(int arr1[], int arr2[]){
    // int len_arr1 = sizeof(arr1)/sizeof(arr1[0]);
}

int main(){
    int arr1[]={2,5,6,1,2,0,8,4};
    int arr2[8]={0};
    copy(arr1,arr2);
    int len_arr2 = sizeof(arr2)/sizeof(arr2[0]);
    for (int i = 0;i<len_arr2;i++){
        printf("%d\n",arr2[i]);
    }
    return 0;
}