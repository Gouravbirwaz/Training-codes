#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int roll_no;
    char name[50];
    int marks;
} Student;

int compare(const void *a, const void *b) {
    return ((Student *)b)->marks - ((Student *)a)->marks;
}

void display_top_students(Student students[], int n) {
    printf("Top Students:\n");
    for (int i = 0; i < (n < 3 ? n : 3); i++) {
        printf("%s (Marks: %d)\n", students[i].name, students[i].marks);
    }
}

Student* binary_search(Student students[], int n, int roll_no) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (students[mid].roll_no == roll_no)
            return &students[mid];
        else if (students[mid].roll_no < roll_no)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return NULL;
}

void display_students(Student students[], int n) {
    printf("Sorted Students:\n");
    for (int i = 0; i < n; i++) {
        printf("%s (Marks: %d)\n", students[i].name, students[i].marks);
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    
    Student students[n];
    for (int i = 0; i < n; i++) {
        printf("Enter Roll No, Name, and Marks for student %d: ", i + 1);
        scanf("%d %s %d", &students[i].roll_no, students[i].name, &students[i].marks);
    }
    
    qsort(students, n, sizeof(Student), compare);
    
    display_students(students, n);
    display_top_students(students, n);
    
    int roll_no_to_search;
    printf("Enter Roll No to search: ");
    scanf("%d", &roll_no_to_search);
    Student *result = binary_search(students, n, roll_no_to_search);
    if (result)
        printf("Found: %s (Marks: %d)\n", result->name, result->marks);
    else
        printf("Student not found.\n");
    
    return 0;
}
