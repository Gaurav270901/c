#include<stdio.h>
#include<stdlib.h>
struct node
{
    int prio,data;
    struct node *link;
}*front=NULL;


void insert();
void delete();
void peek();
void display();

void main()
{
    int ch;
    while(1)
    {
        printf("\n1.insert\n2.delete\n3.peek\n4.display\n5.exit\nenter your choice:\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();break;
            case 2:delete();break;
            case 3:peek();break;
            case 4:display();break;
            case 5:exit(0);
        }

    }
}


void insert()
{
    struct node *temp,*q;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the element :\t");
    scanf("%d",&temp->data);
    printf("enter the priority of element :\t");
    scanf("%d",&temp->prio);
    temp->link=NULL;
    if(front==NULL)
    {
        front=temp;
    }

    else
    {
        q=front;
        if(temp->prio>q->prio)
        {
            temp->link=q;
            front=temp;
            return;
        }
        while(q!=NULL && q->link->prio > temp->prio)
            q=q->link;
        temp->link=q->link;
        q->link=temp;    
    
    }
    
}


void peek()
{
    printf("element at front :\t%d",front->data);
    printf("priority at front is :\t%d",front->prio);
}


void delete()
{
    struct node *temp;
    if(front==NULL)
    {
        printf("\nQueue is empty.....");

    }

    else
    {
        temp=front;
        printf("deleted element is :\t%d",temp->data);
        front=front->link;
        free(temp);
        
    }
    
}



void display()

{
    struct node *q;
    q=front;
    if(front ==NULL)
    {
        printf("queue is empty.....");

    }

    else 
    {
        printf("queue with data and priority:\t");
        while(q!=NULL)
        {
            printf("%d | %d\t->\t",q->data,q->prio);
            q=q->link;
        }
        printf(NULL);
    }
}