#include <stdio.h>
#define maxwords 1000

int main() {
    int wordlengths[maxwords] = {0};

    int c = 0;
    int current = 0; // Flag to indicate if currently inside a word
    int len = 0;     // Length of current word
    int counter = 0; // Index for wordlengths array

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (current == 1) {
                wordlengths[counter++] = len;
                len = 0;
            }
            current = 0; // Not inside a word
        } else {
            len++; // Inside a word, increment length
            current = 1;
        }
    }


    int maxlength = 0;
    for (int i = 0; i < counter; i++){
        if (wordlengths[i]>maxlength){
            maxlength = wordlengths[i];
        }
    }

    int rows = maxlength;


    // Output word lengths
    // Output vertical histogram
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = 0; j < counter; j++) {
            if (wordlengths[j] > i) {
                printf("# ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }


    return 0;
}
