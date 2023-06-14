#include<stdio.h>

int main()
{
    int height,i,j;
    do
    {
        printf("height:\t");
        scanf("%d",&height);
        
    }
    while(height<=0);
    for(int row=1;row<=height;row++)
    {
        for(j=1;j<=height-row;j++)
            {
                printf(" ");
                
            }
        for(int i=1;i<=row;i++)
            printf("#");
            printf(" ");
            printf(" ");
            for(int k=1;k<=row;k++)
                printf("#");
            printf("\n");
            
    }
}