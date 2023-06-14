#include<stdio.h>
#include<stdlib.h>
#define MAX1 5
#define MAX2 5

int stack1[MAX1];
int stack2[MAX2];
void display(int[] ,int);
void push(int[],int);
void compare(int[] ,int[] ,int ,int);
void main()
{
    int ch,x,y,i;
    int top1,top2;
    top1=-1;
    top2=-1;
    while(1)
    {
        printf("\n1.\tpush in stack1\n2.\tpush in stack2\n3.\tdisplay stack1\n4.\tdisplay stack2\n5.\tcompare stacks\n6.\texit\nenter your choice:\t ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:  if(top1==MAX1)
                     {
                            printf("stack is full");
                            break;
                     }      
                     else
                     {
                            top1++;
                            push(stack1,top1);
                            break;
                     }       
            case 2:if(top2==MAX2)
                    {
                            printf("stack is full");
                            break;
                    }       

                     else
                     {
                            top2++;
                            push(stack2,top2);
                            break;
                     }             
            case 3:display(stack1,top1);
                   break;
            case 4:display(stack2,top2);
                   break;
            case 5:compare(stack1,stack2,top1,top2);
                   break;
            case 6:exit(0);                               

        }
    }
}

void push(int stack[],int top)
{
       int x;
       printf("enter the element to be push:\t");
       scanf("%d",&x);
              stack[top]=x; 
}


void display(int stack[],int topx)
{
       int i;
       if(topx==-1)
       {
              printf("stack is empty");
       }
       else
       {
              for(i=topx;i>=0;i--)
              {
                     printf("%d\t",stack[i]);
              }

       }
       

}


void compare(int stack1[],int stack2[],int top1,int top2)
{
       int flag=0;
       if(top1!=top2)
       {
              printf("stacks are not same");
              return;
       }       
       else
       {
              while(top1!=-1 && top2!=-1)
              {
                     if(stack1[top1]!=stack2[top2])
                     {
                            flag=1;
                            break;
                     } 
                     top1--;
                     top2--;     


              }
       }
       if(flag==1)
              printf("stack are not same");
       else
              printf("stacks are same");
              
              
}
