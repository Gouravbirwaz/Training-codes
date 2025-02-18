#include <stdio.h>
#include <string.h>

float calculateBill(char wardType, int days);

int main() {
    char patientName[100];
    char wardType;
    int days;
    float totalBill, discount, finalBill;

    // Input patient details
    printf("Enter Patient Name: ");
    fgets(patientName, sizeof(patientName), stdin);
    patientName[strcspn(patientName, "\n")] = 0; // Remove newline character

    printf("Enter Ward Type (G/S/P): ");
    scanf(" %c", &wardType); // Space before %c to consume any newline character

    printf("Enter Number of Days: ");
    scanf("%d", &days);

    // Calculate the total bill
    totalBill = calculateBill(wardType, days);

    // Calculate discount if applicable
    if (days > 7) {
        discount = totalBill * 0.05; // 5% discount
    } else {
        discount = 0;
    }

    // Calculate final bill
    finalBill = totalBill - discount;

    // Output the results
    printf("\nPatient Name: %s\n", patientName);
    printf("Total Bill Before Discount: ₹%.2f\n", totalBill);
    if (discount > 0) {
        printf("Discount Applied: ₹%.2f\n", discount);
    } else {
        printf("Discount Applied: ₹0.00\n");
    }
    printf("Final Bill Amount: ₹%.2f\n", finalBill);

    return 0;
}

float calculateBill(char wardType, int days) {
    float rate;

    // Determine the rate based on ward type
    switch (wardType) {
        case 'G':
        case 'g':
            rate = 1000.0; // General Ward
            break;
        case 'S':
        case 's':
            rate = 2000.0; // Semi-Private
            break;
        case 'P':
        case 'p':
            rate = 5000.0; // Private
            break;
        default:
            printf("Invalid Ward Type! Defaulting to General Ward.\n");
            rate = 1000.0; // Default to General Ward if invalid input
            break;
    }

    // Calculate total bill
    return rate * days;
}
