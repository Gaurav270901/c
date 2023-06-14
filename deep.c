#include <stdio.h>
#include<stdlib.h>

int main(void) {
	// your code goes here
	while(1)
    {
    int n , sum = 0 ;
	scanf("%d",&n);
    if(n == 0 )
        exit(0);
	for(int i = 1 ; i <= n ; i++)
	{
	    sum=sum+i;
	}
	printf("sum : %d\n",sum);
    }
	return 0;
}

