#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char song[100];
    struct Node *next;
} Node;

Node* createNode(const char *song) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->song, song);
    newNode->next = newNode; // Circular link
    return newNode;
}

void insertSong(Node **head, const char *song) {
    Node *newNode = createNode(song);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void playNext(Node **current) {
    if (*current) {
        printf("Current Song: %s\n", (*current)->song);
        *current = (*current)->next;
    } else {
        printf("No songs in playlist.\n");
    }
}

int main() {
    Node *playlist = NULL;
    insertSong(&playlist, "Song A");
    insertSong(&playlist, "Song B");
    insertSong(&playlist, "Song C");
    
    Node *current = playlist;
    playNext(&current);
    playNext(&current);
    playNext(&current);
    playNext(&current); // Loops back to first song
    
    return 0;
}
