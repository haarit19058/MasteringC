#include <stdio.h>

#define MAX_STACK_SIZE 100

typedef struct {
    char type; // '(', '[', '{', '"', or '''
    int line;  // line number where the character is found
} StackItem;

int top = -1;
StackItem stack[MAX_STACK_SIZE];

void push(char type, int line) {
    if (top < MAX_STACK_SIZE - 1) {
        top++;
        stack[top].type = type;
        stack[top].line = line;
    } else {
        printf("Stack overflow\n");
    }
}

char pop() {
    if (top >= 0) {
        top--;
        return stack[top + 1].type;
    } else {
        printf("Stack underflow\n");
        return '\0';
    }
}

int main() {
    int c;
    int line_number = 1;
    int in_comment = 0;
    int in_string = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            line_number++;
        } else if (c == '"') {
            if (!in_comment) {
                if (in_string) {
                    if (stack[top].type == '"') {
                        pop();
                    }
                    in_string = 0;
                } else {
                    push('"', line_number);
                    in_string = 1;
                }
            }
        } else if (c == '\'') {
            if (!in_comment && !in_string) {
                if (stack[top].type == '\'') {
                    pop();
                } else {
                    push('\'', line_number);
                }
            }
        } else if (c == '/') {
            if (!in_comment && !in_string) {
                int next_char = getchar();
                if (next_char == '*') {
                    in_comment = 1;
                } else {
                    ungetc(next_char, stdin);
                }
            }
        } else if (c == '*') {
            if (in_comment && !in_string) {
                int next_char = getchar();
                if (next_char == '/') {
                    in_comment = 0;
                } else {
                    ungetc(next_char, stdin);
                }
            }
        } else if (c == '(' || c == '[' || c == '{') {
            if (!in_comment && !in_string) {
                push(c, line_number);
            }
        } else if (c == ')' || c == ']' || c == '}') {
            if (!in_comment && !in_string) {
                if (top >= 0 && ((c == ')' && stack[top].type == '(') ||
                                 (c == ']' && stack[top].type == '[') ||
                                 (c == '}' && stack[top].type == '{'))) {
                    pop();
                } else {
                    printf("Error: Unmatched %c at line %d\n", c, line_number);
                }
            }
        }
    }

    if (top >= 0) {
        printf("Error: Unmatched %c at line %d\n", stack[top].type, stack[top].line);
    }

    return 0;
}
