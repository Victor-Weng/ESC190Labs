#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Part A

void segfault(int* pointer)
{
    *pointer = 3;
}

// Part B

// Set directory to code folder, then "valgrind ./Questions1to3" in terminal


// Part C

int openfile()
{
    FILE* ptr;
    char ch;

    // Opening file in reading mode
    ptr = fopen("a.txt","r");

    if(ptr == NULL)
    {
        printf("file can't be opened \n");
        return 0;
    }

    // Part d, error checking
    
    
    

    printf("content of this file are \n");

    // Print what is written in the file char by char

    do {
        ch = fgetc(ptr);
        printf("%c",ch);

        // Checking if character is not EOF.
        // If it is EOF stop reading.
    } while (ch != EOF);

    fclose(ptr);
    return 0;
}

int main()
{

    //int temp = -1;
    //segfault(temp);
    openfile();
    return 0;
}