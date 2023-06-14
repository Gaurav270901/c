#include <stdio.h>
#include <stdlib.h>
void create();
void display();
void insert();
void delete ();
void search();
void reverselist();
struct node
{
    int data;
    struct node *link;
} *head = NULL;
void main()
{
    int x;
    while (1)
    {
        printf("\n1.create\n2.display\n3.insert\n4.delete\n5.search\n6.reverse the linked list\n7.print in reverse order\n8.exit\nEnter your choice :\t");
        scanf("%d", &x);
        switch (x)
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
            reverselist();
            break;
        case 7:
           Reverse2(head);
            break;
        case 8:
            exit(0);
        }
    }
}

void create()
{
    struct node *temp, *next;
    int no;
    printf("how many nodes ypu want to create:\t");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->link = NULL;
        printf("enter the data :\t");
        scanf("%d", &no);
        temp->data = no;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            for (next = head; next->link != NULL; next = next->link);
            next->link = temp;
        }
    }
}

void insert()
{
    struct node *next, *temp;
    int no, pos;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->link = NULL;
    printf("enter the data :\t");
    scanf("%d", &no);
    temp->data=no;
    printf("enter the position:\t");
    scanf("%d", &pos);
    if (pos == 1)
    {
        temp->link = head;
        head = temp;
    }
    else
    {
        next = head;
        for (int i = 1; i < pos - 1 && next->link != NULL; i++)
            next = next->link;
        temp->link = next->link;
        next->link = temp;
    }
}

void display()
{
    struct node *next;
    if (head == NULL)
    {
        printf("list is NULL");
        return;
    }

    for (next = head; next != NULL; next = next->link)
    {
        printf("%d\t", next->data);
    }
}

void search()
{
    struct node *next;
    int no;
    if (head == NULL)
    {
        printf("list is NULL");
        return;
    }
    printf("enter the number to be searched:");
    scanf("%d", &no);
    int i = 1;
    for (next = head; next != NULL; next = next->link)
    {
        if (no == next->data)
        {
            printf("%d fount at %d", no, i);
            return;
        }
        i++;
    }
    printf("data not found");
}

void delete ()
{

    struct node *next, *next1, *temp;
    int pos;
    if (head == NULL)
    {
        printf("list is NULL");
        return;
    }
    printf("enter the position to be deleted:");
    scanf("%d", &pos);
    if (pos == 1)
    {
        temp = head;
        head = head->link;
        free(temp);
        return;
    }

    next = head;
    for (int i = 1; i < pos - 1; i++)
        {
            next = next->link;       
        
            next1 = next->link;
            if(next1->link==NULL)
            {
                next->link=NULL;
                free(next1);
                return;
            }
        }
    next->link = next1->link;
    next1->link=NULL;
    free(next1);
}

void Reverse2(struct node* p1)
{
  if(p1!=NULL)
  {
    Reverse2(p1->link);
    printf("%d\t",p1->data);
  }
  return;
}



void reverselist()
{
  struct node *p1,*p2,*p3;
  if(head->link==NULL)
  return;
  p1=head;
  p2=p1->link;
  p3=p2->link;
  p1->link=NULL;
  p2->link=p1;
  while(p3!=NULL)
  {
    p1=p2;
    p2=p3;
    p3=p2->link;
    p2->link=p1;
  }
  head=p2;
}