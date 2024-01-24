#include <stdio.h>
#include <stdbool.h>

int my_strcmp_rec(char *str1, char *str2)
{
    // Base case: str1 == '\0' ==  str2

    if(*str1 == *str2 && *str1 == '\0')
    {
        return 0;

    }else if(*str1 != *str2){
        
        int ascii1 = (int)*str1;
        int ascii2 = (int)*str2;

        if(ascii1 > ascii2)
        {
            return 1;
        }else{
            return -1;
        }

    }else{
        my_strcmp_rec(str1 + 1, str2 + 1);
    }

}

/*
char *s1 = "[...]";
char *s2 = "[...]";

Explain the difference between s1 == s2, *s1 == *s2, and strcmp(s1, s2).

s1==s2 would return the true because you are comparing the content itself (characters)
whereas
*s1 == *s2 would return false because you are comparing pointer values. Given both
s1 and s2 are stored at different places in memory, they would have different pointers.

strcmp(s1, s2) passes in the values which works because we are just comparing the string contents

*/

void main()
{
    char s1[100] = "You are round";
    char s2[100] = "You are round";

    int temp = my_strcmp_rec(s1, s2);
    printf("%d\n", temp);

}