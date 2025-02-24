#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int price;
} Product;

int compare(const void *a, const void *b) {
    return ((Product *)a)->price - ((Product *)b)->price;
}

void display_cheapest_and_expensive(Product products[], int n) {
    printf("Cheapest Product: %s (Price: %d)\n", products[0].name, products[0].price);
    printf("Most Expensive Product: %s (Price: %d)\n", products[n-1].name, products[n-1].price);
}

Product* binary_search(Product products[], int n, char* name) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(products[mid].name, name);
        if (cmp == 0)
            return &products[mid];
        else if (cmp < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return NULL;
}

void display_products(Product products[], int n) {
    printf("Sorted Products:\n");
    for (int i = 0; i < n; i++) {
        printf("%s (Price: %d)\n", products[i].name, products[i].price);
    }
}

int main() {
    int n;
    printf("Enter the number of products: ");
    scanf("%d", &n);
    
    Product products[n];
    for (int i = 0; i < n; i++) {
        printf("Enter Name and Price for product %d: ", i + 1);
        scanf("%s %d", products[i].name, &products[i].price);
    }
    
    qsort(products, n, sizeof(Product), compare);
    
    display_products(products, n);
    display_cheapest_and_expensive(products, n);
    
    char name_to_search[50];
    printf("Enter Product Name to search: ");
    scanf("%s", name_to_search);
    Product *result = binary_search(products, n, name_to_search);
    if (result)
        printf("Found: %s (Price: %d)\n", result->name, result->price);
    else
        printf("Product not found.\n");
    
    return 0;
}
