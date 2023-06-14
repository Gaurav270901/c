#include <stdio.h>
#include <stdlib.h>
void create();
void insert();
void delete ();
void search();
void display();
struct node
{
    int data;
    struct node *rlink, *llink;
} *head = NULL;

void main()
{
    int ch;
    while (1)
    {
        printf("\n1.Create\n2.Display\n3.Insert\n4.Delete\n5.Search\n6.Print in reverse order\n7.exit\nEnter your choice:\t");
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
             delete ();
            break;
        case 5:
            search();
            break;
        case 6:
            reverse(head);
            break;
        case 7:
            exit(0);
        }
    }
}

void create()
{
    struct node *temp, *next;

    printf("How many nodes you want to create:\t");
    int no,num;
    scanf("%d", &no);
    for (int i = 0; i < no; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->rlink = NULL;
        temp->llink = NULL;
        printf("\n Enter value for node:\t");
        scanf("%d", &num);
        temp->data = num;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            next = head;
            while (next->rlink != NULL)
                next = next->rlink;
            next->rlink = temp;
            temp->llink = next;
        }
    }
}

void display()
{
    struct node *next;
    next = head;
    while (next != NULL)
    {
        printf("%d\t", next->data);
        next = next->rlink;
    }
}

void insert()
{
    int no;
    struct node *next, *temp,*prev;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->rlink = NULL;
    temp->llink = NULL;
    printf("enter the data to be inserted:\t");
    scanf("%d", &temp->data);
    printf("enter the position:\t");
    int pos;
    scanf("%d", &pos);
    if (pos == 1)
    {
        temp->rlink = head;
        head->llink = temp;
        head = temp;
        return;
    }
    else
    {   
        next=head;
        for (int i = 1; i < pos && next != NULL; i++)
        {   
            prev=next;
            next=next->rlink;
        }
        if(next==NULL)
        {
            temp->llink=prev;
            prev->rlink=temp;
            return;
        }
        temp->rlink=next;
        temp->llink=prev;
        prev->rlink=temp;
        next->llink=temp;
    }
}


void delete()
{
    struct node *temp,*next,*prev;
    int pos;
    printf("enter the position to be deleted :\t");
    scanf("%d",&pos);
    if(pos==1)
    {
        temp=head;
        head=head->rlink;
        head->llink=NULL;
        temp->rlink=NULL;
        free(temp);
    }
    else
    {
        next=head;
        for(int i=1;i<pos;i++)
        {
            prev=next;
            next=next->rlink;
            temp=next->rlink;
        }
        if(temp==NULL)
        {
            next->llink=NULL;
            free(next);
            return;
        }
        next->llink=NULL;
        next->rlink=NULL;
        prev->rlink=temp;
        temp->llink=prev;
        free(next);
    }
}

void search()
{
    if(head==NULL)
    {
        printf("linked list is empty");
        return;
    }
    struct node *next;
    int no;
    printf("enter the number to be searched:\t");
    scanf("%d",&no);
    int i=0;
    for(next=head;next!=NULL;next=next->rlink)
    {
        if(no==next->data)
        {
            printf("%d found at %d",no,i+1);
            return;
        }i++;
        
    }
    printf("data not found");
}


void reverse(struct node *q)
{
    if(q != NULL)
    {
        reverse(q->rlink);
        printf("%d\t",q->data);
    }
    return;
}