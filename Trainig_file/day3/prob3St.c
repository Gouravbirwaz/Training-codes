#include <stdio.h>
#include <string.h>
#include <ctype.h> // For tolower and isalnum

int isPalindrome(char str[]) {
    int len = strlen(str);
    int i = 0, j = len - 1;

    while (i < j) {
        // Skip non-alphanumeric characters from the left
        while (i < j && !isalnum(str[i])) {
            i++;
        }

        // Skip non-alphanumeric characters from the right
        while (i < j && !isalnum(str[j])) {
            j--;
        }

        // Compare characters (case-insensitive)
        if (i < j && tolower(str[i]) != tolower(str[j])) {
            return 0; // Not a palindrome
        }

        i++;
        j--;
    }

    return 1; // It's a palindrome
}

int main() {
    char str[1000];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove trailing newline

    if (isPalindrome(str)) {
        printf("Yes, it's a palindrome.\n");
    } else {
        printf("No, it's not a palindrome.\n");
    }

    return 0;
}
