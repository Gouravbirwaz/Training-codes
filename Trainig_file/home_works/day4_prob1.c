#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    char name[50];
    char expiry_date[11]; // YYYY-MM-DD
    float price;
} Medicine;

void saveToFile(Medicine meds[], int n) {
    FILE *file = fopen("medicine_inventory.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d, %s, %s, %.2f\n", meds[i].id, meds[i].name, meds[i].expiry_date, meds[i].price);
    }
    fclose(file);
    printf("Records saved in \"medicine_inventory.txt\"\n");
}

int compareExpiry(const void *a, const void *b) {
    return strcmp(((Medicine *)a)->expiry_date, ((Medicine *)b)->expiry_date);
}

int main() {
    Medicine meds[MAX];
    int n;

    printf("Enter number of medicines: ");
    scanf("%d", &n);
    getchar(); // Consume newline

    for (int i = 0; i < n; i++) {
        printf("Enter details for Medicine %d (ID, Name, Expiry Date YYYY-MM-DD, Price):\n", i + 1);
        scanf("%d", &meds[i].id);
        getchar(); // Consume newline
        fgets(meds[i].name, sizeof(meds[i].name), stdin);
        meds[i].name[strcspn(meds[i].name, "\n")] = '\0';
        scanf("%s %f", meds[i].expiry_date, &meds[i].price);
    }

    qsort(meds, n, sizeof(Medicine), compareExpiry);

    printf("\nSorted Medicines (by Expiry Date):\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - %s\n", i + 1, meds[i].name, meds[i].expiry_date);
    }

    saveToFile(meds, n);
    return 0;
}
