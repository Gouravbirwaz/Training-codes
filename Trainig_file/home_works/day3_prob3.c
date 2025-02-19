#include <stdio.h>

#define MAX_MATCHES 100  

void findHighLowAvg(int scores[], int numMatches, int *highest, int *lowest, float *average);

int main() {
    int numMatches, scores[MAX_MATCHES];
    
    printf("Enter number of matches: ");
    scanf("%d", &numMatches);
    
    printf("Enter scores of %d matches: ", numMatches);
    for (int i = 0; i < numMatches; i++) {
        scanf("%d", &scores[i]);
    }

    int highest, lowest;
    float average;

    findHighLowAvg(scores, numMatches, &highest, &lowest, &average);

    printf("Highest Score: %d\n", highest);
    printf("Lowest Score: %d\n", lowest);
    printf("Average Score: %.2f\n", average);

    return 0;
}

void findHighLowAvg(int scores[], int numMatches, int *highest, int *lowest, float *average) {
    *highest = scores[0];
    *lowest = scores[0];
    int sum = 0;

    for (int i = 0; i < numMatches; i++) {
        if (scores[i] > *highest) {
            *highest = scores[i];
        }
        if (scores[i] < *lowest) {
            *lowest = scores[i];
        }
        sum += scores[i];
    }

    *average = (float)sum / numMatches;
}
