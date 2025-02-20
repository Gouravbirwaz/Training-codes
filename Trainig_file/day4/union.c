#include<stdio.h>


struct fiction_t{
    char title[30];
    char author[50];
    float price;
};
typedef struct fiction_t  Fiction;


struct nonfiction_t{
    char title[30];
    char subject[50];
    float price;
};
typedef struct nonfiction_t  NonFiction;


union Book_type{
    Fiction fiction;
    NonFiction nonFiction;
};
typedef union Book_type bookType;


struct Book_t{
    int type;
    bookType booktype;
};
typedef struct Book_t Book;
Book books[1000];
int bookCount;

void addBook(){
    printf("enter the books number:");
    scanf("%d",&bookCount);
    for (int i=0;i<bookCount;i++){
        printf("enter type of book: Fiction/NonFiction:");
        scanf("%d",&books[i].type);

       switch(books[i].type){
            case 1:{
                    printf("enter Fiction details:(title,author,price)");
                    scanf("%s%s%f",books[i].booktype.fiction.title,books[i].booktype.fiction.author,
                    &books[i].booktype.fiction.price);
            }break;

            case 2:{
                printf("enter NonFiction details:(title,subject,price)");
                scanf("%s%s%f",books[i].booktype.nonFiction.title,
                    books[i].booktype.nonFiction.subject,
                    &books[i].booktype.nonFiction.price);
            }break;
        }

    }
}

void displayBook(){

}

int main(){
    addBook();
    displayBook();
    return 0;
}