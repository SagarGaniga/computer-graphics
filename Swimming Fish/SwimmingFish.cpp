using namespace std;
#include <iostream>
#include <graphics.h>
#include <cstdio>
#include <cmath>

void fish(int x, int y){

    // Body
    //void ellipse(int x, int y, int stangle, int endangle, int xradius, int yradius);
    ellipse(x, y, 0, 360, 50, 20);

    // eye
    circle(x+25, y-5, 5);

    // back fin
    line(x-50, y, x-70, y-30);
    line(x-50, y, x-70, y+30);
    line(x-70, y-30, x-70, y+30);

    // top fin
    line(x+10,y-18, x-15, y-40);
    line(x-10,y-18, x-15, y-40);

    // bottom fin
    line(x+10,y+18, x-15, y+40);
    line(x-10,y+18, x-15, y+40);

    // stripes
    line(x+15,y-17,x,y+17);
    line(x,y-17,x-15,y+17);
}

int main()
{
    int gd=DETECT,gm,x,y,length,angle;
	initgraph(&gd, &gm, "");

    int x1 = 100;                   //x-position of fish 1
    int y1 = getmaxheight()/2;      //y-position of fish 1

    int x2 = 400;                   //x-position of fish 2
    int y2 = getmaxheight()/2-200;  //y-position of fish 2

    int x3 = 200;                   //x-position of fish 3
    int y3 = getmaxheight()/2-300;  //y-position of fish 3

    // Infinite Loop of swimming
    while(1)
    {
        //fish 1
        fish(x1, y1);               //Draw that awesome fish
        x1+=3;                      // change the x position +3
        y1+=rand()%11-5;            // change the y position with random value

        //fish 2
        fish(x2, y2);
        x2+=2;
        y2+=rand()%11-5;

        //fish 3
        fish(x3,y3);
        x3+=2;
        y3+=rand()%12-5;

        delay(100);
        cleardevice();
    }

    getch();
    return 1;
}
