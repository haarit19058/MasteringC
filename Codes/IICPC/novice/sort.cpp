#include <algorithm> 
//contains sort() under namespace of std
#include <iostream> 

using namespace std;

int* copyArr(int arr[],int size){
    int *newArr = new int[size];

    for(int i = 0; i<size; i++){
        newArr[i] = arr[i];
    }

    return newArr;
}

int main() 
{ 
	int arr[] = {53,71,-63,95,36,48,-25,-75,19,2,0,5,-1,43,-334,56,77};
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    int *newArr = copyArr(arr,arrSize);
    sort(newArr,newArr+arrSize);
    for (int i = 0; i<arrSize; i++){
        cout<<newArr[i]<< " ";
    }
    cout << endl;

    int *newArr2 = copyArr(arr,arrSize);
    sort(newArr2,newArr2+6);
    for (int i = 0; i<arrSize; i++){
        cout<<newArr2[i]<< " ";
    }
    cout << endl;






    for(int i : arr){
        cout << i << " ";
    }
    cout<<endl;

    free(newArr);

	return 0; 
} 
