#include <stdio.h>

float atof(char s[]){
    float num;
    int temp =0 ;
    int i=0;
    while (s[i] != '\0'){
        temp = s[i] - '0';
        if ( 0<=temp<=9){
            num = 10*num + temp;
        }
        i++;
    }
    return num;
}



int main(){

    char s[] = "123.45e-6";
    // printf("%s");
    return 0;
}