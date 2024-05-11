// #include <stdio.h>

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












#include <stdio.h>
#include <stdbool.h>

char* strip(char* str) {
    if (!str || !*str) // Check for NULL or empty string
        return str;

    char* start = str;
    char* end = str;

    // Move start pointer to the first non-whitespace character
    while (*start && (*start == ' ' || *start == '\t' || *start == '\n')) {
        start++;
    }

    // Move end pointer to the last non-whitespace character
    char* lastNonSpace = NULL;
    while (*end) {
        if (*end != ' ' && *end != '\t' && *end != '\n') {
            lastNonSpace = end;
        }
        end++;
    }

    // If lastNonSpace is found, move one position further
    if (lastNonSpace != NULL) {
        end = lastNonSpace + 1;
    }

    // Copy the stripped part to the beginning of the string
    while (start <= end) {
        *str++ = *start++;
    }
    *str = '\0'; // Add null terminator

    return str;
}

int main() {
    char str[] = "   Hello, World!   ";
    printf("Before stripping: '%s'\n", str);
    strip(str); // Modify the string in-place
    printf("After stripping: '%s'\n", str); // Print the modified string
    return 0;
}
