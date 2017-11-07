#include<graphics.h>;
#include<conio.h>;
#include<math.h>
#define PI 3.14

void koch(int x1, int y1, int x2, int y2, int it)
{
    //find angle
    float angle = 60*PI/180;

    //find p3 near p1
    int x3 = (2*x1+x2)/3;
    int y3 = (2*y1+y2)/3;

    //find p4 near p2
    int x4 = (x1+2*x2)/3;
    int y4 = (y1+2*y2)/3;

    //find joining pt
    int dx=x4-x3;
    int dy=y4-y3;

    int x = x3 + dx*cos(angle)+dy*sin(angle);
    int y = y3 - dx*sin(angle)+dy*cos(angle);

    if(it > 0)
    {
        //recursion with it-1
        koch(x1, y1, x3, y3, it-1); //13
        koch(x3, y3, x, y, it-1);   //30
        koch(x, y, x4, y4, it-1);   //04
        koch(x4, y4, x2, y2, it-1); //42
    }
    else
    {
        line(x1, y1, x3, y3);
        line(x3, y3, x, y);
        line(x, y, x4, y4);
        line(x4, y4, x2, y2);
    }
}
int main()
{
    initwindow(700,700);

    int x1 = 100, y1 = 200, x2 = 400, y2 = 200, x3 = 250, y3 = 450, it;

    cleardevice();

    setcolor(WHITE);

    it = 2;

    koch(x1, y1, x2, y2, it);   //12
    koch(x2, y2, x3, y3, it);   //23
    koch(x3, y3, x1, y1, it);   //31

    getch();
    return 0;
}
