#include<stdio.h>
#include<string.h>


struct Employe{
    char Empname[25];
    int  Empid;
    int  EmpBasesalary;
    float TotalSalary;
    int TotalworkingDay;
};


int pos(int val){
   if(val<0){
    return 0-val;
   }
   else{
    return val;
   }
}

void CategarizeEmp(struct Employe employ ){
    char Catogary[25];
    if(employ.TotalworkingDay>30){
        printf("You cant exceed the working Day \n");
        return;
    }
    else if(employ.TotalworkingDay>25){
       strcpy(Catogary,"Exelent");
       employ.TotalSalary=employ.EmpBasesalary+0.05*employ.EmpBasesalary;

    }
    else if(employ.TotalworkingDay>=15 && employ.TotalworkingDay<25){
        strcpy(Catogary,"Good");
        employ.TotalSalary=employ.EmpBasesalary;
    }
    else if(employ.TotalworkingDay>=10 && employ.TotalworkingDay<15) {
        strcpy(Catogary,"Needs Improvement"); 
        employ.TotalSalary=employ.EmpBasesalary;
    }
    else{
        strcpy(Catogary,"Needs Improvement---");
        employ.TotalSalary=0.5*employ.EmpBasesalary;
    }
    
  printf("*********************** Employee Status ***********************\n");
  printf("Employ Name : %s\n",employ.Empname);
  printf("Employ Final Salary : %.2f\n",employ.TotalSalary);
  printf("Employ Attandace Bonus : %.2f\n",employ.TotalSalary-employ.EmpBasesalary);
  printf("Employ Performace Catogory : %s\n",Catogary);
}





int main(){
    struct Employe emp;
    emp.EmpBasesalary=50000;
    printf("Enter the name of the Employee : \n");
    scanf("%s",emp.Empname);
    printf("Enter the id of the Employee : \n");
    scanf("%d",&emp.Empid);
    printf("Enter the Total working day of the Employee : \n");
    scanf("%d",&emp.TotalworkingDay);
    CategarizeEmp(emp);
    return 0;
}
