/**
 * Data Structures and Algorithms
 * Linked List
 */
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

// void insertFront(Node *head, int value);
// int removeFromList(Node *head, int value);
// int insertAfter(Node *head, Node *given, int value);

int main()
{
    // Head is Null, prints 0
    printf("%d\n", listSize(NULL));

    // Init head
    Node *head = (Node*) malloc(sizeof(Node));
    head->next = NULL;
    head->value = 0;

    // 0 - 1
    append(head, 1);
    printList(head);

    //0 - 1 - 2
    append(head, 2);
    printList(head);

    // 0 - 1 - 2 - 3
    append(head, 3);
    printList(head);

    // 2
    printf("%d\n", findInList(head, 2));
    
    // 4
    printf("%d\n", listSize(head));

    // 0 - 1 - 2 - 3
    insertAfter(head, head->next->next->next, 4);
    printList(head);

    free(head);

    return 0;
}