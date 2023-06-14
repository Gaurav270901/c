#include<stdio.h>
#include<string.h>
void main()
{
    char name[10][10];
    int i;
    printf("enter how many names:");
    int no;
    scanf("%d",&no);
    printf("enter the name:");
    for(i=0;i<no;i++)
    {
        scanf("%s",name[i]);

    }

    printf("names are :");
    for(i=0;i<no;i++)
    {
        printf("%s\n",name[i]);

    }
    
int d=strcmp(name[1],name[2]);
printf("%d",d);
if(d==0)
    printf("names are same");
else 
    printf("not same");    


}