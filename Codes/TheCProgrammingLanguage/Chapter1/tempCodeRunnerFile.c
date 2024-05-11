#include <stdio.h>

// char* strip(char* str) {
//     // find the start index of the string without leading whitespace
//     int start = 0;
//     while (str[start] == ' ' || str[start] == '\t' || str[start] == '\n') {
//         start++;
//     }

//     // find the end index of the string without trailing whitespace
//     int end = 0;
//     while (str[end] != '\0') {
//         end++;
//     }
//     end--;

//     while (str[end] == ' ' || str[end] == '\t' || str[end] == '\n') {
//         end--;
//     }

//     // shift characters to the beginning of the string
//     int i;
//     for (i = 0; i <= end - start; i++) {
//         str[i] = str[start + i];
//     }

//     // add null terminator to the end of the new string
//     str[i] = '\0';

//     return str;
// }

// int main() {
//     char str[] = "   Hello, World!   ";
//     printf("Before stripping: '%s'\n", str);
//     printf("After stripping: '%s'\n", strip(str));
//     return 0;
// }




