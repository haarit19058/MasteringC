// #include <stdio.h>

// void expand(char str[], char s2[]) {

//     int i;
//     char* start = str;
//     char* end = str;
//     char *temp1,*temp2;

//     // Move start pointer to the first non-whitespace character
//     while (*start && (*start == ' ' || *start == '\t' || *start == '\n' || *start == '-')) {
//         start++;
//     }

//     // Move end pointer to the last non-whitespace character
//     char* lastNonSpace = NULL;
//     while (*end) {
//         if (*end != ' ' && *end != '\t' && *end != '\n' && *end != '-') {
//             lastNonSpace = end;
//         }
//         end++;
//     }

//     // If lastNonSpace is found, move one position further
//     if (lastNonSpace != NULL) {
//         end = lastNonSpace + 1;
//     }

//     while (*start++ == *end )
//     {
//         if (*start == '-'){
//             *temp1 = *(start-1);
//             *temp2 = *(start+1);
//             while (*temp1++ != *temp2+1){
//                 s2[i]=*temp1;
//                 i++;
//             }
//         }
//     }
    
// }

// int main() {
//     char s1[] = "a-z A-Z 0-9";
//     char s2[100];
//     expand(s1, s2);
//     printf("Expanded string: %s\n", s2);
//     return 0;
// }















#include <stdio.h>

void expand(char s1[], char s2[]) {
    int i, j;
    char c;

    i = j = 0;
    
    // Handle leading '-' literally
    if (s1[i] == '-')
        s2[j++] = s1[i++];

    while ((c = s1[i++]) != '\0') {
        // Handle a-z, A-Z, 0-9
        if (s1[i] == '-' && s1[i + 1] >= c) {
            i++; // Skip the '-'
            while (c < s1[i])
                s2[j++] = c++;
        } 
        else {
            s2[j++] = c;
        }
    }

    // Handle trailing '-' literally
    if (s2[j - 1] == '-')
        s2[j++] = '-';
    
    s2[j] = '\0';
}


/* itoa:  convert n to characters in s */ 
void itoa(int n, char s[]) 
{ 
    int i, sign; 
    if ((sign = n) < 0)  /* record sign */ 
        n = -n;          /* make n positive */ 
    i = 0; 
    do {      /* generate digits in reverse order */ 
        s[i++] = n % 10 + '0';  /* get next digit */ 
    } while ((n /= 10) > 0);    /* delete it */ 
    if (sign < 0) 
        s[i++] = '-'; 
    s[i] = '\0'; 
    reverse(s); 
} 

int main() {
    char s1[] = "a-z A-Z 0-9";
    char s2[100];
    expand(s1, s2);
    printf("Expanded string: %s\n", s2);
    return 0;
}
