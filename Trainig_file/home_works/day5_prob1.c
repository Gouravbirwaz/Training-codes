#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HISTORY 100

typedef struct {
    char urls[MAX_HISTORY][100];
    int top;
} Stack;

void push(Stack *stack, const char *url) {
    if (stack->top < MAX_HISTORY - 1) {
        stack->top++;
        strcpy(stack->urls[stack->top], url);
    }
}

void pop(Stack *stack, char *url) {
    if (stack->top >= 0) {
        strcpy(url, stack->urls[stack->top]);
        stack->top--;
    } else {
        url[0] = '\0';
    }
}

typedef struct {
    Stack backStack;
    Stack forwardStack;
    char currentPage[100];
} BrowserHistory;

void visit(BrowserHistory *browser, const char *url) {
    if (strlen(browser->currentPage) > 0) {
        push(&browser->backStack, browser->currentPage);
    }
    strcpy(browser->currentPage, url);
    browser->forwardStack.top = -1;
    printf("Visited: %s\n", url);
}

void goBack(BrowserHistory *browser) {
    if (browser->backStack.top >= 0) {
        push(&browser->forwardStack, browser->currentPage);
        pop(&browser->backStack, browser->currentPage);
        printf("Action: Go Back\nCurrent Page: %s\n", browser->currentPage);
    } else {
        printf("No previous page to go back to.\n");
    }
}

void goForward(BrowserHistory *browser) {
    if (browser->forwardStack.top >= 0) {
        push(&browser->backStack, browser->currentPage);
        pop(&browser->forwardStack, browser->currentPage);
        printf("Action: Go Forward\nCurrent Page: %s\n", browser->currentPage);
    } else {
        printf("No forward page to navigate to.\n");
    }
}

int main() {
    BrowserHistory browser = {{{0}, -1}, {{0}, -1}, ""};
    visit(&browser, "google.com");
    visit(&browser, "github.com");
    visit(&browser, "stackoverflow.com");
    goBack(&browser);
    goForward(&browser);
    return 0;
}
