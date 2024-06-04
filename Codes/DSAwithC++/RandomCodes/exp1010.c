#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[],int size){
    for(int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int *subArr(int arr[],int size,int *subArr[]){

    int index = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j <= i;j++){
            int *temparr = malloc((i-j+2)*sizeof(int));
            *temparr = i - j +1;
            // printf("%d:  ",*temparr);
            for(int k = j ,h = 1; k <= i; k++,h++){
                *(temparr+h) = arr[k];
                // printf("%d ",arr[k]);
                // printf("%d ",*(temparr+h));
            }
            // printf("\n");
            *(subArr+index++) = temparr;
            // printf("%d: %d ",i,**(subArr+j));
        }
    }

    return *subArr;
}


int main(){
    int arr[]={3,2,11,5,1,16,3,7,9,2,10,23,0,1,13};
    int lenArr = sizeof(arr)/sizeof(arr[0]);
    int numSubArr = ((lenArr*(lenArr+1))/2);
    int *subArrCollector[numSubArr];

    subArr(arr,lenArr,subArrCollector);
    printf("%d\n",numSubArr);

    int flag;
    for (int i = 0; i < numSubArr; i++){
        flag = 1;
        // printf("%d:%d",i,**(subArrCollector+i));
        for(int j =0; j< **(subArrCollector+i);j++){
            for(int k = 0;k<=j;k++){
            }
        }
        printf("\n");
    }

    return 0;
}






// #include <stdio.h>
// #include <stdlib.h>

// void printArr(int arr[], int size) {
//     for(int i = 0; i < size; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// void subArr(int arr[], int size, int *subArr[]) {
//     int index = 0;
//     for(int i = 0; i < size; i++) {
//         for(int j = 0; j <= i; j++) {
//             int subArrSize = i - j + 1;
//             int *temparr = malloc((subArrSize + 1) * sizeof(int));  // Allocate memory for subarray
//             temparr[0] = subArrSize;  // Store the size of the subarray at the beginning
//             for(int k = j, h = 1; k <= i; k++, h++) {
//                 temparr[h] = arr[k];  // Fill the subarray
//             }
//             subArr[index++] = temparr;  // Store the subarray pointer
//         }
//     }
// }

// int main() {
//     int arr[] = {3, 2, 11, 5, 1, 16, 3, 7, 9, 2, 10, 23, 0, 1, 13};
//     int lenArr = sizeof(arr) / sizeof(arr[0]);
//     int numSubArr = (lenArr * (lenArr + 1)) / 2;
//     int *subArrCollector[numSubArr];  // Collector for all subarrays

//     subArr(arr, lenArr, subArrCollector);
//     printf("Number of subarrays: %d\n", numSubArr);

//     // Print all subarrays
//     for (int i = 0; i < numSubArr; i++) {
//         int subArrSize = subArrCollector[i][0];  // Get the size of the subarray
//         printArr(subArrCollector[i] + 1, subArrSize);  // Print subarray skipping the size element
//         free(subArrCollector[i]);  // Free the allocated memory for each subarray
//     }

//     return 0;
// }

