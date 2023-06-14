#include<stdio.h>
#include<string.h>
struct emp
{
    char name[20];
    int id,sal;

}e[20];
int readfile(struct emp* );
void insertion(struct emp*,int );
void writefile(struct emp*,int );
int n;
void main()
{
    char s[30];
    n=readfile(e);
    insertion(e,n);
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





void insertion(struct emp *a,int n)
{
    struct emp temp;
    int i,j,k;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0 && temp.id<a[j].id;j--)
            a[j+1]=a[j];
        a[j+1]=temp;    
    }
}