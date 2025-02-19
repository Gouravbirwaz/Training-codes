#include <stdio.h>
#include <string.h>

int findSubstring(char str[], char sub[]) {
    int strLen = strlen(str);
    int subLen = strlen(sub);

    if (subLen > strLen) {
        return -1; // Substring cannot be longer than the main string
    }

    for (int i = 0; i <= strLen - subLen; i++) {
        int j;
        for (j = 0; j < subLen; j++) {
            if (str[i + j] != sub[j]) {
                break; // Mismatch, break inner loop
            }
        }
        if (j == subLen) { // If inner loop completed without a break, it's a match
            return i; // Return starting index
        }
    }

    return -1; // Substring not found
}

int main() {
    char str[1000];
    char sub[1000];

    printf("Enter main string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove trailing newline

    printf("Enter substring: ");
    fgets(sub, sizeof(sub), stdin);
    sub[strcspn(sub, "\n")] = 0; // Remove trailing newline

    int index = findSubstring(str, sub);

    if (index != -1) {
        printf("Substring found at index: %d\n", index);
    } else {
        printf("Substring not found.\n");
    }

    return 0;
}
