#include<stdio.h>
#include<string.h>
struct city 
{
    char cname[20];
    int code;

}c[20];
int readfile(struct city* );
void searchcity(struct city *,char *);
int n;
void main()
{
    char s[30];
    n=readfile(c);
    printf("\nnumber of cities are : %d",n);
    printf("\nenter the city to be searched :\t");
    scanf("%s",&s);
    searchcity(c,s);

}



int readfile(struct city *a)
{
    int i=0;
    FILE *fp;
    if((fp=fopen("city.txt","r"))!=NULL)
    {
        while(!feof(fp))
        {
            fscanf(fp,"%s%d",a[i].cname,&a[i].code);
            i++;
        }
    }
    return i;

};



void searchcity(struct city *a,char *p)
{
    int i,flag=0;
    int no;

    for(i=0;i<n;i++)
    {
        if(strcmp(a[i].cname,p))
        {
            flag=1;
            no=a[i].code;

            break;
        }
    }

    if(flag==1)
        printf("\ncity code is : %d",no);

    else
    {
        printf("city not found\n");
    }
    

}