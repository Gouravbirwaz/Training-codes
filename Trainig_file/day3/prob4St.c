#include <stdio.h>

int mostFrequentElement(int arr, int n) {
    int frequency = {0}; // Assuming elements are in the range 0-999. Adjust if needed.
    int maxFrequency = 0;
    int mostFrequent = -1;

    for (int i = 0; i < n; i++) {
        frequency[arr[i]]++;
        if (frequency[arr[i]] > maxFrequency) {
            maxFrequency = frequency[arr[i]];
            mostFrequent = arr[i];
        } else if (frequency[arr[i]] == maxFrequency && arr[i] < mostFrequent) {
            mostFrequent = arr[i]; // Choose the smaller one if frequencies are equal
        }
    }
    printf("Most Frequent Element: %d (occurs %d times)\n", mostFrequent, maxFrequency);
    return mostFrequent;
}

int main() {
    int n;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[n]; // VLA (Variable Length Array) - C99 and later

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mostFrequentElement(arr, n);


    return 0;
}
