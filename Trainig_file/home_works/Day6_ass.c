include <stdio.h>
#include <stdlib.h>

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void display_ambulances(int distances[], int n) {
    printf("Sorted Distances: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", distances[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of ambulances: ");
    scanf("%d", &n);
    
    int distances[n];
    for (int i = 0; i < n; i++) {
        printf("Enter distance for ambulance %d: ", i + 1);
        scanf("%d", &distances[i]);
    }
    
    selection_sort(distances, n);
    display_ambulances(distances, n);
    
    printf("Nearest Ambulance Assigned: Distance %d km\n", distances[0]);
    
    return 0;
}
