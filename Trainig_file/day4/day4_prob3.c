#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void countWordsAndLines(char filename[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    int lineCount = 0;
    int wordCount = 0;
    char line[1024];

    while (fgets(line, sizeof(line), file)) {
        lineCount++;

        char *token = strtok(line, " \t\n\r"); // Tokenize by spaces, tabs, newlines, and carriage returns.
        while (token != NULL) {
            wordCount++;
            token = strtok(NULL, " \t\n\r");
        }
    }

    fclose(file);

    printf("Total Lines: %d\n", lineCount);
    printf("Total Words: %d\n", wordCount);
}

int main() {
    char filename[] = "data.txt";
    countWordsAndLines(filename);
    return 0;
}
