#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For exit()

typedef struct {
    int rollNumber;
    char studentName[25];
    int maths, physics, chemistry, cs;
    int totalMarks;
    float percentage;
    char Grade;
} student;

student new_student[25], readRecord[25];

void readStudentDetails(student new_student[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter the name of the student: ");
        scanf("%s", new_student[i].studentName);
        printf("Enter the roll number of the student: ");
        scanf("%d", &new_student[i].rollNumber);
        do{
            printf("Enter the marks of maths (0-100): ");
            scanf("%d", &new_student[i].maths);
        }while(new_student[i].maths<0 || new_student[i].maths >100);
        do{
            printf("Enter the marks of physics (0-100): ");
            scanf("%d", &new_student[i].physics);
        }while(new_student[i].physics<0 || new_student[i].physics >100);
        do{
            printf("Enter the marks of chemistry (0-100): ");
            scanf("%d", &new_student[i].chemistry);
        }while(new_student[i].chemistry<0 || new_student[i].chemistry >100);
        do{
            printf("Enter the marks of cs (0-100): ");
            scanf("%d", &new_student[i].cs);
        }while(new_student[i].cs<0 || new_student[i].cs >100);

        new_student[i].totalMarks = new_student[i].maths + new_student[i].physics +
                                    new_student[i].chemistry + new_student[i].cs;
        new_student[i].percentage = (float)new_student[i].totalMarks / 400 * 100;
    }
}

void studentGrading(student new_student[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (new_student[i].percentage >= 90) {
            new_student[i].Grade = 'A';
        } else if (new_student[i].percentage >= 80) {
            new_student[i].Grade = 'B';
        } else if (new_student[i].percentage >= 70) {
            new_student[i].Grade = 'C';
        } else if (new_student[i].percentage >= 60) {
            new_student[i].Grade = 'D';
        } else {
            new_student[i].Grade = 'F';
        }
    }
}

void writeToFile(student new_student[], int n) {
    FILE *inputFile;
    int i;
    inputFile = fopen("student_record.txt", "w");
    if (inputFile == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(inputFile, "STUDENT-NAME\tSTUDENT-ROLL_NUMBER\tMATHS\tPHYSICS\tCHEMISTRY\tCS\tSTUDENT-TOTALMARKS\tSTUDENT-PERCENTAGE\tGRADE\n");
    for ( i = 0; i < n; i++) {
        fprintf(inputFile, "%s\t%d\t%d\t%d\t%d\t%d\t%d\t%.2f\t%c\n", new_student[i].studentName, new_student[i].rollNumber,
                new_student[i].maths, new_student[i].physics, new_student[i].chemistry, new_student[i].cs,
                new_student[i].totalMarks, new_student[i].percentage, new_student[i].Grade);
    }
    fclose(inputFile);
}

student *loadStudentRecord(student readRecord[], int n) {
    FILE *outputFile;
    outputFile = fopen("student_record.txt", "r");
    if (outputFile == NULL) {
        printf("Error opening file: student_record.txt\n");
        return NULL;
    }

    // Skip the header line.
    char dummy[256];
    fgets(dummy, 256, outputFile);
    int i;
    for ( i = 0; i < n; i++) {
        if (fscanf(outputFile, "%s\t%d\t%d\t%d\t%d\t%d\t%d\t%f\t%c", readRecord[i].studentName, &readRecord[i].rollNumber,
                   &readRecord[i].maths, &readRecord[i].physics, &readRecord[i].chemistry, &readRecord[i].cs,
                   &readRecord[i].totalMarks, &readRecord[i].percentage, &readRecord[i].Grade) != 9) {
            printf("Error reading record %d from file.\n", i + 1);
            fclose(outputFile);
            return NULL;
        }
    }
    fclose(outputFile);
    return readRecord;
}

void printLoadRecord(student readRecord[], int n) {
    int i;
    printf("-------------------------------------------------------------------------------------------------------------------\n");
    printf("STUDENT-NAME\tROLL\tMATHS\tPHYSICS\tCHEMISTRY\tCS\tTOTAL\tPERCENTAGE\tGRADE\n");
    printf("-------------------------------------------------------------------------------------------------------------------\n");
    for ( i = 0; i < n; i++) {
        printf("%s\t\t%d\t  %d\t %d\t      %d\t    %d\t    %d\t      %.2f\t      %c\n",
               readRecord[i].studentName, readRecord[i].rollNumber, readRecord[i].maths, readRecord[i].physics,
               readRecord[i].chemistry, readRecord[i].cs, readRecord[i].totalMarks, readRecord[i].percentage, readRecord[i].Grade);
    }
    printf("-------------------------------------------------------------------------------------------------------------------\n");
}






int main() {
    int n,choise;

    while(1){
    printf("Enter the choise 1.write 2.read 3.exit\n");
    scanf("%d",&choise);
    printf("Enter the number of student: ");
    scanf("%d", &n);
    switch(choise){
    case 1:
        readStudentDetails(new_student, n);
        studentGrading(new_student, n);
        writeToFile(new_student, n);
        break;
    case 2:
    if (loadStudentRecord(readRecord, n)) {
        printLoadRecord(readRecord, n);
    }
    break;
    case 3:
       exit(0);
      
    }
 }
    return 0;
}