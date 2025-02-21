#include <stdio.h>

struct fiction_t {
    char title[30];
    char author[50];
    float price;
};
typedef struct fiction_t Fiction;

struct nonfiction_t {
    char title[30];
    char subject[50];
    float price;
};
typedef struct nonfiction_t NonFiction;

union Book_type {
    Fiction fiction;
    NonFiction nonFiction;
};
typedef union Book_type bookType;

struct Book_t {
    int type;
    bookType booktype;
};

typedef struct Book_t Book;
Book books[1000];
int bookCount = 0; // Initialize bookCount to 0

void addBook() {
    printf("Enter the number of books: ");
    scanf("%d", &bookCount);
    for (int i = 0; i < bookCount; i++) {
        printf("Enter type of book (1 for Fiction, 2 for NonFiction): ");
        scanf("%d", &books[i].type);

        switch (books[i].type) {
            case 1: {
                printf("Enter Fiction details (title, author, price): ");
                scanf("%s %s %f", books[i].booktype.fiction.title, books[i].booktype.fiction.author,
                      &books[i].booktype.fiction.price);
            } break;

            case 2: {
                printf("Enter NonFiction details (title, subject, price): ");
                scanf("%s %s %f", books[i].booktype.nonFiction.title,
                      books[i].booktype.nonFiction.subject,
                      &books[i].booktype.nonFiction.price);
            } break;

            default:
                printf("Invalid book type.\n");
                i--; // Decrement i to re-enter the book details
                bookCount--; //decrement the book count as well.
                break;
        }
    }
}

void displayBook() {
    if (bookCount == 0) {
        printf("No books to display.\n");
        return;
    }

    printf("\nBook Details:\n");
    for (int i = 0; i < bookCount; i++) {
        if (books[i].type == 1) {
            printf("Fiction:\n");
            printf("Title: %s\n", books[i].booktype.fiction.title);
            printf("Author: %s\n", books[i].booktype.fiction.author);
            printf("Price: %.2f\n", books[i].booktype.fiction.price);
        } else if (books[i].type == 2) {
            printf("NonFiction:\n");
            printf("Title: %s\n", books[i].booktype.nonFiction.title);
            printf("Subject: %s\n", books[i].booktype.nonFiction.subject);
            printf("Price: %.2f\n", books[i].booktype.nonFiction.price);
        }
        printf("\n");
    }
}

int main() {
    addBook();
    displayBook();
    return 0;
}
