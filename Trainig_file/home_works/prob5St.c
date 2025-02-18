#include<stdio.h>
#include<stdlib.h>
#define max_sub 6
struct Student{
    char name[25];
    int marks[max_sub];
    float avarageMarks;
};

typedef struct Student * studentPtr;


//reading the  student info 
void readStudentInfo(studentPtr student){
    int i;
    int sum=0;
    printf("Enter the Student name : ");
    scanf("%s",student->name);
    printf("Enter the Student Marks : ");
    for(i=0;i<max_sub;i++){
        scanf("%d",&student->marks[i]);
        sum+=student->marks[i];
    }
    student->avarageMarks=(float)sum/(float)max_sub;    
}


// Code for displaying the student info 
void displyStudentInfo(studentPtr student){
      printf("Student Name : %s\n",student->name);
      printf("student Avarage Marks : %f\n",student->avarageMarks);
}


// Main functionn for the opertaion 
int main(){
    studentPtr newStudent=(studentPtr)malloc(sizeof(struct Student));
    readStudentInfo(newStudent);
    displyStudentInfo(newStudent);
    free(newStudent);
}
