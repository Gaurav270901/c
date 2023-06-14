#include <stdio.h>
#include <stdlib.h>
void create();
void display();
void insert();
void count();

struct node
{
    int data;
    struct node *link;
} *head = NULL;

void main()
{
    int ch;
    while (1)
    {
        printf("\n1.create\n2.display\n3.insert\n4.count\n5.exit\nenter your choice:\t");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            count();
            break;
        case 5:
            exit(0);
        }
    }
}

void create()
{
    int data;
    struct node *temp, *next;
    int no;
    printf("enter the number of nodes:\t");
    scanf("%d", &no);
    for (int i = 0; i < no; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->link = NULL;
        printf("enter the data:\t");
        scanf("%d", &temp->data);
        if (head == NULL)
        {
            head = temp;
            temp->link = head;
        }
        next = head;
        while (next->link != head)
        {
            next = next->link;
        }

        temp->link = head;
        next->link = temp;
    }
}

void display()
{
    struct node *q;
    if (head == NULL)
    {
        printf("Empty list");
        return;
    }
    q=head;
    while (q->link != head)
    {
        
        printf("%d\t", q->data);
        q = q->link;
    }
    printf("%d",q->data);
}

void insert()
{
    struct node *temp, *next,*last;
    int pos;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->link = NULL;
    printf("enter the data:\t");
    scanf("%d", &temp->data);
    printf("enter the position:\t");
    scanf("%d", &pos);
    last=head;
    while(last->link!=head)
    {
        last=last->link;
    }
    if(pos==1)
    {
        temp->link=head;
        head=temp;
        last->link=head;
    }

    else
    {
        next=head;
        for(int i=1;i<pos-1 && next->link!=head;i++)
            next=next->link;
        temp->link=next->link;
        next->link=temp;
        last=temp;    

    }

}

void count()
{
    struct node *q,*last;
    int cnt=1;
    if(head==NULL)
    {
        printf("list is empty");
        return;
    }
    last=head;
    while(last->link!=head)
    {
        last=last->link;
    }

    for(q=head;q!=last;q=q->link)
        cnt++;


     printf("number of nodes are %d\n",cnt++);   
}