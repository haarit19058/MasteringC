#include <stdio.h>
#include <conio.h>
#include <string.h>

int main() {
    char c;
    char text[1000] = {0}; // Initialize text buffer
    int cursor = 0; // Initialize cursor position

    while (1) {
        system("cls"); // Clear the screen on Windows

        // Print the text
        printf("%s\n", text);

        // Print spaces to move cursor
        for (int i = 0; i < cursor; i++) {
            printf(" ");
        }
        
        // Print cursor marker
        printf("^\n");

        c = _getch(); // Read a character from the terminal

        // Handle character input
        switch (c) {
            case 'q':
                printf("\n");
                return 0;
            case 8: // Handle backspace (ASCII code for backspace)
                if (cursor > 0) {
                    memmove(&text[cursor - 1], &text[cursor], strlen(&text[cursor]) + 1);
                    cursor--;
                }
                break;
            case 224: // Handle arrow keys
                switch (_getch()) {
                    case 77: // Right arrow
                        if (cursor < strlen(text))
                            cursor++;
                        break;
                    case 75: // Left arrow
                        if (cursor > 0)
                            cursor--;
                        break;
                }
                break;
            default:
                memmove(&text[cursor + 1], &text[cursor], strlen(&text[cursor]) + 1);
                text[cursor] = c;
                cursor++;
        }
    }

    return 0;
}
