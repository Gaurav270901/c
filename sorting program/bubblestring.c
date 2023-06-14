#include<stdio.h>
#include<string.h>
char name[10][10];
int no;
void accept();
void display();
void bubblestring();
void main()
{
    accept();
    printf("array of string before sorting :\n");
    display();
    bubblestring();
    printf("\narray of string after sorting :\n");
    display();
}


void accept()
{
    printf("enter number of string to be accepted :\t");
    scanf("%d",&no);
    for(int i=0;i<no;i++)
    {
        printf("string number %d :\t",i+1);
        scanf("%s",&name[i]);
    }
    
}


void display()
{
    for(int i=0;i<no;i++)
    {
        printf("%s\t",name[i]);
    }
}



void bubblestring()
{
    char temp[10];
    
    int i,j;
    for(i=0;i<no-1;i++)
    {
        for(j=0;j<no-1-i;j++)
        {
            if(strcmp(name[j],name[j+1])>0)
            {
                strcpy(temp,name[j]);
                strcpy(name[j],name[j+1]);
                strcpy(name[j+1],temp);
            }
        }
    }

}