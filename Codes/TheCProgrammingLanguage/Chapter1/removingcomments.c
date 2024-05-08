#include <stdio.h>

int main() {
    int c, prev_c = '\0'; // prev_c stores the previous character read
    int inside_single_line_comment = 0; // Flag to track single-line comment
    int inside_multi_line_comment = 0; // Flag to track multi-line comment

    while ((c = getchar()) != EOF) {
        if (!inside_single_line_comment && !inside_multi_line_comment) {
            if (c == '/') {
                if (prev_c == '/') {
                    // Start of single-line comment
                    inside_single_line_comment = 1;
                } else if (prev_c == '*') {
                    // Start of multi-line comment
                    inside_multi_line_comment = 1;
                }
            }
        } else if (inside_single_line_comment) {
            if (c == '\n') {
                // End of single-line comment
                inside_single_line_comment = 0;
            }
        } else if (inside_multi_line_comment) {
            if (prev_c == '*' && c == '/') {
                // End of multi-line comment
                inside_multi_line_comment = 0;
                prev_c = '\0'; // Reset prev_c to avoid outputting '/'
                continue;
            }
        } else {
            // Inside a comment, skip characters
            prev_c = c;
            continue;
        }

        if (!inside_single_line_comment && !inside_multi_line_comment) {
            // Print character only if not inside any comment
            putchar(c);
        }

        prev_c = c;
    }

    return 0;
}
































// My COde
// #include <stdio.h>

// int main(){
//     int c,counter;

//     while((c = getchar()) != EOF){
//         if (c == '/' && counter == 0){
//             counter = 1;
//         }
//         if (c == '/' && counter == 1){
//             counter = 2;
//         }
//         if (c == '\n'){
//             counter = 0;
//         }
//         if (counter == 0 || counter ==1){
//             putchar(c);
//         }
//     }
    
//     return 0;
// }