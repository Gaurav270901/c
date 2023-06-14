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

}



void searchcity(struct city *a,char *s) 
{
     char last[20];
     strcpy(a[n-1].cname,last);  
     strcpy(a[n-1].cname,s); 
     // Here num is the search element. 
     int i = 0; 
     while(strcmp(a[i].cname,s)!=0) 
     { 
         i++; 
     } 
        strcpy(a[n-1].cname,s); 
          if( (i < n-1) || strcmp(a[i].cname,last)==0 ) 
          { 
              printf( "city code is %d ",a[i].code); 
        } 
              else 
              {
                 printf(" city not found");
               } 


}