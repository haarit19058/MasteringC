#include <stdio.h>

void squeeze(char s1[], char s2[]) {
    int i, j, k;
    int match;

    for (i = j = 0; s1[i] != '\0'; i++) {
        match = 0; // Initialize match flag for each character in s1
        for (k = 0; s2[k] != '\0'; k++) {
            if (s1[i] == s2[k]) {
                match = 1; // Set match flag if s1[i] matches any character in s2
                break;
            }
        }
        if (!match) {
            s1[j++] = s1[i]; // Copy character from s1 to s1 if no match is found in s2
        }
    }
    s1[j] = '\0'; // Null-terminate the modified string s1
}

int main() {
    char s1[] = "hellosredrfgh";
    char s2[] = "world";

    squeeze(s1, s2);

    printf("Modified string: %s\n", s1);

    return 0;
}
