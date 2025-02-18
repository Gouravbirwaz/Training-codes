#include <stdio.h>

float calculatePayableAmount(float billAmount) {
    float discount = 0;

    if (billAmount > 1000) {
        discount = 0.20;
    } else if (billAmount >= 500) {
        discount = 0.10;
    }

    return billAmount - (billAmount * discount);
}

int main() {
    float billAmount;
    printf("Enter total bill amount: ");
    scanf("%f", &billAmount);

    float payableAmount = calculatePayableAmount(billAmount);
    printf("Final Payable Amount: %.2f\n", payableAmount);

    return 0;
}
