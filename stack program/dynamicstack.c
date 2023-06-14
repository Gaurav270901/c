#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*top;
void push();
void pop();
void init();
void peek();
void display();
int isempty();
void main()
{
    int ch;
    init();
    while(1)
    {
        printf("\n1.push\n2.pop\n3.peek\n4.display\n5.exit\nenter your choice:\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();
                    break;
            case 2:pop();
                    break;
            case 3:peek();
                    break;
            case 4:display();
                    break;
            case 5:exit(0);                                
        }
    }
}

void push()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->link=NULL;
    printf("enter the data to be push:\t");
    int no;
    scanf("%d",&no);
    temp->data=no;
    if(top==NULL)
        top=temp;
    else
    {  
        temp->link=top;
        top=temp;
    }
    
}


void pop()
{
    struct node *temp;
    if(isempty())
    {
        printf("stack is empty\n");
    }
    else
    {
    temp=top;
    top=top->link;
    printf("data to be pop is :\t%d",temp->data);
    temp->link=NULL;
    free(temp);
    }
}

void display()
{   
    struct node *temp;
    if(isempty())
    {
        printf("stack is empty");

    }
    else
    {
    
        for(temp=top;temp!=NULL;temp=temp->link)
            printf("%d\t",temp->data);
    }    
}


int isempty()
{
    if (top ==NULL)
        return 1;
    else 
        return 0;    
}

void init()
{
    top=NULL;
}

void peek()
{
    if(isempty())
    {
        printf("stack is empty\n");
    }
    else
         printf("\n%d\n",top->data);
}