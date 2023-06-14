#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
int data;
struct node *rlink,*llink;
}*head=NULL;
int node;
void create();
void display();
void count();
void insert();
void delete();
void search();
void reverse1();
void reverse2(struct node*);
void main()
{
  int ch;
  while(1)
  {
    printf("\n 1.create\n 2.display\n 3.count\n 4.insert\n 5.delete\n 6.search\n 7.reverse1\n 8.reverse2\n 9.exit");
    printf("\n Enter your choice:\t");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:create();
             break;
      case 2:display();
             break;
      case 3:count();
             break;
      case 4:insert();
             break;
      case 5:delete();
             break;
      case 6:search();
             break;
      case 7:reverse1();
             break;
      case 8:reverse2(head);
             break;      
      case 9:exit(0);      
    }
  }
}
void create()
{
  int num,i;
  struct node *temp,*next;
  printf("\n Enter how many node:\t");
  scanf("%d",&node);
  for(i=0;i<node;i++)
  {
    temp=(struct node*)malloc(sizeof(struct node));
    temp->rlink=NULL;
    temp->llink=NULL;
    printf("\n Enter value for node:\t");
    scanf("%d",&num);
    temp->data=num;
    if(head==NULL)
    {
       head=temp;
    }
    else
    {
      next=head;
      while(next->rlink!=NULL)
      next=next->rlink;
      next->rlink=temp;
      temp->llink=next;
    }
  }
}
void display()
{
  struct node *next;
  next=head;
  while(next!=NULL)
  {
    printf("%d\t",next->data);
    next=next->rlink;
  }
}

void search()
{
  int num,flag=0,pos=1;
  struct node *next;
  printf("\n Enter data to be search:");
  scanf("%d",&num);
  next=head;
  while(next!=NULL)
  {
    if(num==next->data)
    {
      flag=1;
      break;
    }
    else
    {
    next=next->rlink;
    pos++;
    }
  }
  if(flag==1)
  {
    printf("\n data found at %d position",pos);
  }
  else
  {
    printf("data not found");
  }
}
void count()
{
  int cnt=0;
  struct node *next;
  next=head;
  while(next!=NULL)
  {
     next=next->rlink;
     cnt++;
  }
  printf("\n Total number of nodes are: %d",cnt);
}
void insert()
{
  struct node *temp,*prev ,*next;
  int num,pos,i;
  temp=(struct node*)malloc(sizeof(struct node));
  printf("\n Enter the data to be insert:\t");
  scanf("%d",&num);
  temp->data=num;
  temp->rlink=NULL;
  printf("\n Enter the position:\t");
  scanf("%d",&pos);
  if(pos==1)
  {
    temp->rlink=head;
    head->llink=temp;
    head=temp;
  }
  else
  {
    next=head;
    for(i=1;i<pos && next!=NULL;i++)
    {
      prev=next;
      next=next->rlink;
    }
    if(next==NULL)
    {
      prev->rlink=temp;
      temp->llink=prev;
      return;
    }
    temp->llink=prev;
    prev->rlink=temp;
    temp->rlink=next;
    next->llink=temp;
  }
}
void delete()
{
  int pos,i;
  struct node *temp,*next,*prev,*next1;
  printf("\n Which position you have to delete:\t");
  scanf("%d",&pos);
  if(pos>node)
  {
    printf("\n position not exist");
  }
  if(pos==1)
  {
    next=head;
    head=head->rlink;
    next->rlink=NULL;
    head->llink=NULL;
    free(next);
  }
  else
  {
    next=head;
    for(i=1;i<pos;i++)
    {
      prev=next;
      next=next->rlink;
      next1=next->rlink;
      if(next1==NULL)
      {
        next->llink=NULL;
        prev->rlink=NULL;
        free(next);
        return;
      }
    }
    prev->rlink=next1;
    next->llink=prev;
    next->llink=NULL;
    next->rlink=NULL;
    free(next);
  }
}
void reverse1()
{
}
void reverse2(struct node* p1)
{
  if(p1!=NULL)
  {
    reverse2(p1->rlink);
    printf("%d\t",p1->data);
  }
  return;
}