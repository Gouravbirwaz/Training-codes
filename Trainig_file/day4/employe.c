#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// defining the structure
struct Employe {
    int Id;
    char Name[25];
    char Department[25];
    int Salary;
};

typedef struct Employe *emp;

// reading the employee details
void readEmployee(emp newEmployees, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter the name of the employee %d : ", i + 1);
        scanf("%s", (newEmployees + i)->Name);
        printf("Enter the Id of the employee %d : ", i + 1);
        scanf("%d", &(newEmployees + i)->Id);
        printf("Enter the Department of the employee %d : ", i + 1);
        scanf("%s", (newEmployees + i)->Department);
        printf("Enter the Salary of the employee %d : ", i + 1);
        scanf("%d", &(newEmployees + i)->Salary);
    }
}

// highest salary calculations
emp highestSalary(emp newEmployees, int n) {
    emp highestSalary = newEmployees;
    int i;
    for (i = 1; i < n; i++) { // Start from 1 to avoid comparing first element with itself.
        if ((newEmployees + i)->Salary > highestSalary->Salary) {
            highestSalary = newEmployees + i;
        }
    }
    return highestSalary;
}

// printing the employee details
void printHighEmployee(emp employee) {
    printf("************** highest Employee details ***************\n");
    printf("Name : %s\n", employee->Name);
    printf("Id : %d\n", employee->Id);
    printf("Department : %s\n", employee->Department);
    printf("Salary : %d\n", employee->Salary);
    printf("************** end of Employee details ***************\n");
}

// writing to file
void writeToFile(emp newEmployees, int n) {
    FILE *inputFile;
    int i;
    inputFile = fopen("record.txt", "w");
    if (inputFile == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(inputFile, "EMPLOYEE-NAME\tEMPLOYEE-ID\tDEPARTMENT\tSALARY\n");
    for (i = 0; i < n; i++) {
        fprintf(inputFile, "%s\t\t%d\t\t%s\t\t%d\n", (newEmployees + i)->Name, (newEmployees + i)->Id, (newEmployees + i)->Department, (newEmployees + i)->Salary);
    }
    fclose(inputFile);
}

// loading the files from the text file
emp loadEmployeeRecord(emp readRecord, int n, char *recordTable) {
    FILE *outputFile;
    int i;
    outputFile = fopen(recordTable, "r");
    if (outputFile == NULL) {
        printf("Error opening file: %s\n", recordTable);
        return NULL;
    }

    //Skip the header line.
    char dummy[100];
    fgets(dummy,100,outputFile);

    for (i = 1; i < n; i++) {
        if (fscanf(outputFile, "%s%d%s%d", (readRecord + i)->Name, &(readRecord + i)->Id, (readRecord + i)->Department, &(readRecord + i)->Salary) != 4) {
            printf("Error reading record %d from file.\n", i + 1);
            fclose(outputFile);
            return NULL;
        }
    }
    fclose(outputFile);
    return readRecord;
}

void printLoadRecord(emp readRecord, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("EmployeeName : %s\tEmployeeId :%d\tEmployeeDepartment :%s\tEmployeeSalary :%d\n", (readRecord + i)->Name, (readRecord + i)->Id, (readRecord + i)->Department, (readRecord + i)->Salary);
    }
}

int main() {
    int n = 0;
    char recordTable[25];
    emp employees = NULL;
    int choice;

    while (1) {
        printf("Enter the mode 1.read 2.write 4.exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 2:
                printf("Enter the Number of employees: ");
                scanf("%d", &n);
                employees = (emp)malloc(sizeof(struct Employe) * n);
                if (employees == NULL) {
                    printf("Memory allocation failed!\n");
                    return 1;
                }
                readEmployee(employees, n);
                emp highEmployee = highestSalary(employees, n);
                printHighEmployee(highEmployee);
                writeToFile(employees, n);
                free(employees);
                employees = NULL;
                break;
            case 1:
                printf("Enter the length :");
                scanf("%d", &n);
                emp readRecords = (emp)malloc(sizeof(struct Employe) * n);
                if (readRecords == NULL) {
                    printf("Memory allocation failed!\n");
                    return 1;
                }
                printf("Enter the record table name: ");
                scanf("%s", recordTable);
                printf("***************** The employee records are ***************\n");
                if(loadEmployeeRecord(readRecords, n, recordTable) != NULL){
                    printLoadRecord(readRecords, n);
                }
                free(readRecords);
                break;
            case 4:
                if (employees != NULL) {
                    free(employees);
                }
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}