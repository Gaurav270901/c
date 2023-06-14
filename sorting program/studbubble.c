#include<stdio.h>
struct student
{
    char name[20];
    int rno;
    float avg;
}s[10],temp;
void accept_details();
void display_details();
void bubble_student();
int no;
void main()
{
   accept_details();
   bubble_student();  
   printf("\nafter sorting the name of students are:");
   for(int i=0;i<no;i++)
    {
        printf("%s\t",s[i].name);
    }
     display_details();  
}


void accept_details()
{
    do
    {
        printf("enter the number of students:\t");
        scanf("%d",&no);
    }
    while(no<=0);    
    for(int i=0;i<no;i++)
    {
        printf("\nenter the name of student:\t");
        scanf("%s",&s[i].name);
        printf("enter the roll no of student:\t");
        scanf("%d",&s[i].rno);
        printf("enter the average of student:\t");
        scanf("%f",&s[i].avg);
        printf("\n\n");

    }
}



void display_details()
{
    printf("students details are:\n");
    for(int i=0;i<no;i++)
    {
        printf("name:\t%s\nroll no:\t%d\naverage:\t%.1f\n\n",s[i].name,s[i].rno,s[i].avg);
    }

}




void bubble_student()
{
    int i,j;
    for(i=0;i<no-1;i++)
    {
        for(j=0;j<no-1-i;j++)
        {
            if(s[j].avg<s[j+1].avg)
            {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }

}
