#include <stdio.h>

int main() {
    int status;
    printf("Enter order status (1-4): ");
    scanf("%d", &status);

    if (status == 1)
        printf("Your order has been placed.\n");
    else if (status == 2)
        printf("Your food is being prepared.\n");
    else if (status == 3)
        printf("Your food is out for delivery.\n");
    else if (status == 4)
        printf("Your order has been delivered. Enjoy your meal!\n");
    else
        printf("Invalid status. Please enter a number between 1 and 4.\n");

    return 0;
}
