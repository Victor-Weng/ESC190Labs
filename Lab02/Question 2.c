#include <stdio.h>

int findlength(int *arr)
{
    int length = 0;
    int i = 0;

    while(arr[i] != '\0')
    {
        i++;
    }

    return i;
}



void strcat1(int *destination, const int *source)
{
    int dlen = findlength(destination);
    int slen = findlength(source);
    int tlen = dlen + slen;

    for(int i = 0; i < tlen; i++)
    {
        destination[dlen + i] = source[i];
    }


}

void strcat2(int *destination, const int *source)
{
    int dlen = findlength(destination);
    int slen = findlength(source);
    int tlen = dlen + slen;

    for(int i = 0; i < tlen; i++)
    {
        *(destination +  dlen + i) = *(source + i);
    }

}


void main()
{
    char str1[100] = "This is ";
    char str2[100] = "so boring";

    printf("%s\n", str1);

    strcat2(str1,str2); // using index i or pointer arithmetic

    printf("%s\n", str1);

}