#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "intlist.h"

// Allocate memory for an object of type IntList, initialize
// its data to equal the data in data_arr, and set its size
// Store the address of the new object in *p_IntList
void create_list_from_data(IntList **p_IntList, int *data_arr, int size)
{
    *p_IntList = (IntList*)malloc(sizeof(IntList));

    (*p_IntList)->data = (int *)malloc(sizeof(int)*size);

    memcpy((*p_IntList)->data,data_arr,sizeof(int)*size);

    (*p_IntList)-> size = size;
    (*p_IntList)->capacity = size;
}

void print_List(int *list, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d",*(list+i));
    }
    printf("\n");
}

void increase_capacity(IntList* list, int size, int capacity)
{
    if((list->size)>=(list->capacity))
    {
        list->data = (int*)realloc(list->data,(list->capacity)*(sizeof(int))*2);
        list->capacity = (list->capacity)*2;
    
    }
}

// Append new_elem to the end of list
void list_append(IntList *list, int new_elem)
{
    // Check if capacity is ok

    increase_capacity(list,list->size,list->capacity);

    // if ok:

    list->data[(list->size)] = new_elem;
    list->size += 1;

}


// Insert new_elem at index in list. new_elem should now be at
// location index.
// Use the function memmove to move elements of list->data as needed
// If the capacity needs to grow, use realloc to increase the capacity by
// a factor of 2
void list_insert(IntList *list, int new_elem, int index)
{

    increase_capacity(list,list->size,list->capacity);

    memmove(&(list->data[index+1]), &(list->data[index]), (sizeof(int)*((list->size)-index)));
    list->data[index] = new_elem;

    list->size += 1;


}

// Delete the element at index index

void list_delete(IntList *list, int index)
{
    memmove(&(list->data[index]),&(list->data[index+1]), (sizeof(int)*((list->size)-index)));

    list->size -= 1;
}

// call free as appropriate to free the memory used by list
// Note: the order in which you free list->data and list
// itself is important (how?)
void list_destroy(IntList *list);

// Return the element at index index in list
int list_get(IntList *list, int index);
