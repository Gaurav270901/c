#include<stdio.h>
#define MAX 10
int a[MAX];
int n;

void bubble(int *a,int n)
{
    int i,j,temp;
for(i=0;i<n-1;i++)
{
  for(j=0;j<n-1-i;j++)
  {
    if(a[j]>a[j+1])
    {
    temp=a[j];
    a[j]=a[j+1];
    a[j+1]=temp;
    }
  }
}
}


void accept()
{
   int i;
   printf("how many terms:\t");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
      printf("Enter the values:\t");
      scanf("%d",&a[i]);
    
   }
}
void display()
{
 int i;
 for(i=0;i<n;i++)
 {
   printf("%d\t",a[i]);
 }

}
