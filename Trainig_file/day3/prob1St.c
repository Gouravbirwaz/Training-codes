#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 100

typedef struct {
    int id;
    int marks[MAX_SUBJECTS];
    int totalMarks;
} Student;

int compareStudents(const void *a, const void *b) {
    return ((Student *)b)->totalMarks - ((Student *)a)->totalMarks;
}

void calculateTotalMarks(Student students[], int n, int m) {
    for (int i = 0; i < n; i++) {
        students[i].totalMarks = 0;
        for (int j = 0; j < m; j++) {
            students[i].totalMarks += students[i].marks[j];
        }
    }
}

void sortStudents(Student students[], int n) {
    qsort(students, n, sizeof(Student), compareStudents);
}

void displayStudents(Student students[], int n) {
    printf("Output:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d: Total Marks = %d\n", students[i].id, students[i].totalMarks);
    }
}

int main() {
    int n, m;

    printf("Enter number of students: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX_STUDENTS) {
        printf("Invalid number of students.\n");
        return 1;
    }

    printf("Enter number of subjects: ");
    scanf("%d", &m);
    if (m <= 0 || m > MAX_SUBJECTS) {
        printf("Invalid number of subjects.\n");
        return 1;
    }

    Student students[MAX_STUDENTS];

    printf("Enter marks:\n");
    for (int i = 0; i < n; i++) {
        students[i].id = i + 1;
        printf("Student %d: ", i + 1);
        for (int j = 0; j < m; j++) {
            scanf("%d", &students[i].marks[j]);
        }
    }

    calculateTotalMarks(students, n, m);
    sortStudents(students, n);
    displayStudents(students, n);

    return 0;
}
