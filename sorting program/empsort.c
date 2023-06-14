#include<stdio.h>
#include<string.h>
struct emp
{
    char name[20];
    int id,sal;

}e[20];
int readfile(struct emp* );
void sortempid(struct emp*,int );
void sortempname(struct emp*,int );
void writefile(struct emp*,int );
int n;
void main()
{
    char s[30];
    n=readfile(e);
    int no;
    printf("1.sort by name\n2.sort by ID\n");
    do{
        printf("enter your choice :\t");
        scanf("%d",&no);
    }
    while(no!=1 && no!=2);
    if(no==1)
    {
        sortempname(e,n);
        printf("sorted by name succesfully");
    }

    else 
    {
        sortempid(e,n);
        printf("sorted by ID succesfully");
    }

    writefile(e,n);



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



void sortempid(struct emp *s,int no)
{
     int i,j;
     struct emp temp;
    for(i=0;i<no-1;i++)
    {
        for(j=0;j<no-1-i;j++)
        {
            if(s[j].id>s[j+1].id)
            {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
}



void sortempname(struct emp *e,int no)
{
    
    struct emp temp;
    int i,j;
    for(i=0;i<no-1;i++)
    {
        for(j=0;j<no-1-i;j++)
        {
            if(strcmp(e[j].name,e[j+1].name)>0)
            {
                temp=e[j];
                e[j]=e[j+1];
                e[j+1]=temp;
            }
        }
    }

}