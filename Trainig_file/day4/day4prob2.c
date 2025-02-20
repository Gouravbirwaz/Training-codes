#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100
#define FILENAME "employees.txt"

struct Employee {
    int id;
    char name[50];
    float salary;
};

void writeToFile(struct Employee emp[], int n) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d %s %.2f\n", emp[i].id, emp[i].name, emp[i].salary);
    }

    fclose(file);
    printf("Employee data written to file.\n");
}

void readFromFile() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }

    printf("Employees Data from File:\n");

    struct Employee emp;
    while (fscanf(file, "%d %s %f", &emp.id, emp.name, &emp.salary) == 3) {
        printf("%d %s %.2f\n", emp.id, emp.name, emp.salary);
    }

    fclose(file);
}

int main() {
    int n;
    struct Employee employees[MAX_EMPLOYEES];

    printf("Enter number of employees: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_EMPLOYEES) {
        printf("Invalid number of employees.\n");
        return 1;
    }

    printf("Enter details (ID, Name, Salary):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %s %f", &employees[i].id, employees[i].name, &employees[i].salary);
    }

    writeToFile(employees, n);
    readFromFile();

    return 0;
}
