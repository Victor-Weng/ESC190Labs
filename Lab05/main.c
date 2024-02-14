#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "Questions.c"


int main()
{
    // First create an int list:
    int dataList[] = {9,2,9,4,9};
    int size = 5;
    IntList *testArr;

    // Test create
    printf("Test for Create : \n");
    create_list_from_data(&testArr, dataList, size);
    print_List(testArr->data, testArr->size);
    printf("size: %d\n", testArr->size);
    printf("capacity: %d\n", testArr->capacity);

    // Test append
    printf("Test for Append : \n");
    list_append(testArr, 2);
    print_List(testArr->data, testArr->size);
    printf("size: %d\n", testArr->size);
    printf("capacity: %d\n", testArr->capacity);

    // Test insert
    printf("Test for Insert : \n");
    list_insert(testArr, 3, 3);
    print_List(testArr->data, testArr->size);
    printf("size: %d\n", testArr->size);
    printf("capacity: %d\n", testArr->capacity);

    // Test delete
    printf("Test for Delete : \n");
    list_delete(testArr, 3);
    print_List(testArr->data, testArr->size);
    printf("size: %d\n", testArr->size);
    printf("capacity: %d\n", testArr->capacity);
    
    return 0;
}