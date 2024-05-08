#include <stdio.h>

#define TAB_STOP 14  // Change this to the desired tab stop

int main() {
    int c;
    int column = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int spaces_to_next_tab_stop = TAB_STOP - (column % TAB_STOP);
            for (int i = 0; i < spaces_to_next_tab_stop; ++i) {
                putchar(' ');
                ++column;
            }
        } else if (c == '\n') {
            putchar(c);
            column = 0; // Reset column count for new line
        } else {
            putchar(c);
            ++column;
        }
    }

    return 0;
}
