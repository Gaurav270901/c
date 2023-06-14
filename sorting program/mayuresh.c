#include<stdio.h>

struct employee

{

char ename[30];

int age,sal;

}emp[100];

 

int n;

main()

{

 

n=ReadFile(emp);

printf("Total record are %d",n);

bubblesort(emp,n);

WriteFile(emp,n);

printf("File sorted...");

}

 

 

int ReadFile(struct employee *arr)

{

int cnt=0;

FILE *fp;

if((fp=fopen("emp.txt","r"))!=NULL)

{

printf("records are:");

while(!foef(fp))

{

fscanf(fp, "%s %d %d",arr[cnt].ename,&arr[cnt].age,&arr[cnt].sal);

printf("\n %s %d %d",arr[cnt].ename,arr[cnt].age,arr[cnt].sal);

cnt++;

}

}

return cnt-1;

}

 

 

void Bubblesort(struct employee *a,int n)

{

int i,j;

struct employee temp;

for(i=0;i<n-1;i++)

{

for(j=0;j<n-1-i;j++)

{

if(a[j].sal > a[j+1].sal)

{

temp=a[j];

a[j]=a[j+1];

a[j+1]=temp;

}

}

}

}

 

 

void WriteFile(struct employee *arr,int n)

{

int i;

FILE *fp;

if((fp=fopen("sortedemp.txt","w"))!=NULL)

{

for(i=0;i<n;i++)

fprintf(fp,"\n %s \t%d \t%d",arr[i].ename,arr[i].age,arr[i].sal);

}

 

}
    