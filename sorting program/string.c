#include<stdio.h>
#include<string.h>
void main()
{
    char name[30],a[20];
    gets(name);
    int flag=0;
    printf("enter the name for comparison");
    gets(a);
    int size=strlen(a);
    for(int i=0;i<size;i++)
    {
        if(a[i]!=name[i])
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("string matches\n");
    else 
        printf("string does not matches");    
}