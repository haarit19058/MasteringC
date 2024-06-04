#include <iostream>
using namespace std;


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
        // i--;
        sum = 10* sum + arr[i];
    }

    return sum;
}


int binarytodecimal(int n,int arr[]){
    int temp = 0,i = 0;
    while(n>0){
        temp = n % 10;
        arr[i] = temp;
        i++;
        n = n/10;
    }
    int sum = 0, j = 0;
    int multiplier = 1;
    while(j < i){
        // cout<<arr[j]<<endl;
        sum = multiplier * arr[j] + sum;
        multiplier = 2 * multiplier;
        j++;
    }
    return sum;
}

int main(){ 
    int arr[100];
    int bin = 110101;
    int dec = binarytodecimal(bin,arr);
    cout << dec <<endl << bin << endl;
    return 0;
}