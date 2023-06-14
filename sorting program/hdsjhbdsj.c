#include<stdio.h>
#include<string.h>
struct emp
{
    char name[20];
    int id,sal;

}e[20],count[20];
int readfile(struct emp* );
void count_sort();
void writefile(struct emp*,int );
int n;
void main()
{
    char s[30];
    n=readfile(e);
    count_sort();
    writefile(e,n);
    printf("sorted by ID successfully........");

}


int readfile(struct emp *a)
{
    int i=0;
    FILE *fp;
    if((fp=fopen("emp.txt","r"))!=NULL)
    {
        while(!feof(fp))
        {
            fscanf(fp,"%s%d%d",a[i].name,&a[i].id,&a[i].sal);
            printf("name:%s\teid:\t%d\tempsal:%d\n",a[i].name,a[i].id,a[i].sal);
            i++;
        }
    }
    return i;

}



void writefile(struct emp *a,int n)
{
    int i;
    FILE *fp;
    if((fp=fopen("insertionemp.txt","w"))!=NULL)
    {
        for(i=0;i<n;i++)
            fprintf(fp,"\n%s\t%d\t%d",a[i].name,a[i].id,a[i].sal);
    }
}





void count_sort()
{
 count[20].id={0};
 int i,j;
 for(i=0;i<n;i++)
{
     count[e[i].id].id=count[e[i].id].id+1;
}
printf("\nsorted array using count sort is:");
for(i=0;i<=n;i++)
 {
  for(j=1;j<=count[i].id;j++)
    { printf("%d\t",i);
      }
   }
}