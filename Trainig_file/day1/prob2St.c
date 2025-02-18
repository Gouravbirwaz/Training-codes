#include <stdio.h>

// Function to calculate electricity bill with surcharge
void calculateBill(int customerID, int units) {
    float bill = 0, super_charge = 0;

    if (units > 200) {
        bill += (units - 200) * 5;
        units = 200;
    }
    if (units > 100) {
        bill += (units - 100) * 3;
        units = 100;
    }
    bill += units * 2;
    if (bill > 1000) {
        super_charge = bill * 0.10;  
        bill += super_charge;
    }

    printf("Total bill for customer %d: %.2f\n", customerID, bill);
    printf("Super charge added: %.2f\n", super_charge);
}

int main() {
    int N, units;
    
    printf("Enter the number of customers: ");
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        printf("Enter electricity consumption (units) for customer %d: ", i);
        scanf("%d", &units);
        calculateBill(i, units);
    }

    return 0;
}
