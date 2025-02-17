#include <stdio.h>

// Function to assign grades based on marks
void assignGrade(int studentID, int marks) {
    char grade;

    if (marks >= 90 && marks <= 100) {
        grade = 'A';
    } else if (marks >= 80) {
        grade = 'B';
    } else if (marks >= 70) {
        grade = 'C';
    } else if (marks >= 60) {
        grade = 'D';
    } else {
        grade = 'F';
    }

    printf("Student %d: Marks = %d, Grade = %c\n", studentID, marks, grade);
}

int main() {
    int N, marks;

    // Get the number of students
    printf("Enter the number of students: ");
    scanf("%d", &N);

    // Process each student's marks
    for (int i = 1; i <= N; i++) {
        printf("Enter total marks for student %d (out of 100): ", i);
        scanf("%d", &marks);

        // Validate input
        if (marks < 0 || marks > 100) {
            printf("Invalid marks! Please enter a value between 0 and 100.\n");
            i--; // Repeat the same student input
            continue;
        }

        assignGrade(i, marks);
    }

    return 0;
}
