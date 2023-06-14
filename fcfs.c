#include<stdio.h>
#include<stdlib.h>

struct process
{
    int pno , at , fbt, nbt , tbt , ft , tat , wt , flag ; 
}p[100];

struct gantt
{
    int pno , et ;
}gc[100];

int np , gccnt = 0 , stime = 0 ;

int fcfs();
void accept();
void display();
void displaygc();

void main()
{
    accept();
}

void accept()
{
    printf("Enter the number of processes :\t");
    scanf("%d",&np);
    for(int i = 0 ; i < np ; i++)
    {
        printf("Enter the process number :");
        scanf("%d",&p[i].pno);
        printf("Enter the arrival time :");
        scanf("%d",&p[i].at);
        printf("Enter the first burst time :");
        scanf("%d",&p[i].fbt);
        p[i].nbt = rand()%10+1;
        
    }
}