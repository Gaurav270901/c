#include<stdio.h>
#define MAX 10
int arr[MAX];
int size;
void accept();
void search(int);
void main()
{
    int no;
    accept();
    printf("enter the value to be searched:\t");
    scanf("%d",&no);
    search(no);

}


void accept()
{
   int i;
   printf("how many terms:\t");
   scanf("%d",&size);
   for(i=0;i<size;i++)
   {
      printf("Enter the values:\t");
      scanf("%d",&arr[i]);
    
   }

}



void search(int no)
{
    int flag=0,pos;
    for(int i=0;i<size;i++)
    {
        if(arr[i]==no)
        {
           flag=1;
           pos=i;
           break; 
        }
       
    }
     if(flag==1)
        {
            printf("number is present at %d position",pos);
        }
      else 
      {
          printf("number not found");
      }  
}