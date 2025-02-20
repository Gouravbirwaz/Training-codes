#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// defining the structuer

struct Employe
{
    int Id;
    char Name[25];
    char Department[25];
    int Salary;
};

typedef struct Employe *emp;

emp newEmployees[10];

// reading the employee deatails
void readEmployee(emp newEmployees,int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter the name of the employee %d : ", i );
        scanf("%s", (newEmployees+i)->Name);
        printf("Enter the Id of the employee %d : ", i + 1);
        scanf("%d", &(newEmployees+i)->Id);
        printf("Enter the Department of the employee %d : ", i + 1);
        scanf("%s", (newEmployees+i)->Department);
        printf("Enter the Salary of the employee %d : ", i + 1);
        scanf("%d", &(newEmployees+i)->Salary);
    }
}

// hgih slary calculations
emp highestSalary(emp newEmployees, int n)
{
    emp highestSalary=newEmployees;
    int i;
    for (i = 0; i < n; i++)
    {
        if ((newEmployees+i)->Salary> (highestSalary)->Salary)
        {
            highestSalary = newEmployees+i;
        }
    }

    return highestSalary;
}

// printing the employee details

void printhighEmployee(emp newEmployees)
{
    printf("************** highest Employee deatails ***************\n");
    printf("Name : %s\n", newEmployees->Name);
    printf("Id : %d\n", newEmployees->Id);
    printf("Department : %s\n", newEmployees->Department);
    printf("Salary : %d\n", newEmployees->Salary);
    printf("************** end of Employee deatails ***************\n");
}

// definining the main functions

int main()
{
    int n;
    emp newEmployees = (emp)malloc(sizeof(struct Employe)*10);
    printf("Enter the Number of employees :");
    scanf("%d", &n);
    readEmployee(newEmployees,n);
    emp highEmploye;
    highEmploye=highestSalary(newEmployees,n);
    printhighEmployee(highEmploye); 
    free(newEmployees);
    return 0;
}