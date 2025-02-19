#include<stdio.h>

void printForward(int array[],int n,int i){
   if(i==n){
       return ;
   }
   printf("%d\t",array[i]);
   printForward(array,n,++i);
}

void printBackword(int array[],int n,int i){
    if(i==n-1){
        return ;
    }
    printBackword(array,n,++i);
    printf("%d\t",array[i]);
 }

int main(){
    int array[10]={1,2,3,4,5,6};
    printForward(array,6,0);
    printf("\n");
    printBackword(array,6,-1);
    return 0;
}