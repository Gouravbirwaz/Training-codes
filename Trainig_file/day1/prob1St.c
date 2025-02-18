#include <stdio.h>

// Function to classify salary
void classifySalary(int employeeID, float salary) {
    if (salary < 30000) {
        printf("Employee %d: Low income (₹%.2f)\n", employeeID, salary);
    } else if (salary <= 70000) {
        printf("Employee %d: Middle income (₹%.2f)\n", employeeID, salary);
    } else {
        printf("Employee %d: High income (₹%.2f)\n", employeeID, salary);
    }
}

int main() {
    int N;
    float salary;

    // Get the number of employees
    printf("Enter the number of employees: ");
    scanf("%d", &N);

    // Process each employee's salary
    for (int i = 1; i <= N; i++) {
        printf("Enter salary for employee %d: ", i);
        scanf("%f", &salary);
        classifySalary(i, salary);
    }

    return 0;
}
