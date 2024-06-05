#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[],int len){
    for(int i=0; i<len;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void swap(int *i, int *j) {
    int temp = *j;
    *j = *i;
    *i = temp;
}

int partition(int arr[],int leftind,int rightind){
    int partindex;
    int i = leftind+1,j = rightind;
    int temp;
    while(i!=j){
        while(arr[i]<=arr[leftind] && i <j) i++;
        while(arr[j]>arr[leftind] && i<j) j--;
        swap(arr+j,arr+i);  
    }

    swap(&arr[leftind],&arr[i-1]);
    partindex = i-1;
    return partindex;
}

void quickSort(int arr[], int leftind, int rightind) {
    if (leftind < rightind) {
        int temp = partition(arr, leftind, rightind);
        quickSort(arr, leftind, temp);
        quickSort(arr, temp + 1, rightind);
    }
}

int* joinTwoArrays(int arr1[],int size1,int arr2[],int size2){
    int *newarr = malloc((size1+size2+1)*sizeof(int));
    *newarr = size1+size2;
    int i=0,j=0;
    while(i+j<size1+size2 && i<size1 && j<size2){
        if (arr1[i]>arr2[j]){
            *(newarr+i+j+1) = arr2[j];
            // printf("%d -> %d\n",arr2[j],j);
            j++;
        }
        else{
            *(newarr+i+j+1) = arr1[i];
            // printf("%d -> %d\n",arr1[i],i);
            i++;
        }
    }

    while(i<size1){
        // printf("%d -> %d\n",arr2[j],i);
        *(newarr+i+j+1) = arr1[i];
        i++;
    }
    while(j<size2){
        // printf("%d -> %d\n",arr2[j],j);
        *(newarr+i+j+1) = arr2[j];
        j++;
    }
    return newarr;
}

int* mergeSort(int arr[],int left,int right){
    if (left == right) {
        int *singleElementArr = malloc(2 * sizeof(int));
        singleElementArr[0] = 1;
        singleElementArr[1] = arr[left];
        return singleElementArr;
    }


    int mid = (left+right)/2;

    int *new_left = mergeSort(arr,left,mid);
    int *new_right = mergeSort(arr,mid+1,right);
    int *newarr = joinTwoArrays((new_left+1),*new_left,(new_right+1),*new_right);

    free(new_left);
    free(new_right);

    return newarr;
}

int kthminmax(int arr[],int left,int right,int k){
    // finding the kth number in an array
    if (left<=right){

    int pt = partition(arr,left,right);
    // printf("%d  ",pt);
    if (pt>k) return kthminmax(arr,left,pt,k);
    else if(pt < k) return kthminmax(arr,pt+1,right,k);
    else return arr[pt];
    }

    return -1;
}

int main(){
    int arr[]={3,10,-10,4,23,-14,18,26,47,-16,-25,24,14,-23,2};
    int len = sizeof(arr)/sizeof(arr[0]);
    printf("%d",kthminmax(arr,0,len,3));
    // int arr1[] = {1,2,3,8,10};
    // int arr2[] = {-10,-3,4,5,6,8,9,11,12};
    // int size1 = sizeof(arr1)/sizeof(arr1[0]);
    // int size2 = sizeof(arr2)/sizeof(arr2[0]);
    // int *new = mergeSort(arr,0,len);
    // printArr(new+1,*new);


    return 0;
}