

#include<stdio.h>
int stack[20];
int top;
int max=20;
void init();
void push();
void pop();
void display();
int isfull();
int isempty();
void peek();
void init()
{
  top=-1;
}
void push()
{ int x;
  if(isfull())
{
  printf("\n stack is full");
}
else
{
   printf("\n Enter the data to be push:\t");
    scanf("%d",&x);
 top++;
 stack[top]=x;
}
}
void pop()
{
  int d;
  int a;
  a=isempty();
  if(a==1)
  {
    printf("\n stack is empty");
  }
  else
  {
   d=stack[top];
   top--;
   printf("%d",d);
  }
}
void display()
{
  int i;
  for(i=top;i>=0;i--)
  {
    printf("%d\n",stack[top]);
  }
}
int isfull()
{
  if(top==max-1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
int isempty()
{
  if(top==-1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
void peek()
{
  if(isempty())
  {
  printf("/n stack is empty");
  }
  else
  {
    printf("%d\t",stack[top]);
  }
}