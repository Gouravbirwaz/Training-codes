#include <stdio.h>
#include <string.h>

#define MAX_PASSENGERS 100  // Maximum passengers limit

// Structure to store passenger details
typedef struct {
    char name[50];
    int age;
    char destination[50];
} Passenger;

void addPassengers(Passenger list[], int n);
void sortPassengers(Passenger list[], int n);
void searchPassengers(Passenger list[], int n, char searchDest[]);

int main() {
    int n;
    printf("Enter number of passengers: ");
    scanf("%d", &n);
    
    Passenger passengerList[MAX_PASSENGERS];

    // Take passenger input
    addPassengers(passengerList, n);

    // Sort passengers by destination
    sortPassengers(passengerList, n);

    // Display sorted passenger list
    printf("\nSorted List (by destination):\n");
    for (int i = 0; i < n; i++) {
        printf("%s - %s\n", passengerList[i].name, passengerList[i].destination);
    }

    // Search passengers by destination
    char searchDest[50];
    printf("\nEnter destination to search: ");
    scanf("%s", searchDest);
    searchPassengers(passengerList, n, searchDest);

    return 0;
}

// Function to add passengers
void addPassengers(Passenger list[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nPassenger %d:\n", i + 1);
        printf("Enter Name: ");
        scanf("%s", list[i].name);
        printf("Enter Age: ");
        scanf("%d", &list[i].age);
        printf("Enter Destination: ");
        scanf("%s", list[i].destination);
    }
}

// Function to sort passengers by destination (Bubble Sort)
void sortPassengers(Passenger list[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(list[j].destination, list[j + 1].destination) > 0) {
                Passenger temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

// Function to search passengers by destination
void searchPassengers(Passenger list[], int n, char searchDest[]) {
    int found = 0;
    printf("Passengers traveling to %s: ", searchDest);
    for (int i = 0; i < n; i++) {
        if (strcmp(list[i].destination, searchDest) == 0) {
            printf("%s ", list[i].name);
            found = 1;
        }
    }
    if (!found) {
        printf("No passengers found.");
    }
    printf("\n");
}
