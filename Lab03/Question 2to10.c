#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "q2.h"

void studentPrint(student1 p)
{
    printf("%s\n", p.name);
    printf("%s\n", p.student_number);
    printf("%d\n", p.year);
}

void studentPrint2(student2 p)
{
    printf("%s\n", p.name);
    printf("%s\n", p.student_number);
    printf("%d\n", p.year);
}

void set_default_name(student1* p_s)
{
    strcpy(p_s->name, "Default Student");
    strcpy(p_s[0].name, "A Student");
    strcpy((*p_s).name, "Soy Student");

    (*p_s).year = 10;
    p_s->year = 10;
    p_s[0].year = 10;
}

void create_block1(student1 **p_p_s, int n_students)
{
    *p_p_s = (student1 *)malloc(n_students*sizeof(student1));
    
}

void set_default_name_wrong(student1 s)
{
    // does not work since it makes a copy to and changes local variable
}

void set_name(student1 * p_s, char name[])
{
    char temp[10000];
    
    for(int i = 0; i < 200; i ++)
    {
        temp[i] = name[i];
    }

    strcpy(p_s->name, temp);

}

void destroy_block1(student1 *p_s)
{
    free(p_s);
}




void create_block2(student2 **p_p_s, int num_students)
{

    *p_p_s = (student2*)malloc(num_students*sizeof(student2));
    for(int i = 0; i < num_students; i++)
    {
        (*p_p_s)[i].name = NULL;
        (*p_p_s)[i].student_number = NULL;
        (*p_p_s)[i].year = 0;
    }
    
    
}

void set_name2(student2* p_s, char input[])
{   
    int len = strlen(input);

    p_s->name = (char *)malloc((len + 1)*sizeof(char));
    strcpy(p_s->name, input);

}

void destroy_block2(student2* p_p_c, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(p_p_c[i].name);
        free(p_p_c[i].student_number);
        free(p_p_c[i].year);
    }
}

int main()
{
    student1 joe = {.name = "joe", .student_number = "123", .year = 12 };
    char defnam[] = "youuuuuuuuuuuuuuuu";
    set_default_name(&joe);
    studentPrint(joe);
    int n = 10;
    create_block1(&joe, n);
    set_name(&joe, defnam);
    studentPrint(joe);

    student1* ok;
    create_block1(&ok, n);
    destroy_block1(ok);
    studentPrint(joe);

    student2* notok;

    create_block2(&notok,n);
    set_name2(&(notok[2]), "okkkkkkkk");
    studentPrint2(notok[1]);
    destroy_block2(&notok[1], n);
    studentPrint2(notok[1]);

    return 0;
}