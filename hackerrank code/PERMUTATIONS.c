#include<stdio.h>
#include<string.h>
void swap(char *,char *);
void permutatn(char*,int,int);
void main()
{
    char str[20];
    printf("enter the string :\t");
    scanf("%s",&str);
    int n=strlen(str);
    permutatn(str,0,n-1);
} 

void swap(char *p,char *q)
{
    char temp;
   temp=*p;
    *p=*q;
    *q=temp;
}


void permutatn(char *a,int low,int n)
{
  if(low==n)
  {
      printf("%s\n",a);
  }
  else
  {
      for(int j=low;j<=n;j++)
      {
          swap((a+low),(a+j));
          permutatn(a,low+1,n);
          swap((a+low),(a+j));
      }
  }
  
}


