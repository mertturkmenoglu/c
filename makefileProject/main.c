#include <stdio.h>
#include "addition.h"
#include "person.h"

int main(void) {

    Person person1, person2;
    int result;

    printf("\nFirst persons age: ");
    scanf("%d", &person1.age);
    printf("\nSecond persons age: ");
    scanf("%d", &person2.age);

    result = add(person1.age, person2.age);

    printf("\n%d + %d = %d\n", person1.age, person2.age, result);

    return 0;
}