#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedLists.h"
#include <stdbool.h>

// Problem 1: Write a function that appends a node to a linked list. 
// You must use the definitions below. Make sure that the code works on lists of any size. If you need helper functions,
// you must write them yourself.
// You may need to make assumptions like "the next field of the last node is NULL." state any such assumption as a comment.

/*
typedef struct node{
    int data;
    struct node* next;
} node;

typedef struct LL{
    node *head;
    int size;
} LL;
*/

node* createNode(LL *my_list, int value);
void LL_append(LL *my_list, int new_elem);
void printLinked(LL *my_list);
bool validate_list_length(LL *my_list, int length);

int main(void)
{
    //create head
    LL* my_list = (LL*)malloc(sizeof(LL*));
    my_list->size = 1;

    
    my_list->head = createNode(my_list, 0);
    
    LL_append(my_list,3);
    LL_append(my_list,4);
    LL_append(my_list,5);
    LL_append(my_list,6);
    LL_append(my_list,7);
    LL_append(my_list,8);
    
    printLinked(my_list);
    printf("\nLength of list to be tested: %d, Validation of test: %d\n",my_list->size, validate_list_length(my_list, my_list->size));
    printf("\nLength of list to be tested: %d, Validation of test: %d\n",9, validate_list_length(my_list, 9));
    return 0;
}

node* createNode(LL *my_list, int value)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// append integer new_elem to linked list my_list
void LL_append(LL *my_list, int new_elem)
{
    node* temp = my_list->head;

    for(int i = 1; i < (my_list->size); i++)
    {
        temp = temp->next;
    }
    temp->next = (node*)malloc(sizeof(node*));
    temp->next = createNode(my_list,new_elem);
    my_list->size ++;
}

void printLinked(LL *my_list)
{
    node *temp = my_list->head;

    //printf("%d",my_list->size);
    
    for(int i = 0; i < (my_list->size); i++)
    {
        printf("%d",temp->data);
        temp = temp->next;
    }
}

bool validate_list_length(LL *my_list, int length)
{
    node *temp = my_list->head;
    for(int i = 0; i < length-1; i++) // iterate 8 times (head LL + all the trails)
    {
        if(temp->next == NULL)
        {
            return 0;
        } else {
            temp = temp->next;
        }
    }
    
    if(temp->next == NULL)
    {
        return 1;
    } else {
        return 0;
    }
}

void delete_list(LL *my_list, int index)
{
    if(index >= my_list->size){
        printf("invalid index\n");
        exit(1);
    }

    
}