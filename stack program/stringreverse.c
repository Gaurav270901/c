#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
int stack[MAX];
int top;
char pop();
void push (char x);
void main()
{
    int top=-1,i,leng;
    char str[20],rev[20];
    printf("enter the string:\t");
    scanf("%s",&str);
    leng=strlen(str);
    for(i=0;i<leng;i++)
    {
        push(str[i]);
    }
    for(i=0;i<leng;i++)
    {
        rev[i]=pop();
    }
    rev[i]='\0';
    printf("reverse string is :\t%s",rev);
}
void push(char x)
{
    top=top+1;
    stack[top]=x;
}
char pop()
{
    char item;
    item=stack[top];
    top=top-1;
    return item;
}







 