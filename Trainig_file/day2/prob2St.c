#include <stdio.h>

// Function prototype
long factorial(int n);

int main() {
    int number;
    
    // Input a number from the user
    printf("Enter a number: ");
    scanf("%d", &number);
    
    // Check for negative input
    if (number < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        // Calculate factorial
        long result = factorial(number);
        // Output the result
        printf("Factorial of %d is %ld\n", number, result);
    }

    return 0;
}

// Recursive function to calculate factorial
long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Base case: 0! = 1 and 1! = 1
    } else {
        return n * factorial(n - 1); // Recursive case
    }
}
