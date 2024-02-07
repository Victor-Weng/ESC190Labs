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

//Question 2

// function atof from stdlib.h converts an input string to a double, make your own

double my_atof(char *str)
{
    int i = 0; // set index
    double sign = 1.0; // set the sign to positive
    double dp = 0.1; // decimal index place
    double result = 0.0; // initialize result sum to be 0

    while(str[i] <= '0' || str[i] >= '9')
    {
        i++;
    }

    if(str[i] == '-')
    {
        sign = -1; // if there is a negative at the start, set the sign to negative
        i++; // increase i
    }

    while(str[i] != '.' && str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0'); // maybe make it double ?
        i++; // CHECK ERROR?
    }

    i++;

    while(str[i] != NULL && str[i] >= '0' && str[i] <= '9')
    {
        result = result + (str[i] - '0')*dp;
        dp*=0.1;
        i++;
    }
    
    return result * sign;
}

double sumFile()
{
    FILE* ptr;
    char line[1000];
    double dsum = 0.0;

    // Opening file in reading mode
    ptr = fopen("test.txt","r");

    if(ptr == NULL)
    {
        printf("file can't be opened \n");
        return 0;
    }

    // Print what is written in the file char by char

    while (fgets(line, sizeof(line), ptr) != NULL) {
        dsum += my_atof(line);
    }

    fclose(ptr);
    return dsum;
}


int main()
{

    //int temp = -1;
    //segfault(temp);
    //openfile();
    double res = sumFile();
    printf("%f\n",res);
    return 0;
}