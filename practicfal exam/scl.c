#include <stdio.h>
#include <stdlib.h>
void create();
void display();
void insert();
void delete ();
//void reverse(struct node*);
void search();
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
        printf("\n1.create\n2.display\n3.insert\n4.delete\n5.search\n6.reverse\n7.exit\nenter ur choice:\t");
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
           // reverse(head);break;

            case 7:exit(0);
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
        printf("list is empty");
        return;
    }
    for (q = head; q->link != head; q = q->link)
    {
        printf("%d\t", q->data);
    }
    printf("%d", q->data);
}

void insert()
{
    struct node *temp, *next, *last;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->link = NULL;
    int pos;
    printf("enter the position to inserted:\t");
    scanf("%d", &pos);
    printf("enter the data:\t");
    scanf("%d", &temp->data);
    if (pos == 1)
    {
        for (last = head; last->link != head; last = last->link)
            ;
        temp->link = last->link;
        last->link = temp;
        head = temp;
        return;
    }

    else
    {
        next = head;
        for (int i = 1; i < pos - 1 && (next->link != head); i++)
        {
            next = next->link;
        }

        temp->link = next->link;
        next->link = temp;
    }
}

void delete ()
{
    if (head == NULL)
    {
        printf("list is empty\n");
        return;
    }
    struct node *next, *temp, *last;
    int pos;

    printf("enter the position to be deleted:\t");
    scanf("%d", &pos);
    if (pos == 1)
    {
        for (last = head; last->link != head; last = last->link)
            ;
        last->link = head->link;
        temp = head;
        head = head->link;
        temp->link = NULL;
        free(temp);
        return;
    }
    next = head;

    for (int i = 1; i < pos - 1; i++)
    {
        next = next->link;
        temp = next->link;
        if (temp->link == head)
        {
            temp->link = NULL;
            next->link = head;
            free(temp);
            return;
        }
    }

    next->link = temp->link;
    free(temp);
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
    for (next = head; next->link != head; next = next->link)
    {
        if (no == next->data)
        {
            printf("%d fount at %d", no, i);
            return;
        }
        i++;
    }

    if(no==next->data)
    {
         printf("%d fount at %d", no, i);
            return;

    }
    printf("data not found");
}


void reverse(struct node *p1)
{
  if(p1->link!=head)
  {
    reverse(p1->link);
    printf("%d\t",p1->data);
  }
  return;
}