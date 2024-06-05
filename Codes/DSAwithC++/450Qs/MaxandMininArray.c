#include <stdio.h>


int max_or_min(int arr[], int size, int maxormin) {
    int index = maxormin ? -100000 : 100000;

    for (int i = 0; i < size; i++) {
        if (maxormin) {
            index = (arr[i] > index) ? arr[i] : index;
        } else {
            index = (arr[i] < index) ? arr[i] : index;
        }
    }

    return index;
}

int main(){
    int arr[] = {2,1,10,3,14,51,42,20,30,93,-1,-2,-13,-15,-46};
    int size= sizeof(arr)/sizeof(arr[0]);
    int result = max_or_min(arr,size,2);
    printf("%d",result);

    return 0;
}