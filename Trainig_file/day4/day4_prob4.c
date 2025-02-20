#include <stdio.h>
#include <stdlib.h>

#define FILENAME "students.txt"

struct Marks {
    int subject1;
    int subject2;
    int subject3;
};

struct Student {
    int id;
    char name[50];
    struct Marks marks;
};

void appendStudentRecord() {
    FILE *file = fopen(FILENAME, "a"); // Open in append mode
    if (file == NULL) {
        perror("Error opening file for appending");
        return;
    }

    struct Student student;
    printf("Appending student:\n");
    scanf("%d, %s, %d, %d, %d", &student.id, student.name,
          &student.marks.subject1, &student.marks.subject2,
          &student.marks.subject3);

    fprintf(file, "%d %s %d %d %d\n", student.id, student.name,
            student.marks.subject1, student.marks.subject2,
            student.marks.subject3);

    fclose(file);
    printf("Student record appended.\n");
}

void displayStudentRecords() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }

    printf("Student Records:\n");

    struct Student student;
    while (fscanf(file, "%d %s %d %d %d", &student.id, student.name,
                  &student.marks.subject1, &student.marks.subject2,
                  &student.marks.subject3) == 5) {
        printf("%d %s %d %d %d\n", student.id, student.name,
               student.marks.subject1, student.marks.subject2,
               student.marks.subject3);
    }

    fclose(file);
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Append Student Record\n2. Display Student Records\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); //Clear input buffer.

        switch (choice) {
            case 1:
                appendStudentRecord();
                break;
            case 2:
                displayStudentRecords();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
