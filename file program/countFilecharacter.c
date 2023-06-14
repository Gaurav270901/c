#include <stdio.h>
void main()
{
    FILE *fp;
    char ch;
    int cc = 0, wc = 0, lc = 0;
    fp = fopen("file.txt", "r");
    while (ch != EOF)
    {
        ch = fgetc(fp);
        cc++;
        if (ch == ' ')
            wc++;
        if (ch == '\n')
        {
            lc++;
            wc++;
        }
    }
    fclose(fp);
    printf("Words : %d\nLines : %d\nCharacter : %d", wc, lc, cc);
}