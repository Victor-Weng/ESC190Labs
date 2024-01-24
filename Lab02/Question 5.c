#include <stdio.h>
#include <ctype.h>

int findlength(char *arr)
{
    int length = 0;
    int i = 0;

    while(arr[i] != '\0')
    {
        i++;
    }

    return i;
}


int my_atoi(char *str, int len)
{
    // converts passed in string to number

    //printf("%d\n",len);

    int temp = 0;
    for (int i = 0; i < len; i++)
    {
        if(isdigit(str[i]))
        {   
            //printf("%c\n",str[i]);

            int temptemp = (str[i]-'0');

            for(int j = 0; j < len-i-1; j++)
            {
                temptemp *= 10;
            }
            
            temp += temptemp;

            //printf("%d\n",temp);
        }else{
            return 0;
        }
    }
    return temp;
   
}

void main()
{
    char arr[] = {'2','2','9','2'};
    printf("%d\n",my_atoi(arr,4));
}