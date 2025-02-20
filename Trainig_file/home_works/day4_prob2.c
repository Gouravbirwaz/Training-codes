#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef union {
    float daily_rent;
    float total_rent;
} Rent;

typedef struct {
    int car_id;
    char model[50];
    Rent rent;
    int is_daily; // 1 for daily rent, 0 for total rent
} Car;

void saveToFile(Car cars[], int n) {
    FILE *file = fopen("car_rentals.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d, %s, %.2f/%s\n", cars[i].car_id, cars[i].model, 
                cars[i].is_daily ? cars[i].rent.daily_rent : cars[i].rent.total_rent, 
                cars[i].is_daily ? "day" : "total");
    }
    fclose(file);
    printf("Data saved in \"car_rentals.txt\"\n");
}

void updateRent(Car cars[], int n) {
    int id;
    printf("Enter Car ID to update rent: ");
    scanf("%d", &id);
    for (int i = 0; i < n; i++) {
        if (cars[i].car_id == id) {
            printf("Enter new rent: ");
            scanf("%f", &cars[i].rent.daily_rent);
            printf("Rent updated successfully!\n");
            return;
        }
    }
    printf("Car ID not found!\n");
}

int main() {
    Car cars[MAX];
    int n;

    printf("Enter number of cars: ");
    scanf("%d", &n);
    getchar(); // Consume newline

    for (int i = 0; i < n; i++) {
        printf("Enter details for Car %d (ID, Model, Rent per Day):\n", i + 1);
        scanf("%d", &cars[i].car_id);
        getchar(); // Consume newline
        fgets(cars[i].model, sizeof(cars[i].model), stdin);
        cars[i].model[strcspn(cars[i].model, "\n")] = '\0';
        scanf("%f", &cars[i].rent.daily_rent);
        cars[i].is_daily = 1;
    }

    printf("\nCars Available:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - ₹%.2f/day\n", i + 1, cars[i].model, cars[i].rent.daily_rent);
    }

    saveToFile(cars, n);
    updateRent(cars, n);
    saveToFile(cars, n);
    
    return 0;
}
