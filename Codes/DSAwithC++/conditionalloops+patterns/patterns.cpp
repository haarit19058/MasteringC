#include <iostream>
#include <stdio.h>
using namespace std;


void square(int rows,int cols){
    for(int i=1;i<=rows;i++){
        for(int j = 1 ;j <=cols; j++){
            printf("%4d",i+j*i);
        }
        cout<<endl;
    }
}

void hollowrectangle(int rows,int cols){
    for (int i = 1; i<=rows; i++){
        for (int j = 1; j<=cols; j++){
            if(i == 1 || j == 1  || i == rows || j == cols)
                cout<<"*";
            else
                cout<<" ";
        }
        cout<<endl;
    }
}

void halfpyramid(int n){
    for (int i = 0; i<n; i++){
        for (int j = 0;j<i;j++){
            cout<<"* ";
        }
        cout << endl;
    }

}

void invertedhalfpyramid(int n){
    for (int i = 0; i<n; i++){
        for (int j = n-i-1;j>=0;j--){
            cout<<"* ";
        }
        cout << endl;
    }

}

void numeric_half_pyramid(int n){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            cout << j << " ";
        }
        cout << endl;
    }
}

void inverted_numeric_half_pyramid(int n){
    for (int i = 1; i <= n; i++){
        for (int j = n-i+1; j >= 1; j--){
            cout << j << " ";
        }
        cout << endl;
    }
}

void inverted_numeric_half_pyramid_rightaligned(int n){
    for (int i = 1; i <= n; i++){
        for(int j = 0;j<i;j++){
            cout<<"  ";
        }
        for (int j = n-i+1; j >= 1; j--){
            cout << j << " ";
        }
        cout << endl;
    }
}

void fullpyramid_odd(int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j<n-i; j++){
            cout<< "  ";
        }
        for (int j = 0; j < 2*i +1;j++){
            cout << "* ";
        }
        cout<<endl;
    }
}

void fullpyramid_all(int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j<n-i; j++){
            cout<< " ";
        }
        for (int j = 0; j < i ;j++){
            cout << "* ";
        }
        cout<<endl;
    }
}

void invertedFullPyramidAll(int n){
    for (int i = n; i >= 1; i--){
        for (int j = 0; j<n-i; j++){
            cout<< " ";
        }
        for (int j = 0; j < i ;j++){
            cout << "* ";
        }
        cout<<endl;
    }
}

void diamond(int n){

    fullpyramid_all(n);
    invertedFullPyramidAll(n);
}


void hollowpyramid(int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j<n-i; j++){
            cout<< " ";
        }
        for (int j = 0; j < i; j++){
            if (j == 0 || j == i-1){
                cout << "* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout << endl;
    }
}


void hollowpyramidInverted(int n){
    for (int i = n; i > 0; i--){
        for (int j = 0; j<n-i; j++){
            cout<< " ";
        }
        for (int j = 0; j < i; j++){
            if (j == 0 || j == i-1){
                cout << "* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout << endl;
    }
}


void hollowDiamond(int n){
    hollowpyramid(n);
    hollowpyramidInverted(n);
}


void squareWithDiamondCut(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (n - i); j++) {
            cout << "* ";
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "  "; 
        }
        for (int j = 0; j < (n - i); j++) {
            cout << "* ";
        }
        cout << endl;
    }

    for (int i = n; i >= 0; i--) {
        for (int j = 0; j < (n - i); j++) {
            cout << "* ";
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "  "; 
        }
        for (int j = 0; j < (n - i); j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void numberpattern1(int n){
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 2 * i - 1; j++){
            if (j%2==0)
                cout << i;
            else    
                cout << "*";
        }
        cout << endl;
    }

    for (int i = n-1; i > 0; i--){
        for (int j = 0; j< 2 * i - 1; j++ ){
            if (j%2==0)
                cout<<i;
            else    
                cout << "*";
        }
        cout << endl;
    }
}

void numberpattern2(int n){
    for (int i = 1; i <= n; i++){
        if (i!=1)
        cout << 1 <<" ";
        if (i==n){
            for (int j = 2;j <= n;j++){
                cout <<j<<" ";
            }
        }
        else{
            for (int j = 1; j < i-1;j++){
                cout << "  ";
            }
            cout<<i;
        }
        cout << endl;
    }
}


void characterpattern(int n){
    for(int row = 0; row < n; row++ ){
        for (int col = 0; col<row+1; col++){
            char ch = col + 'A';
            cout << ch;
        }
    cout << endl;
    }
}



int main(){
    characterpattern(8);

    return 0;
}