#include <stdio.h>

int main(){
    float fahr,celsius;
    float lower,upper,step;
    lower = 0;
    upper = 600;
    step = 10;
    fahr =lower;
    while(fahr<=upper){
        celsius = (5.00/9.00)*(fahr-32.00);
        printf("%4.0f %3.0f\n",fahr,celsius);
        fahr = fahr + step;
    }
    return 0;
}