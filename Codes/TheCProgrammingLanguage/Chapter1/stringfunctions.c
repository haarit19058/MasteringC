#include <stdio.h>

#define MAX_LINE_LENGTH 1000

char linecontainer[MAX_LINE_LENGTH];

char *getline() {
    int i = 0;
    char *ptr = linecontainer; // Pointer to iterate through linecontainer
    int c;

    while ((c = getchar()) != EOF && c != '\n' && i < MAX_LINE_LENGTH - 1) {
        *ptr++ = c; // Store the character in linecontainer
        i++;
    }

    *ptr = '\0'; // Null-terminate the string

    // Check if the line is empty and end of file is reached
    if (i == 0 && c == EOF) {
        return NULL;
    }

    return linecontainer; // Return pointer to the beginning of the string
}

void strip(char *line){
    int i = 0;
    while (line[i]!='\0'){

        
        
        i++;
    }
}



// Function to find the length of a string
int string_length(char *s) {
    int length = 0;
    while (*s != '\0') {
        length++;
        s++;
    }
    return length;
}

// Function to reverse a character string
void reverse_string(char *s) {
    int length = string_length(s);
    int i, j;
    char temp;
    
    // Swap characters from the beginning and end of the string
    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int main() {
    char *line;

    while ((line = getline()) != NULL) {
        printf("%s\n", line);
    }

    return 0;
}











// My Code

// #include <stdio.h>

// char linecontainer[1000];
// char *getline(){
//     extern char linecontainer;
//     int c,i;
//     i = 0;
//     c = getchar();
//     while (c != EOF && c != '\n'){
//         linecontainer[i] = c;
//         i++;        
//     }

//     linecontainer[i] = '\0';

//     return *linecontainer;

// }




// int main(){


//     return 0;
// }