#include<stdio.h>

void print(int array[],int n,int i){
   if(i==n){
       return ;
   }
   printf("%d\t",array[i]);
   print(array,n,++i);
}


int main(){
    int array[10]={1,2,3,4,5,6};
    print(array,6,0);
    return 0;
}