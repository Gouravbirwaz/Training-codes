#include <stdio.h>
#include <string.h>

int main() {
    int method, bankChoice;
    char cardNumber[17], upiID[50];

    printf("Select Payment Method (1-3): ");
    scanf("%d", &method);

    if (method == 1) {
        printf("Enter your 16-digit card number: ");
        scanf("%s", cardNumber);
        if (strlen(cardNumber) == 16)
            printf("Payment Successful!\n");
        else
            printf("Transaction Failed. Please try again.\n");
    } else if (method == 2) {
        printf("Enter your UPI ID: ");
        scanf("%s", upiID);
        if (strchr(upiID, '@') != NULL)
            printf("Payment Successful!\n");
        else
            printf("Transaction Failed. Please try again.\n");
    } else if (method == 3) {
        printf("Select Bank (1 for SBI, 2 for HDFC): ");
        scanf("%d", &bankChoice);
        if (bankChoice == 1 || bankChoice == 2)
            printf("Payment Successful!\n");
        else
            printf("Transaction Failed. Please try again.\n");
    } else {
        printf("Invalid payment method. Please try again.\n");
    }

    return 0;
}
