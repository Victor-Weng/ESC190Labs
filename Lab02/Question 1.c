#include <stdio.h>

void question1(int *arr, int length){
    for(int i = 0; i < length; i ++)
    {
        if(i%2 == 0)
        {
            arr[i] = 0;
        }
        
    }
}

void main(){
    int arr[] = {5, 6, 7, 8};

    for(int i = 0; i < 4; i++)
    {
        printf("%d",arr[i]);
        
    }
    printf("\n");

    question1(&arr, 4);
    
    for(int i = 0; i < 4; i++)
    {
        printf("%d",arr[i]);
        
    }
    printf("\n");
}