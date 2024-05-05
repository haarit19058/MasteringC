#include <stdio.h>
int main(){
    int c;
    int current = 0; // 0 for not a blank
    int count;
    while ((c = getchar()) != EOF){
        if (c == '\t' || c == ' '){
            current = 1;
        }
        else if (current == 1 && (c != ' ' || c != '\t' )){
            putchar(' ');
            current = 0;
            putchar(c);
        }
        else{
            putchar(c);
        }
    }
    return 0;
}