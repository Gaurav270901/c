#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
    FILE *fp;
    char s[80] ; 
    fp = fopen("file.txt","w");
    if(fp == NULL)
    {
        printf("File not exist :");
        return;
    }
    printf("Enter in file :\n");
    while(strlen(gets(s))>0)
    {
        fputs(s,fp);
        fputs("\n",fp);
    }
    fclose(fp);
    printf("########## file :\n");
    fp = fopen("file.txt","r");
    while(fgets(s,79,fp)!=NULL)
        printf("%s",s);
    fclose(fp);    

}