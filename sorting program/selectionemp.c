#include<stdio.h>
#include<string.h>
struct emp
{
    char name[20];
    int id,sal;

}e[20];
int readfile(struct emp* );
void selection(struct emp*,int );
void writefile(struct emp*,int );
int n;
void main()
{
    char s[30];
    n=readfile(e);
    selection(e,n);
    writefile(e,n);
    printf("sorted by id successfully........");

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
    if((fp=fopen("empsort.txt","w"))!=NULL)
    {
        for(i=0;i<n;i++)
            fprintf(fp,"\n%s\t%d\t%d",a[i].name,a[i].id,a[i].sal);
    }
}





void selection(struct emp *a,int n)
{
    int min,i,j;
    for(i=0;i<=n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(e[j].id<a[min].id)
            {
                min=j;
            }
        }
        if(min!=i)
        {
            struct emp t=a[min];
            a[min]=a[i];
            a[i]=t;


        }
    }
}