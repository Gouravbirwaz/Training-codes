#include<stdio.h>
#include<string.h>
enum tollCost{
     car=1,
    truck,
    bike,
};

int getVehicletype(char *vehicle){
     if(strcmp(vehicle,"car")==0){
        return car;
     }
     else if(strcmp(vehicle,"truck")==0){
        return truck;
     }
     else{
        return bike;
     }
}

int main(){
    int tollTax=0;
    int number,i;
    char vehicle[25];
    enum tollCost type;
    printf("enter the numebr vehicle :");
    scanf("%d",&number);;
    for( i=0;i<number;i++){
        printf("Enter the type of vehicle :");
        scanf("%s",vehicle);
        switch(getVehicletype(vehicle)){
            case car:
                 tollTax+=50;
                 break;
            case truck:
                 tollTax+=100;
                 break;
            case bike:
                 tollTax+=20;
                 break;
             default:
                 printf("Invalid vehicle");
        }
    }

    printf("Total Toll tax is : %d",tollTax);
    return 0;
}