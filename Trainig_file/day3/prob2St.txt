#include <stdio.h>
#include <string.h>

void reverseWord(char *start, char *end) {
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void reverseWords(char str[]) {
    int len = strlen(str);
    if (len == 0) return;

    reverseWord(str, str + len - 1);

    char *start = str;
    for (char *end = str; *end != '\0'; end++) {
        if (*end == ' ') {
            reverseWord(start, end - 1);
            start = end + 1;
        }
    }

    reverseWord(start, str + len - 1);
}

int main() {
    char str[1000];

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    reverseWords(str);

    printf("Reversed Sentence: %s\n", str);

    return 0;
}
