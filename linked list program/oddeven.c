#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *link;
}*head1=NULL;
struct node *oddhead=NULL,*evenhead=NULL;
struct node *create(struct node*,int);
void display(struct node*);
int  count(struct node*);
void main()
{
    int no;
    printf("how many nodes you want to create:\t");
    scanf("%d",&no);
    for(int i=0;i<no;i++)
    {
        printf("enter the number:\t");
        int n;
        scanf("%d",&n);
        head1=create(head1,n);
    }

    printf("\nlist is :\t");
    display(head1);
    struct node *q;
    for(q=head1;q!=NULL;q=q->link)
    {
        if(q->data%2==0)
        {
            evenhead=create(evenhead,q->data);
        }
        else 
            oddhead=create(oddhead,q->data);
    }

    printf("\nodd list is :\t");
    display(oddhead);
    printf("\neven list is:\t");
    display(evenhead);
    int total=count(head1);
    int odd=count(oddhead);
    int even=count(evenhead);
    printf("\ntotal elements in the list:\t%d\ntotal number of odd elements:\t%d\t\ntotal number of even elements:\t%d\t",total,odd,even);
}

struct node *create(struct node *head,int n)
{
    struct node *q,*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->link=NULL;
    temp->data=n;
    if (head==NULL)
    {
        head=temp;
    }
    else
    {
        q=head;
        while(q->link!=NULL)
        {
            q=q->link;
        }
        q->link=temp;
    }
    return head;
}


void display(struct node *head)
{
    struct node *q;
    q=head;
    while(q!=NULL)
    {
        printf("%d\t",q->data);
        q=q->link;
    }
}


int count(struct node *head)
{
     struct node *q;
     int cnt=0;
    q=head;
    while(q!=NULL)
    {
        cnt++;
        q=q->link;
    }
    return cnt;
}