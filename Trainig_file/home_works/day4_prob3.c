#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int emp_id;
    char name[50];
    float basic_salary;
    float allowances;
    float gross_salary;
} Employee;

void saveToFile(Employee employees[], int n) {
    FILE *file = fopen("payroll.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d, %s, %.2f, %.2f, %.2f\n", employees[i].emp_id, employees[i].name,
                employees[i].basic_salary, employees[i].allowances, employees[i].gross_salary);
    }
    fclose(file);
    printf("Record saved in \"payroll.txt\"\n");
}

void searchEmployee(Employee employees[], int n) {
    int id;
    printf("Enter Employee ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < n; i++) {
        if (employees[i].emp_id == id) {
            printf("\nEmployee: %s\nGross Salary: ₹%.2f\n", employees[i].name, employees[i].gross_salary);
            return;
        }
    }
    printf("Employee ID not found!\n");
}

int main() {
    Employee employees[MAX];
    int n;

    printf("Enter number of employees: ");
    scanf("%d", &n);
    getchar(); // Consume newline

    for (int i = 0; i < n; i++) {
        printf("Enter details for Employee %d (ID, Name, Basic Salary, Allowances):\n", i + 1);
        scanf("%d", &employees[i].emp_id);
        getchar(); // Consume newline
        fgets(employees[i].name, sizeof(employees[i].name), stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = '\0';
        scanf("%f %f", &employees[i].basic_salary, &employees[i].allowances);
        employees[i].gross_salary = employees[i].basic_salary + employees[i].allowances;
    }

    saveToFile(employees, n);
    searchEmployee(employees, n);
    
    return 0;
}
