#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>

// Print Linked List
void printList(Node *head)
{
    Node *tmp = head;
	while (tmp != NULL) { 
        printf("%d\t", tmp->value); 
        tmp = tmp->next; 
    } 
	printf("\n");
}

/**
 * Insert a new node on the front of the list
 * @param list is the head of the list
 * @param value is the new value of node
 */
void insertFront(Node *head, int value)
{
    // Implement
}

void append(Node *head, int value)
{
    // If head is null
    // Value will be inserted into head
    if(head == NULL) {
        head->value = value;
        return;
    }

    // Head is not null
    // Create a new node
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;

    Node *tmp = head;

    // Find the last element
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }

    // Current last element will point to newNode
    tmp->next = newNode;

    // New last element will point to null
    newNode->next = NULL;
}

int findInList(Node *head, int value)
{
    Node *tmp = head;
    int index = 0;
    
    while((tmp->next != NULL) && (tmp->value != value)) {
        tmp = tmp->next;
        index++;
    }

    return (tmp->value == value) ? index : -1;
}

int removeFromList(Node *head, int value)
{
    // Implement
}

int insertAfter(Node *head, Node *given, int value)
{
    if(head == given) {
        Node *newNode = (Node*) malloc(sizeof(Node));
        newNode->value = value;
        newNode->next = head->next;
        head->next = newNode;
        return 1;
    }

    Node *tmp = head;
    while((tmp->next != given) && (tmp->next != NULL)) {
        tmp = tmp->next;
    }

    if(tmp->next == given) {
        tmp = given->next;
        Node *newNode = (Node*) malloc(sizeof(Node));
        newNode->value = value;
        given->next = newNode;
        newNode->next = tmp;
        return 1;
    } else {
        return 0;
    }
}

void freeList(Node *head)
{
    // Implement
}

int listSize(Node *head)
{
    Node *tmp = head;
    if(head == NULL)
        return 0;
    int counter = 0;
    while(tmp->next != NULL) {
        tmp = tmp->next;
        counter++;
    }
    counter++;
    return counter;
}