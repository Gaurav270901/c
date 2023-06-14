#include<stdio.h>
#include<stdlib.h>
void main()
{
    FILE *fs,*ft;
    char ch;
    fs = fopen("source.txt","r");
    if(fs == NULL)
    {
        puts("File not exist");
        return ;
    }
    ft= fopen("dest.txt","w");
    if(ft==NULL)
    {
        printf("File not exixt :");
        exit(1);
        return ;
    }
    while(ch != EOF)
    {
        ch = fgetc(fs);

        fputc(ch , ft);
    }
    printf("file copied successfully");
    fclose(fs);
    fclose(ft);
}