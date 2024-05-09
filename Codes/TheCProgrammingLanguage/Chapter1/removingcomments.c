#include <stdio.h>

int main() {
    int c, c1, c2;

    while ((c = getchar()) != EOF) {
        if (c != '"') {
            if (c == '/') {
                c1 = c;
                c = getchar();
                if (c == '/') { // Single-line comment
                    while (c != EOF && c != '\n') {
                        c = getchar();
                    }
                    if (c == EOF) break; // Exit loop if EOF is reached
                    putchar('\n');
                }
                else if (c == '*') { // Multi-line comment
                    c = getchar();
                    while (1) {
                        while (c != EOF && c != '*') {
                            c = getchar();
                            if (c == EOF) break; // Exit loop if EOF is reached
                        }
                        if (c == EOF) break; // Exit loop if EOF is reached
                        c = getchar();
                        if (c == '/') break; // Exit loop at end of multi-line comment
                    }
                }
                else { // Not a comment, print '/'
                    putchar(c1);
                }
            }
            else { // Not a comment or string, print character
                putchar(c);
            }
        }
        else { // Inside a string, print character
            putchar(c);
        }
    }

    return 0;
}
