#include <stdio.h>

void toten(int* n)
{
    /* 
    Changes the value at pointer *n to 10
    */

    *n = 10;
}

void changearr(char *arr, int length)
{
    //*arr = malloc(length * sizeof(int));
    for (int i = 0; i < length ; i++)
    {
        arr[i] = 'a';
    }
}

void printarr(char **arr, int length)
{
    for (int i = 0; i < length ; i++)
    {
        printf("%c",(*arr)[i]);
    }
}

void seq_replace(int *arr1, unsigned long arr1_sz, int *arr2, unsigned long arr2_sz) // unsigned means only positive numbers
{
    bool complete = false;
    for (int i = 0; i < arr1_sz ; i++)
    {
        if(arr1[i] == arr2[i])
        {
            for (int j = 1; j < arr2_sz ; j ++)
            {
                if(arr1[i+j] != arr2[j])
                    {   
                        complete = false;
                        break;
                    }
            }

            if(complete == true)
            {
                for (int j = 1; j < arr2_sz ; j ++)
                {
                    arr1[i] = 0;    
                }
            }
        }
    }
}

void main(){
    
    // Question 2
    int a = 5;
    printf("%d\n", a);
    toten(&a);
    printf("%d\n", a);

    // Question 3
    char arr[5] = {'1','2','3','4','5'};

    printf("%s\n", arr);
    changearr(&arr, 5);

    printf("%s\n", arr);
}

