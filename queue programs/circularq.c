#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;

}*rear;
void init();
int isempty();
void insert();
void delete();
void peek();
void delete();
void display();
void main()
{
    int ch;
    init();
    while(1)
    {
        printf("\n1.\tinsert\n2.\tdelete\n3.\tpeek\n4.\tdisplay\n5.\texit\nenter your choice:\t ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert();
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



void init()
{
    rear=NULL;
}

int isempty()
{
    if(rear==NULL)
        return 1;
    else 
        return 0;    
}




void insert()
{
    int x;
    struct node *temp;
    printf("enter the data:\t");
    scanf("%d",&x);
    temp=(struct node*)malloc(sizeof(struct node));
    temp->link=NULL;
    temp->data=x;
    if(isempty())
    { 
          rear=temp;
          temp->link=rear;
    }      
    else
    {
        temp->link=rear->link;
        rear->link=temp;
        rear=temp;
    }
}

void delete()
{
    int x;
    struct node *temp;
    if(isempty())
    {
        printf("Q is empty");
        return;
    }
    else
    {
        temp=rear->link;
        if(temp==rear)
            rear=NULL;
        else
        {
            
        rear->link=temp->link;    
        
        }
        x=temp->data;
        printf("deleted element is %d",x);
        free(temp);
    }
    
}


void display()
{
    struct node *temp;
    if(isempty())
    {
        printf("Q is empty");
        return;
    }
    temp=rear->link;
    while(temp!=rear)
    {
        printf("%d\t",temp->data);
        temp=temp->link;
    }
    printf("%d",rear->data);
}


void peek()
{
    if(isempty())
    {
        printf("Q is empty");
        return;
    }
    else
    {
        printf("peeked element is %d",rear->link->data);
    }
    
}