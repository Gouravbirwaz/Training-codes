#include <stdio.h>

#define MAX_STUDENTS 100

struct Marks {
    int subject1;
    int subject2;
    int subject3;
};

struct Student {
    int id;
    char name[50];
    struct Marks marks;
    int totalMarks;
    float averageMarks;
    char grade;
};

void readStudents(struct Student students[], int n) {
    printf("Enter details (ID, Name, Marks in 3 subjects):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %s %d %d %d", &students[i].id, students[i].name,
              &students[i].marks.subject1, &students[i].marks.subject2,
              &students[i].marks.subject3);
    }
}

void calculateGrades(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        students[i].totalMarks = students[i].marks.subject1 +
                                students[i].marks.subject2 +
                                students[i].marks.subject3;
        students[i].averageMarks = (float)students[i].totalMarks / 3;

        if (students[i].averageMarks >= 90) {
            students[i].grade = 'A';
        } else if (students[i].averageMarks >= 75) {
            students[i].grade = 'B';
        } else if (students[i].averageMarks >= 60) {
            students[i].grade = 'C';
        } else if (students[i].averageMarks >= 50) {
            students[i].grade = 'D';
        } else {
            students[i].grade = 'F';
        }
    }
}

void displayStudents(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s - Total: %d, Average: %.2f, Grade: %c\n",
               students[i].name, students[i].totalMarks,
               students[i].averageMarks, students[i].grade);
    }
}

int main() {
    int n;
    struct Student students[MAX_STUDENTS];

    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_STUDENTS) {
        printf("Invalid number of students.\n");
        return 1;
    }

    readStudents(students, n);
    calculateGrades(students, n);
    displayStudents(students, n);

    return 0;
}
