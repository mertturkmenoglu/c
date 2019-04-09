#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct NODE {
    int value;
    struct NODE *next;
} Node;

void printList(Node *head);
void insertFront(Node *head, int value);
void append(Node *head, int value);
int findInList(Node *head, int value);
int removeFromList(Node *head, int value);
int insertAfter(Node *head, Node *given, int value);
void freeList(Node *head);
int listSize(Node *head);

#endif