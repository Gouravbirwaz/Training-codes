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
    
    for(i=0;i<max_sub;i++){
        printf("Enter the marks in %d Subject :",i+1);
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
    int numberofStudents;
    printf("Enter the number of studnets :");
    scanf("%d",&numberofStudents);
    int i;
    studentPtr newStudent=(studentPtr)malloc(sizeof(struct Student)*numberofStudents);
    for(i=0;i<numberofStudents;i++){
    printf("Enter %d student deatils \n",i+1);
     readStudentInfo(newStudent+i);
    }
    printf("******************** Student marks info ********************\n");
    for(i=0;i<numberofStudents;i++){
    displyStudentInfo(newStudent+i);
    }
    free(newStudent);
}
