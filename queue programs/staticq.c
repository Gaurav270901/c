#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int front ,rear;
void init();
void add();
void delete();
void peek();
int isempty();
int isfull();
void display();
void main()
{
    int ch;
    init();
    while(1)
    {
        printf("\n1.\tadd\n2.\tdelete\n3.\tpeek\n4.\tdisplay\n5.\texit\nenter your choice:\t ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: add();
                break;
            case 2: delete();
                break;
            case 3: peek();
                break;
            case 4:display();
                break;                   
            case 5: exit(0);
        }

    }
}


int isfull()
{
    if(rear==MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}


int isempty()
{
    if(front==-1 || front>rear)
        return 1;
    else
        return 0;
        
}



void init()
{
    front=-1;
    rear=-1;
}


void add()
{
    int x;
    if(isfull())
    {
        printf("Q is full");
        return;
    }
    else
    {
        printf("enter the data:\t");
        scanf("%d",&x);
        if(front==-1)
            front=0;
        rear++;
        queue[rear]=x;    
    }
    
}


void delete()
{
    int x;
    if(isempty())
    {
        printf("Q is empty");
        return;
    }
    else
    {
        x=queue[front];
        front++;
        printf("the number deleted from Q is %d",x);
        return;
    }
    
}


void display()
{
    if(isempty())
    {
        printf("Q is full");
        return;
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d\t",queue[i]);
        }
    }
    
}



void peek()
{
    printf("%d",queue[front]);
}

