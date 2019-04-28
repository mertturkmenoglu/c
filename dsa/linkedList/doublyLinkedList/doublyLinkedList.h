#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

struct Node {
    int value;
    struct Node *prev;
    struct Node *next;
};

void printList(struct Node *head);
void insertFront(struct Node *head, int value);
void append(struct Node *head, int value);
int findInList(struct Node *head, int value);
int removeFromList(struct Node *head, int value);
int insertAfter(struct Node *head, struct Node *given, int value);
int insertBefor(struct Node *head, struct Node *given, int value);
void freeList(struct Node *head);
int listSize(struct Node *head);

#endif