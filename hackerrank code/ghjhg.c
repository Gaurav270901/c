#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
int main()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
    //1st rectangle
    rectangle(100, 200, 200, 300);
    //2nd rectangle
    rectangle(150, 250, 250, 350);
    // 1st line
    line(100, 200, 150, 250);
    // 2nd line
    line(200, 300, 250, 350);
    // 3rd line
    line(100, 300, 150, 350);
    // 4th line
    line(200, 200, 250, 250);
    getch();
    return 0;
    closegraph();
