#include<stdio.h>
#include<string.h>
struct city 
{
    char cname[20];
    int code;

}c[20];
int readfile(struct city* );
void searchcity(struct city  *,int,int);
int size;
void main()
{
    char s[30];
    size=readfile(c);
    printf("\nnumber of cities are : %d",size);
    searchcity(c,0,size);

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



void searchcity(struct city *a,int low,int high)
{
    int i,flag=0;
    int no,mid;
    char s[20];
    printf("\nenter the city to be searched :\t");
    scanf("%s",&s);
    while (low <= high){
        mid = (high + low)/2;
        if (strcmp(a[mid].cname,s)==0){
            flag==1;
            printf("city code is %d",a[mid].code);
            return;
        }
        else if (strcmp(a[mid].cname,s)>0){
            high = mid -1 ;
        }
        else if (strcmp(a[mid].cname,s)<0){
            low = mid + 1;
        }
    }

    printf("city not found");

}