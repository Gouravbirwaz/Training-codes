#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000  // Maximum DNA sequence length

// Function to count occurrences of a pattern in a DNA sequence
int countPatternOccurrences(char dnaSeq[], char pattern[]);

int main() {
    char dnaSeq[MAX_LENGTH], pattern[100];
    
    // Taking input for the DNA sequence
    printf("Enter DNA Sequence: ");
    scanf("%s", dnaSeq);

    // Taking input for the pattern to search
    printf("Enter pattern to search: ");
    scanf("%s", pattern);

    // Count occurrences of the pattern
    int count = countPatternOccurrences(dnaSeq, pattern);

    // Display the result
    printf("Pattern found %d time(s) in the DNA sequence.\n", count);

    return 0;
}

// Function to count occurrences of a pattern in a DNA sequence
int countPatternOccurrences(char dnaSeq[], char pattern[]) {
    int dnaLen = strlen(dnaSeq);
    int patternLen = strlen(pattern);
    int count = 0;

    for (int i = 0; i <= dnaLen - patternLen; i++) {
        int match = 1;
        for (int j = 0; j < patternLen; j++) {
            if (dnaSeq[i + j] != pattern[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            count++;
        }
    }

    return count;
}
