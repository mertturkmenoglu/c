/**
 * Basic OOP concept implementation
 * To compile(debug): gcc -Wall -Wextra -O3 -g -o main main.c
 * Valgrind: valgrind ./main
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BookClass {
    int pageNumber;
    char author[100];
    struct BookClass* (*Book)(int, char*);
    void (*deBook)(void);
    void (*setPageNumber)(int);
    void (*setAuthor)(char[100]);
    int (*getPageNumber)(void);
    char* (*getAuthor)(void);
    void (*printBookInfo)(void);
};

typedef struct BookClass BookObject;
struct BookClass *instance;

char* getAuthor() {
    return instance->author;
}

int getPageNumber() {
    return instance->pageNumber;
}

void setPageNumber(int pageNumber) {
    instance->pageNumber = pageNumber;
}

void setAuthor(char *author) {
    strcpy(instance->author, author);
}

void printBookInfo() {
    printf("Page Number: %d\nAuthor: %s\n", instance->pageNumber, instance->author);
}

void deBook() {
    free(instance);
}

struct BookClass *Book(int pageNumber, char* author) {
    instance = (struct BookClass*) malloc(sizeof(struct BookClass));
    instance->pageNumber = pageNumber;
    strcpy(instance->author, author);
    instance->Book = &Book;
    instance->getAuthor = &getAuthor;
    instance->getPageNumber = &getPageNumber;
    instance->setAuthor = &setAuthor;
    instance->setPageNumber = &setPageNumber;
    instance->printBookInfo = &printBookInfo;
    instance->deBook = &deBook;
    return instance;
}



int main() {
    BookObject* var = Book(102, "Yasar Kemal");
    var->printBookInfo();
    var->deBook();
    return 0;
}

