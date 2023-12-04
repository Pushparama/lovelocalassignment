#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char* str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1; 
}

char* shortestPalindrome(char* s) {
    int n = strlen(s);

    
    int end = n - 1;
    while (end > 0 && !isPalindrome(s, 0, end)) {
        end--;
    }

   
    char* result = (char*)malloc((2 * n - end - 1) * sizeof(char));
    int j = 0;
    for (int i = n - 1; i > end; i--) {
        result[j++] = s[i];
    }
    for (int i = 0; i < n; i++) {
        result[j++] = s[i];
    }
    result[j] = '\0';

    return result;
}

int main() {
    char s[100];  
    
    scanf("%s", s);

    char* result = shortestPalindrome(s);

    
    printf(" %s\n", result);

    free(result);

    return 0;
}

