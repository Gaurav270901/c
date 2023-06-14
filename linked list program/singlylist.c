#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
  int data;
  struct node *link;
}*head=NULL;
void Create();
void Display();
void Count();
void Insert();
void Delete();
void Search();
void Reverse1();
void Reverse2(struct node*);
int main()
{
  int ch;
  while(1)
  {
    printf("\n 1.Create");
    printf("\n 2.Display");
    printf("\n 3.Count");
    printf("\n 4.Insert");
    printf("\n 5.Delete");
    printf("\n 6.Search");
    printf("\n 7.Reverse1");
    printf("\n 8.Reverse2");
    printf("\n 9.Exit");
    printf("\n Enter your choice:\t");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:Create();
              break;
      case 2:Display();
              break;
      case 3:Count();
              break;
      case 4:Insert();
              break;
      case 5:Delete();
              break;
      case 6:Search();
              break;
      case 7:Reverse1();                                            break;
      case 8:Reverse2(head);
              break;
      case 9:exit(0);
      }
  }
}
void Create()
{
  int num,i,n;
  struct node *temp,*next;
  printf("\n Enter how many nodes you want to create:\t");
scanf("%d",&n);
for(i=0;i<n;i++)
{
  temp=(struct node*)malloc(sizeof(struct node));
  temp->link=NULL;
  printf("\n Enter the value for nodes:\t");
  scanf("%d",&num);
  temp->data=num;
  if(head==NULL)
  head=temp;
  else
  {
    next=head;
    while(next->link!=NULL)
    next=next->link;
    next->link=temp;
  }
}
}
void Display()
{
  struct node *next;
  next=head;
  while(next!=NULL)
  {
    printf("%d\t",next->data);
    next=next->link;
  }
}
void Count()
{
  int cnt=0;
  struct node *next;
  next=head;
  while(next!=NULL)
  {
    cnt++;
    next=next->link;
  }
  printf("\n Total number of nodes are: %d",cnt);
 
}

void Search()
{
  struct node *next;
  next=head;
  int val,flag=0 ,pos=1;
  printf("\n Enter the value to be search:\t");
  scanf("%d",&val);
  while(next!=NULL)
  {
    if(val==next->data)
    {
      flag=1;
      break;
    }
    else
    {
    next=next->link;
    pos++;
    }
  }
  if(flag==1)
  {
    printf("%d found at %d position",val,pos);
  }
  else
  {
  printf("\n %d does not found",val);
  }
}
void Insert()
{
  int num,pos,i;
  struct node *temp,*next;
  temp=(struct node*)malloc(sizeof(struct node));
  printf("\n Enter value of node:\t");
  scanf("%d",&num);
  temp->data=num;
  temp->link=NULL;
  printf("\n Enter the position:\t");
  scanf("%d",&pos);
  if(pos==1)
  {
    temp->link=head;
    head=temp;
  }
  else
  {
    next=head;
    for(i=1;i<pos-1&&next->link!=NULL;i++)
    next=next->link;
    temp->link=next->link;
    next->link=temp;
  }
}
void Delete()
{
  struct node *temp,*next;
  int pos,i;
  printf("\n Enter the position of node to be delete:\t");
  scanf("%d",&pos);
  if(head==NULL)
  {
    printf("\n link list is empty");
    return;
  }
  if(pos==1)
  {
    temp=head;
    head=head->link;
    free(temp);
  }
  else{
    next=head;
    for(i=0;i<pos-1;i++)
    next=next->link;
    temp=next->link;
    next->link=temp->link;
    temp->link=NULL;
    free(temp);
  }
}
void Reverse1()
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
void Reverse2(struct node* p1)
{
  if(p1!=NULL)
  {
    Reverse2(p1->link);
    printf("%d\t",p1->data);
  }
  return;
}