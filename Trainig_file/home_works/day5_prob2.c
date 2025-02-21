#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCK 100

typedef struct {
    char items[MAX_STOCK][100];
    int top;
} Stack;

void push(Stack *stack, const char *item) {
    if (stack->top < MAX_STOCK - 1) {
        stack->top++;
        strcpy(stack->items[stack->top], item);
        printf("Stock Added: %s\n", item);
    } else {
        printf("Stock is full, cannot add more items.\n");
    }
}

void pop(Stack *stack, char *item) {
    if (stack->top >= 0) {
        strcpy(item, stack->items[stack->top]);
        stack->top--;
        printf("Dispatching Item: %s\n", item);
    } else {
        item[0] = '\0';
        printf("No stock available to dispatch.\n");
    }
}

void displayStock(Stack *stack) {
    if (stack->top >= 0) {
        printf("Remaining Stock: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%s", stack->items[i]);
            if (i < stack->top) printf(", ");
        }
        printf("\n");
    } else {
        printf("No stock available.\n");
    }
}

int main() {
    Stack warehouse = {{0}, -1};
    char item[100];
    
    push(&warehouse, "Item A");
    push(&warehouse, "Item B");
    push(&warehouse, "Item C");
    
    pop(&warehouse, item);
    displayStock(&warehouse);
    
    return 0;
}
