#include <stdio.h>
void main()
{
    FILE *fp;//file pointer which is going to traversed in a file
    fp = fopen("file.txt", "r");//retrning the value of first element i n a file
    char ch;
    while (ch != EOF)//traversing the file
    {
        ch = fgetc(fp);
        printf("%c", ch);
    }
    fclose(fp);
}