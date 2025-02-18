#include <stdio.h>

void swap(int *a, int *b);

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    swap(&num1, &num2);

    printf("After Swapping:\n");
    printf("First Number: %d\n", num1);
    printf("Second Number: %d\n", num2);

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
